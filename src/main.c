#include <stdio.h>
#include "esolangs.h"

typedef enum lang_t
{
    DEADFISH
} lang_t;

void print_help(void)
{
    char *msg = 
    "ESOTERP COMMANDS:\n"
    "-h         :   print this message\n"
    "-df  <src> :   run deadfish (file)\n"
    "-df  i     :   run deadfish (interactive)\n\n";

    printf(msg);
}

int init(char *src, lang_t lang)
{
    switch (lang)
    {
        case DEADFISH:
            return df_init(src);
    }
}

void reset(lang_t lang)
{
    switch (lang)
        {
            case DEADFISH:
                df_reset();
                break;
        }
}

int main(int argc, char const **argv)
{
    if (argc != 3)
    {
        print_help();
        return -1;
    }
}