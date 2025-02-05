# Tarefa de clock e temporizadores

Para essa tarefa, foram requisitadas duas atividades distintas, uma para simular um semáforo, e a outra, para acionar leds a partir de um botão. Abaixo, serão divididos as explicações de cada uma, sob o subtítulo de "Atividade 1" e "Atividade 2".

# - Atividade 1

## **Hardware Necessário**

- Raspberry Pi Pico
- 3 LEDs (vermelho, amarelo e verde)
- 3 resistores (330Ω recomendados)

## **Esquema de Ligação**

| Componente   | GPIO do Pico |
| ------------ | ------------ |
| LED Vermelho | GP11         |
| LED Amarelo  | GP12         |
| LED Verde    | GP13         |

## **Descrição do Funcionamento**

1. O LED vermelho acende primeiro.
2. A cada 3 segundos, ocorre a troca de estado dos LEDs na seguinte sequência:
   - Vermelho ➔ Amarelo
   - Amarelo ➔ Verde
   - Verde ➔ Vermelho
3. O ciclo se repete continuamente.

## **Compilação e Execução**

1. Instale o **SDK do Raspberry Pi Pico** e configure o ambiente de desenvolvimento.
2. Faça a clonagem desse repositório, onde estarão as pastas "Atividade 1" e "Atividade 2".
3. Importe a pasta "Atividade 1" através do **Pico SDK**.
4. Compile o código e mova o arquivo *.uf2* para o a **BitDogLab** (a mesma deve estar no modo *bootsel*).

## **Estrutura do Código**

- **Inicialização dos GPIOs**: Configura os pinos dos LEDs como saída e acende o LED vermelho inicialmente.
- **Temporizador de Repetição**: A cada 3 segundos, alterna os LEDs.
- **Loop Principal**: Mantém o sistema rodando indefinidamente.

## **Observações**

- O código é um exemplo básico para demonstrar o uso de GPIOs e temporizadores no Raspberry Pi Pico.
- Na simulação do Wokwi integrado ao VS code, a cores vão ser idênticas ao esperado, porém, ao simular na BitDogLab, devido às especificações da atividade (3 leds diferentes) e a configuração da placa, uma das cores irão divergir (amarelo na simulação, azul na BitDogLab).

# - Atividade 2

## **Hardware Necessário**

- Raspberry Pi Pico
- 3 LEDs (verde, azul e vermelho)
- 3 resistores (330Ω recomendados)
- 1 botão

## **Esquema de Ligação**

| Componente   | GPIO do Pico |
| ------------ | ------------ |
| LED Verde    | GP11         |
| LED Azul     | GP12         |
| LED Vermelho | GP13         |
| Botão        | GP5          |

O botão deve ser conectado ao **GP5**, com um resistor pull-up ativado no código.

## **Descrição do Funcionamento**

1. O código inicializa os pinos dos LEDs como saída e o do botão como entrada com pull-up.
2. Quando o botão é pressionado, os três LEDs são ligados simultaneamente.
3. Após 3 segundos, o LED verde se apaga.
4. Após mais 3 segundos, o LED azul se apaga.
5. Após mais 3 segundos, o LED vermelho se apaga e o sistema volta ao estado inicial.

## **Compilação e Execução**

1. Repita os passos 1. e 2. da atividade 1 (desconsidere se já feito).
2. Importe a pasta "Atividade 2" através do **Pico SDK**.
3. Repita o passo 4. da atividade 1.

---
Criado por Victor Gabriel Guimarães Lopes 
