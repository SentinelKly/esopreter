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

int get_file(char *src, const char *filename)
{
    int size = 0;

	FILE *f = fopen(filename, "rb");

	if (f == NULL) 
	{ 
		src = NULL;
		return -1;
    }

	fseek(f, 0, SEEK_END);
	size = ftell(f);
	fseek(f, 0, SEEK_SET);

	src = (char *) malloc(size + 1);

	if (size != fread(src, sizeof(char), size, f)) 
	{ 
		free(src);
		return -2;
	} 

	fclose(f);
	src[size] = 0;

	return size;
}

char *get_input()
{
    char *src = malloc(sizeof(char) * 256);
    scanf("%s", src);
    return src;
}

int main(int argc, char const **argv)
{
    if (argc != 3)
    {
        print_help();
        return -1;
    }

    
}