#include <common.h>
#include <command.h>

static int do_hello(cmd_tbl_t *cmdtp,
                    int flag,
                    int argc,
                    char * const argv[])
{
    printf("Hello! My first U-Boot program.\n");
    return 0;
}

U_BOOT_CMD(
    hello, 1, 1, do_hello,
    "print my first U-Boot message",
    ""
);