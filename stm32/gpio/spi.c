#include <stdint.h>

/* RCC registers */
#define RCC_AHB1ENR  (*(volatile uint32_t *)0x40023830)
#define RCC_APB2ENR  (*(volatile uint32_t *)0x40023844)

/* GPIOA registers */
#define GPIOA_MODER  (*(volatile uint32_t *)0x40020000)
#define GPIOA_ODR    (*(volatile uint32_t *)0x40020014)
#define GPIOA_AFRL   (*(volatile uint32_t *)0x40020020)

/* SPI1 registers */
#define SPI1_CR1     (*(volatile uint32_t *)0x40013000)
#define SPI1_SR      (*(volatile uint32_t *)0x40013008)
#define SPI1_DR      (*(volatile uint32_t *)0x4001300C)

int main(void)
{
    /* 1. Enable GPIOA clock */
    RCC_AHB1ENR |= (1 << 0);

    /* 2. Enable SPI1 clock */
    RCC_APB2ENR |= (1 << 12);

    /* 3. Configure PA5, PA6, PA7 as Alternate Function */
    GPIOA_MODER &= ~((3 << 10) |
                     (3 << 12) |
                     (3 << 14));

    GPIOA_MODER |=  ((2 << 10) |
                     (2 << 12) |
                     (2 << 14));

    /* 4. Select AF5 for PA5, PA6, PA7 */
    GPIOA_AFRL &= ~((0xF << 20) |
                    (0xF << 24) |
                    (0xF << 28));

    GPIOA_AFRL |=  ((5 << 20) |
                    (5 << 24) |
                    (5 << 28));

    /* 5. Configure PA4 as CS output */
    GPIOA_MODER &= ~(3 << 8);
    GPIOA_MODER |=  (1 << 8);

    /* CS initially HIGH */
    GPIOA_ODR |= (1 << 4);

    /* 6. Configure SPI1 */
    // We'll do this next

    /* 7. Enable SPI1 */

    /* 8. SPI loopback test */

    while (1)
    {
    }
}