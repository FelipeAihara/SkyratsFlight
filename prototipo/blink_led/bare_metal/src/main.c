#define RCC_AHB1ENR (*((volatile unsigned int *) 0x40023830))
#define GPIOC_MODER (*((volatile unsigned int *) 0x40020800))
#define GPIOC_BSRR (*((volatile unsigned int *) 0x40020818))

extern void delayMs(int n);

int main(void) {
    // Habilita o clock para a porta C
    RCC_AHB1ENR |= (1UL << 2);

    // Configura o pino C13 como output
    GPIOC_MODER &= ~(1UL << 27);
    GPIOC_MODER |= (1UL << 26);

    while(1) {
        // Liga o LED
        GPIOC_BSRR = (1UL << 29);
        // Delay de 1 segundo
        delayMs(1000);

        // Desliga o LED
        GPIOC_BSRR = (1UL << 13);

        // Delay de 1 segundo
        delayMs(1000);
    }
}
