#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "esolangs.h"

#define LCOUNT    1
#define MODE_INT  0
#define MODE_PERS 1

static int (*LANG_INITS[LCOUNT])(char *src) = {deadfish_exec};
static void (*LANG_RESETS[LCOUNT])(void) = {deadfish_reset};

static char *LANGS[LCOUNT] = {"-deadfish"};
static char *COMMANDS[2] = {"#exit", "#clear"};

void print_help(void)
{
    char *msg = 
    "\nEsopreter Help:\n"
    "usage: esopreter <lang> <src>\n\n"
    "Languages:\n"
    "    -deadfish\n\n"
    "Sources\n"
    "    <file> :   source file\n"
    "    ip     :   interactive persistent\n"
    "    i      :   interactive mode\n\n";

    printf("%s", msg);
}

int get_file(char *src, const char *filename)
{
    src = malloc(sizeof(char) * 99999);
	FILE *f = fopen(filename, "r");

	if (f == NULL) 
	{ 
        free(src);
		return -1;
    }

	if (fread(src, sizeof(char), 99999, f)) 
	{ 
		free(src);
		return -2;
	} 

	fclose(f);
    return 0;
}

char *get_input()
{
    char *src = malloc(sizeof(char) * 256);
    scanf("%s", src);
    return src;
}

int get_lang(const char *lang)
{
    for (int i = 0; i < LCOUNT; i++)
    {
        if (!strcmp(lang, LANGS[i]))
        {
            return i;
        }
    }

    return -1;
}

void print_persistance(int mode, int lang)
{
    printf("-%s%s interactive mode--\n\n", LANGS[lang], (mode == MODE_PERS) ? " persistant" : "");
}

int resolve_commands(char *src, int mode, int lang)
{
    if (!strcmp(src, COMMANDS[0]))
    {
        exit(0);
    }

    else if (!strcmp(src, COMMANDS[1]))
    {
        system("clear");
        print_persistance(mode, lang);
        return 1;
    }

    return 0;
}

void interactive_mode(int mode, int lang)
{
    print_persistance(mode, lang);

        while (1)
        {
            printf("\neso:%s -> ", LANGS[lang]);
            char *src = get_input();

            if (src[0] == '#')
            {
                int res = resolve_commands(src, mode, lang);
                continue;
            }

            int err = LANG_INITS[lang](src);
            if (err) {printf("ERROR: CODE %i", err);}

            if (mode == MODE_INT)
            {
                LANG_RESETS[lang]();
            }
        }
}

int main(int argc, char const **argv)
{
    if (argc != 3) {print_help(); return 0;}

    int lang = get_lang(argv[1]);

    if (lang == -1) {print_help(); return 0;}

    if (!strcmp(argv[2], "ip"))
    {
        interactive_mode(MODE_PERS, lang);
    }

    else if (!strcmp(argv[2], "i"))
    {
        interactive_mode(MODE_INT, lang);
    }

    else
    {
        char *src = NULL;
        int out = get_file(src, argv[2]);

        if (out < 0 || !src)
        {
            printf("ERROR: file '%s' not found!\n", argv[2]);
            return 0;
        }

        int err = LANG_INITS[lang](src);
        if (err) {printf("ERROR: CODE %i", err);}
    }

    return 0;
}