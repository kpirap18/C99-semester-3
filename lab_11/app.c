#include <stdio.h>
#include <string.h>
#include "func.h"
#include <limits.h>
#include "my_snprintf.h"

int main()
{
    char s[BUFSIZE];
    int count;

    char s1[222] = "qwerty";
    char f[] = "%s";

    count = my_snprintf(s, 5, f, s1);
    printf("my_snprintf:\n%d %s\n",count, s);

    count = snprintf(s, 5, f, s1);
    printf("snprintf:\n%d %s\n",count, s);

    return 0;
}