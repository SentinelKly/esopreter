#ifndef _ESOLANGS_H_
#define _ESOLANGS_H_

#include <stdio.h>
#include <string.h>

typedef enum lang_t
{
    DEADFISH
} lang_t;

#define ERR_INVALID_TOKEN 0x1

int deadfish_exec(char *src);
void deadfish_reset(void);

#endif