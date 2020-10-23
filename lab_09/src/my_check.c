#include "my_check.h"

int my_check_feild(char *feild)
{
    if ((strcmp(feild, "title") != 0) && (strcmp(feild, "name") != 0) && (strcmp(feild, "year") != 0))
        return INVALID_ARG;

    return OK;
}
int my_check_key(char *key)
{
    int key_ = atoi(key);

    if ((key_ <= MIN_YEAR) || (key_ >= MAX_YEAR))
        return INVALID_ARG;

    return OK;
}
