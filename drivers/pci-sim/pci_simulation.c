#include <stdio.h>
#include <stdint.h>

/* Simulated BAR (256 bytes) */
uint32_t bar[64];

/* Register offsets */
#define REG_STATUS   0x00
#define REG_CONTROL  0x04
#define REG_DATA     0x08

/* Read register (like readl) */
uint32_t read_reg(uint32_t offset)
{
    return bar[offset / 4];
}

/* Write register (like writel) */
void write_reg(uint32_t offset, uint32_t value)
{
    bar[offset / 4] = value;

    /* Simulate device behavior */
    if (offset == REG_CONTROL) {
        if (value == 1) {
            printf("Device: START command received\n");
            bar[REG_STATUS / 4] = 0x1;  // set status = busy
        } else if (value == 0) {
            printf("Device: STOP command received\n");
            bar[REG_STATUS / 4] = 0x0;  // set status = idle
        }
    }
}

int main()
{
    printf("=== Fake PCI Device Simulation ===\n");

    /* Initial state */
    printf("Initial STATUS: 0x%x\n", read_reg(REG_STATUS));

    /* Driver writes START */
    write_reg(REG_CONTROL, 1);

    /* Driver reads STATUS */
    printf("After START, STATUS: 0x%x\n", read_reg(REG_STATUS));

    /* Write some data */
    write_reg(REG_DATA, 0xdeadbeef);
    printf("DATA register: 0x%x\n", read_reg(REG_DATA));

    /* Driver writes STOP */
    write_reg(REG_CONTROL, 0);

    printf("After STOP, STATUS: 0x%x\n", read_reg(REG_STATUS));

    return 0;
}
