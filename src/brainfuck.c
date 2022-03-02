#include "esolangs.h"

static unsigned char *tape = 0;
static unsigned long ptr = 0;

static void grow_tape()
{
    tape = realloc(tape, sizeof(tape) + BF_TAPE_SIZE);
}

int brainfuck_exec(char *src)
{
    if (!tape) {brainfuck_reset();}

    for (int i = 0; i < strlen(src); i++)
    {
        unsigned char ins = src[i];
    }

    return 0;
}

void brainfuck_reset(void)
{
    free(tape);
    tape = malloc(sizeof(char) * BF_TAPE_SIZE);
}
