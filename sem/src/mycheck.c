#include <string.h>
#include "mycheck.h"

int checkfile(char *name)
{
    FILE *f = fopen(name, "rb");
    if (!f)
    {
        return ERROR;
    }

    int size;
    fseek(f, 0, SEEK_END);

    size = ftell(f);

    if (size <= 0)
    {
        fclose(f);
        return ERROR;
    }

    fclose(f);
    return size;
}

int isdelim(char s)
{
    char delim[] = {' ','.',',',':',';','\'','[',']','{','\\','\"',
                    '1','2','3','4','5','6','7','8','9','0','}','(',
                    ')','?','|','/','!','<','>','\n','%','=','+','-',
                    '*','\a','\b','\v','\f','\r','$','\0'};
    for (int i = 0; delim[i] != '\0'; ++i)
    {
        if (s == delim[i])
            return 1;
    }

    return 0;
}

