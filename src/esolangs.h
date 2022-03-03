#ifndef _ESOLANGS_H_
#define _ESOLANGS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define ERR_INVALID_TOKEN 0x1

#define BF_TAPE_SIZE  30000
#define BF_STACK_SIZE   500
#define BF_MODE_INS       1
#define BF_MODE_BR        2

typedef enum lang_t
{
    DEADFISH, BRAINFUCK
} lang_t;

int deadfish_exec(char *src);
int brainfuck_exec(char *src);

#endif