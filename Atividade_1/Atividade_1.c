#include <stdio.h>  //inclui a biblioteca padrão de entrada e saída do C
#include "pico/stdlib.h"    //inclui a biblioteca padrão do Raspberry Pi Pico   
#include "hardware/timer.h"    // Inclui a biblioteca para controle e uso de temporizadores de hardware

#define r_led 11
#define y_led 12
#define g_led 13

bool repeating_timer_callback (struct repeating_timer *t){
    bool r_on = gpio_get(r_led);
    bool y_on = gpio_get(y_led);
    bool g_on = gpio_get(g_led);

    printf("PASSARAM-SE 3 SEGUNDOS\n");

    if (r_on == 1){
        r_on = !r_on;
        gpio_put(r_led, r_on);
        y_on = !y_on;
        gpio_put(y_led, y_on);

    } else if (y_on == 1){
        y_on = !y_on;
        gpio_put(y_led, y_on);
        g_on = !g_on;
        gpio_put(g_led, g_on);
    } else if (g_on == 1){
        g_on = !g_on;
        gpio_put(g_led, g_on);
        r_on = !r_on;
        gpio_put(r_led, r_on);
    }
}

//Função que inicializa os GPIOs, e acende o led vermelho 
void init_gpio (){
    gpio_init(r_led);
    gpio_set_dir(r_led, 1);
    gpio_put(r_led, 1);

    gpio_init(g_led);
    gpio_set_dir(g_led, 1);
    gpio_put(g_led, 0);

    gpio_init(y_led);
    gpio_set_dir(y_led, 1); 
    gpio_put(y_led, 0);   
}

int main()
{
    stdio_init_all();
    init_gpio();

    struct repeating_timer timer;

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer);

    while (true) {
        sleep_ms(1000);
        printf("ROTINA DE REPETICAO\n");
    }
}