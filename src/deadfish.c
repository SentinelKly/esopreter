#include "esolangs.h"

int deadfish_exec(char *src)
{
    short accumulator = 0x0;

    for (int i = 0; i < strlen(src); i++)
    {
        char ins = src[i];

        switch (ins)
        {
            case 'i':
                accumulator ++;
                break;
            
            case 'd':
                accumulator --;
                break;
            
            case 's':
                accumulator *= accumulator;
                break;
            
            case 'o':
                printf("%i", accumulator);
                break;
            
            case 'c':
                printf("%c", accumulator);
                break;
        }

        if (accumulator == -1 || accumulator == 256)
        {
            accumulator = 0;
        }
    }

    return 0;
}