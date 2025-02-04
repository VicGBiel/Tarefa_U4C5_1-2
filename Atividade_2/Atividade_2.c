#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

#define G_LED 11
#define B_LED 12
#define R_LED 13
#define BTN_A 5

bool is_on = false;
uint8_t led_state = 0; // Controla qual LED será desligado

// Inicializa os GPIOs
void init_gpio() {
    gpio_init(R_LED);
    gpio_set_dir(R_LED, GPIO_OUT);
    gpio_put(R_LED, 0);

    gpio_init(B_LED);
    gpio_set_dir(B_LED, GPIO_OUT);
    gpio_put(B_LED, 0);

    gpio_init(G_LED);
    gpio_set_dir(G_LED, GPIO_OUT);
    gpio_put(G_LED, 0);

    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);
}

// Callback para desligar os LEDs de forma sequencial
int64_t turn_off_callback(alarm_id_t id, void *user_data) {
    uint32_t timestamp = to_ms_since_boot(get_absolute_time());

    switch (led_state) {
        case 0:
            gpio_put(G_LED, 0);
            printf("Verde apagado - tempo absoluto: %d ms\n", timestamp);
            led_state++;
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            break;
        case 1:
            gpio_put(B_LED, 0);
            printf("Azul apagado - tempo absoluto: %d ms\n", timestamp);
            led_state++;
            add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            break;
        case 2:
            gpio_put(R_LED, 0);
            printf("Vermelho apagado - tempo absoluto: %d ms\n", timestamp);
            is_on = false;
            led_state = 0; // Reseta o estado para a próxima ativação
            break;
    }

    return 0;
}

int main() {
    stdio_init_all();
    init_gpio();

    while (true) {
        if (gpio_get(BTN_A) == 0 && !is_on) {
            sleep_ms(50); // Debounce

            if (gpio_get(BTN_A) == 0) { // Confirma se o botão ainda está pressionado
                while (gpio_get(BTN_A) == 0) sleep_ms(10); // Aguarda o botão ser liberado

                is_on = true;
                led_state = 0; // Garante que a sequência de desligamento inicie corretamente
                
                // Liga os LEDs
                gpio_put(G_LED, 1);
                gpio_put(B_LED, 1);
                gpio_put(R_LED, 1);

                printf("LEDs ligados\n");

                // Agenda o primeiro desligamento
                add_alarm_in_ms(3000, turn_off_callback, NULL, false);
            }
        }

        sleep_ms(10); // Pequeno atraso para reduzir uso da CPU
    }
}

