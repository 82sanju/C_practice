#include "stm32f4xx.h"

int main(void)
{
    /* 1. Enable GPIOA clock */
    RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

    /* 2. Configure PA5 as output */
    GPIOA->MODER &= ~(3U << (5 * 2));
    GPIOA->MODER |=  (1U << (5 * 2));

    /* 3. Push-pull */
    GPIOA->OTYPER &= ~(1U << 5);

    /* 4. No pull-up/pull-down */
    GPIOA->PUPDR &= ~(3U << (5 * 2));

    while (1)
    {
        /* LED ON */
        GPIOA->BSRR = (1U << 5);

        for (volatile int i = 0; i < 1000000; i++);

        /* LED OFF */
        GPIOA->BSRR = (1U << (5 + 16));

        for (volatile int i = 0; i < 1000000; i++);
    }
}