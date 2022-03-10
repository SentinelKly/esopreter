#include "esolangs.h"

#ifdef _WIN32
#   define CLEAR() system("cls")
#else
#   define CLEAR() system("clear")
#endif

#define MAX_FILE_BUFF 100000000
#define LCOUNT 2

static int (*LANG_INITS[LCOUNT])(char *src) = {deadfish_exec, brainfuck_exec};

static char *LANGS[LCOUNT] = {"-deadfish", "-brainfuck"};
static char *COMMANDS[2] = {"#exit", "#clear"};

void print_help(void)
{
    char *msg = 
    "\nEsopreter Help\n"
    "usage: esopreter <lang> <src>\n\n"
    "Languages\n"
    "    -deadfish\n"
    "    -brainfuck\n\n"
    "Sources\n"
    "    <file> :   source file\n"
    "    i      :   interactive mode\n\n";

    printf("%s", msg);
}

char *get_file(char const *filename)
{
    char *src = malloc(sizeof(char) * MAX_FILE_BUFF + 1);
    FILE *fp = fopen(filename, "r");

    if (fp != NULL) 
    {
        size_t len = fread(src, sizeof(char), MAX_FILE_BUFF, fp);

        if (ferror(fp) != 0)  free(src);
        else src[len++] = '\0';

        fclose(fp);
        return src;
    }

    free(src);
    src = NULL;
    return src;
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
        if (!strcmp(lang, LANGS[i]))  return i;
    }

    return -1;
}


int resolve_commands(char *src, int lang)
{
    if (!strcmp(src, COMMANDS[0]))
    {
        exit(0);
        return 1;
    }

    else if (!strcmp(src, COMMANDS[1]))
    {
        CLEAR();
        printf("-%s interactive mode--\n\n", LANGS[lang]);
        return 1;
    }

    return 0;
}

void interactive_mode(int lang)
{
     printf("-%s interactive mode--\n\n", LANGS[lang]);

        while (1)
        {
            printf("\neso:%s -> ", LANGS[lang]);
            char *src = get_input();

            if (src[0] == '#')
            {
                int res = resolve_commands(src, lang);
                continue;
            }

            int err = LANG_INITS[lang](src);
            if (err) {printf("ERROR: CODE %i", err);}
        }
}

int main(int argc, char const **argv)
{
    if (argc != 3) {print_help(); return 0;}

    int lang = get_lang(argv[1]);

    if (lang == -1) {print_help(); return 0;}

    if (!strcmp(argv[2], "i"))
    {
        interactive_mode(lang);
    }

    else
    {
        char *src = get_file(argv[2]);

        if (!src)
        {
            printf("ERROR: file '%s' not found!\n", argv[2]);
            return 0;
        }

        int err = LANG_INITS[lang](src);
        if (err) {printf("ERROR: CODE %i", err);}
    }

    return 0;
}