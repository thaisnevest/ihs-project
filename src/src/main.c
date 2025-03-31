#include <stdio.h>
#include "raylib.h"
#include "menu/menu.h"
#include "updategame/updategame.h"
#include "final/final.h"
#include "string.h"
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <errno.h>
#include "../../include/ioctl_cmds.h"

int main(int argc, char** argv)
{
    int fd;

    if (argc < 2) {
        printf("Precisa do /dev/mydev no argumento na hora de compilar. %s\n", argv[0]);
        return -EINVAL;
    }

    if ((fd = open(argv[1], O_RDWR)) < 0) {
        fprintf(stderr, "Error opening file %s\n", argv[1]);
        return -EBUSY;
    }

    SetTargetFPS(60);
    InitMenu(fd);
    updategame(fd);
    InitFinal();
    return 0;
}
