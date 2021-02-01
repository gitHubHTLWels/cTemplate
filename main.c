#include <stdio.h>
#include "analyse.h"

#define STATIC_PATH "/tmp/res.iso"

#define ERROR_OPEN_RES -1
#define ERROR_PROCESSING -2

int main(int argc, char **argv)
{

    if (argc > 1)
    {
        printf("\nAufruf mit  %d Parametern.\n", argc - 1);
    }
    else
    {
        puts("Programm wurde mit keinem Parameter aufgerufen.\n");
    }

    if (argc > 1)
    {
        int jj = 0;
        for (jj = 1; jj < argc; jj++)
        {
            printf("Parameter (%d): %s \n", jj, argv[jj]);
        }
        puts("\n\n");
    }

    if (!do_open(STATIC_PATH))
    {
        do_close();
        return ERROR_OPEN_RES;
    }

    if (!do_main())
    {
        do_close();
        return ERROR_PROCESSING;
    }
    do_close();

    return 0;
}