#include <stdarg.h>
#include "count.h"

int count(char *name, ...)
{
    va_list args;
    va_start(args, name);
    int wordall = 0;
    char *name1 = name;

    while (name1)
    {
        int rc = checkfile(name1);

        if (rc != ERROR)
        {
            FILE *f = fopen(name1, "rb");
            int cur = wordinfile(f, rc);
            printf("In file \"%s\" %d words\n", name1, cur);
            fclose(f);
            wordall += cur;
            cur = 0;
        }
        name1 = va_arg(args, char *);
    }

    va_end(args);

    return wordall;
}

int wordinfile(FILE *f, int len)
{
    int count = 0;

    char ch, chbefore;
    fread(&chbefore, sizeof(char), 1, f);
    //printf("%c", chbefore);
    for (int i = 0; i < len; ++i)
    {
        fread(&ch, sizeof(char), 1, f);
        //printf("%c", ch);
        if (!isdelim(ch) && (int)chbefore == 92)
        {
            fread(&ch, sizeof(char), 1, f);
            chbefore = ch;
        }
        else if (isdelim(ch) && (isdelim(chbefore) == 0))
        {
            count++;
        }
        else if (isdelim(ch) == 0 && i == len - 1)
        {
            count++;
        }
        chbefore = ch;
    }

    return count;
}

// int count(int number, ...)
// {
//     va_list args;
//     va_start(args, number);
//     int wordall = 0;

//     for (int i = 0; i < number; ++i)
//     {
//         char *name = va_arg(args, char *);
//         int rc = checkfile(name);

//         if (rc == ERROR)
//         {
//             fprintf(stdout, "File has some error\n");
//         }
//         else
//         {
//             FILE *f = fopen(name, "rb");
//             int cur = wordinfile(f, rc);
//             printf("In file \"%s\" %d words\n", name, cur);
//             fclose(f);
//             wordall += cur;
//             cur = 0;
//         }
//     }

//     va_end(args);

//     return wordall;
// }