#ifndef _ESOLANGS_H_
#define _ESOLANGS_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BF_TAPE_SIZE  30000

typedef enum lang_t
{
    DEADFISH, BRAINFUCK
} lang_t;

int deadfish_exec(char *src);
int brainfuck_exec(char *src);

#endif