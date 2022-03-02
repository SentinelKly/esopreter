#include "esolangs.h"

static short accumulator = 0x0;

int deadfish_exec(char *src)
{
    for (int i = 0; i < strlen(src); i++)
    {
        char ins = src[i];

        if (ins == '\n' || ins == '\r' || ins == '\t' || ins == ' ')
        {
            continue;
        }

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

            default:
                return ERR_INVALID_TOKEN;
                break;
        }

        if (accumulator == -1 || accumulator == 256)
        {
            accumulator = 0;
        }
    }

    return 0;
}

void deadfish_reset()
{
    accumulator = 0;
}