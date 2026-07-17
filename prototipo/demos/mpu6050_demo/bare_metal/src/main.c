/*
PASSO A PASSO DE COMO USAR O I2C NO STM32F411
Manual de referência do STM32F411, página 476:
The following is the required sequence in controller mode.
• Program the peripheral input clock in I2C_CR2 register in order to generate correct
timings
• Configure the clock control registers
• Configure the rise time register
• Program the I2C_CR1 register to enable the peripheral
• Set the START bit in the I2C_CR1 register to generate a Start condition
The peripheral input clock frequency must be at least:
• 2 MHz in Sm mode
• 4 MHz in Fm mode
*/

#define 

int main(void) {
    // Habilitar clock para o I2C
    // 
}