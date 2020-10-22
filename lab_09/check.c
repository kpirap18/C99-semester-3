#include "my_check.h"

int check_feild(char *feild)
{
    if ((strcmp(feild, "title") != 0) && (strcmp(feild, "name") != 0) && (strcmp(feild, "year") != 0))
        return INVALID_ARG;

    return OK;
}
int check_key(char *key)
{
    int key_ = atoi(key);

    if ((key_ <= MIN_YEAR) || (key_ >= MAX_YEAR))
        return INVALID_ARG;

    return OK;
}
