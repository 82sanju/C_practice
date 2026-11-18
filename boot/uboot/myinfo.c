
#include <common.h>
#include <command.h>

static int do_myinfo(cmd_tbl_t *cmdtp, int flag,
                     int argc, char *const argv[])
{
    int i;

    printf("\n");
    printf("================================\n");
    printf("       MYINFO COMMAND\n");
    printf("================================\n");

    printf("Message: Custom U-Boot command\n");
    printf("Argument count (argc): %d\n", argc);

    printf("\nArguments passed:\n");

    for (i = 0; i < argc; i++)
    {
        printf("argv[%d] = %s\n", i, argv[i]);
    }

    printf("================================\n");

    return CMD_RET_SUCCESS;
}

U_BOOT_CMD(
    myinfo, 10, 1, do_myinfo,
    "display command information",
    "[arg1] [arg2] [arg3] ..."
);
