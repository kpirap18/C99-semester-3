#include "my_check.h"

int my_check_key(char *key)
{
    int key_ = atoi(key);

    if (key_ <= 0)
        return INVALID_ARG;

    return OK;
}

int filelen(FILE *f)
{
    int num, len = 0;
    rewind(f);
    while(fscanf(f, "%d", &num) == 1)
    {
        len++;
    }

    return len;
}
