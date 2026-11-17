#include <stdint.h>

// RCC (clock control)
#define RCC_AHB1ENR   (*(volatile uint32_t *)0x40023830)

// GPIO port (example: GPIOD)
#define GPIOD_MODER   (*(volatile uint32_t *)0x40020C00)
#define GPIOD_ODR     (*(volatile uint32_t *)0x40020C14)

void delay(volatile uint32_t count)
{
    while(count--)
    {
        __asm__("nop");
    }
}

int main()
{
    // 1. Enable clock for GPIOD (bit 3)
    RCC_AHB1ENR |= (1 << 3);

    // 2. Set pin 12 as output
    // Each pin uses 2 bits in MODER
    GPIOD_MODER &= ~(3 << (12 * 2)); // clear
    GPIOD_MODER |=  (1 << (12 * 2)); // output mode

    while(1)
    {
        // LED ON (set bit 12)
        GPIOD_ODR |= (1 << 12);

        delay(500000);

        // LED OFF (clear bit 12)
        GPIOD_ODR &= ~(1 << 12);

        delay(500000);
    }
}