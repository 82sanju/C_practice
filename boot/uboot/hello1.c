
#include <common.h>
#include <command.h>

static int do_hello(cmd_tbl_t *cmdtp,
                    int flag,
                    int argc,
                    char * const argv[])
{
    if (argc < 2)
    {
        printf("Usage: hello <name>\n");
        return 1;
    }

    printf("Hello %s!\n", argv[1]);

    return 0;
}

U_BOOT_CMD(
    hello, 2, 1, do_hello,
    "print hello message",
    "<name> - print greeting for the given name"
);
