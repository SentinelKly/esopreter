#ifndef _ESOLANGS_H_
#define _ESOLANGS_H_

typedef enum lang_t
{
    DEADFISH
} lang_t;

int df_init(char *src);
void df_reset(void);

#endif