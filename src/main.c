#include <stdio.h>
#include "esolangs.h"

#define LCOUNT 1

static int (*lang_inits[LCOUNT])(char *src) = {df_init};
static void (*lang_resets[LCOUNT])(void) = {df_reset};

static char *langs[LCOUNT] = {"-df"};

void print_help(void)
{
    char *msg = 
    "Esopreter Help:\n"
    "usage: esopreter <lang> <src>\n\n"
    "Languages:\n"
    "    -df    :   deadfish\n\n"
    "Sources"
    "    <file> :   source file\n"
    "    i      :   interactive mode\n\n";

    printf(msg);
}

int main(int argc, char const **argv)
{
    if (argc != 3)
    {
        print_help();
        return -1;
    }
}