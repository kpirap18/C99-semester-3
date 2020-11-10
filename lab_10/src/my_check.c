#include "my_check.h"

int my_check_key(char *key)
{
    int key_ = atoi(key);

    if (key_ <= 0)
        return INVALID_ARG;

    return OK;
}
