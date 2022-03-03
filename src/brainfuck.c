#include "esolangs.h"

int brainfuck_exec(char *src)
{
    size_t tptr = 0;
    size_t tmult = 1;

    unsigned char *tape = malloc(sizeof(unsigned char) * tmult * BF_TAPE_SIZE);
    memset(tape, 0, sizeof(unsigned char) * tmult * BF_TAPE_SIZE);

    for (size_t pc = 0;src[pc] != 0;pc++)
    {
        unsigned char ins = src[pc];

        switch (ins)
        {
            case '>':
                if (tptr == tmult * BF_TAPE_SIZE)
                {
                    tmult ++;
                    tape = realloc(tape, sizeof(unsigned char) * tmult * BF_TAPE_SIZE);
                }

                tptr ++;
                break;
            
            case '<':
                if (tptr > 0) tptr --;
                break;
            
            case '+':
                tape[tptr] ++;
                break;
            
            case '-':
                tape[tptr] --;
                break;
                
            case '.':
                printf("%c", tape[tptr]);
                break;

            case ',':
                //get user input
                break;

            case '[':
                if (tape[tptr] == 0)
                {
                    unsigned long count = 0;

                    while (1)
                    {
                        pc++;

                        if (!src[pc]) break;
                        if (src[pc] == '[') count++;

                        else if (src[pc] == ']') 
                        {
                            if (count) count--;
                            else break;
                        }
                    }
                }

                break;
            
            case ']':
                if (tape[tptr] != 0)
                {
                    unsigned long count = 0;

                    while (1)
                    {
                        pc--;

                        if (!pc) break;
                        if (src[pc] == ']') count++;

                        else if (src[pc] == '[') 
                        {
                            if (count) count--;
                            else break;
                        }
                    }
                }
                break;
        }

        if (tape[tptr] > 255) tape[tptr] -= 256;
        if (tape[tptr] < 0) tape[tptr] += 256;
    }

    return 0;
}