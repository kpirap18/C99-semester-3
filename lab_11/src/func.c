#include "func.h"
#include <stdio.h>

int toanysystem(char *newnum, unsigned long long int number, int foundation)
{
    char alf[17] = "0123456789abcdef";
    int len = leninsystem(number, foundation);

    if (number == 0)
    {
        newnum[0] = '\0';
    }

    int i = 0;
    while (number > 0)
    {
        newnum[i++] = alf[number % foundation];
        number /= foundation;
    }
    newnum[i] = '\0';

    for (i = 0; i < len / 2; ++i)
    {
        char buf = newnum[i];
        newnum[i] = newnum[len - i - 1];
        newnum[len - i - 1] = buf;       
    }

    return len;
}

size_t my_strlen(const char *string)
{
    int len = 0;

    while (string[len] != '\0')
    {
        ++len;
    }

    return len;
}

int lennumber(long long int number)
{
    int len = 0;
    if (number < 0)
    {
        number *= -1;
    }
    while (number > 0)
    {
        len++;
        number /= 10;
    }

    return len;
}

int leninsystem(long long int number, int foundation)
{
    int len = 0;

    if (number < 0)
    {
        number = LLONG_MAX + number;
    }
    
    while (number > 0)
    {
        number /= foundation;
        ++len;
    }

    return len;
}

int inttostring(char *newnum, long long int number)
{
    int len = lennumber(number);
    if (number < 0)
    {
        number *= -1;
    }

    int i = 0;
    while (number > 0)
    {
        newnum[i] = (number % 10) + '0';
        number /= 10;
        i++;
    }

    for (i = 0; i < len / 2; ++i)
    {
        char buf = newnum[i];
        newnum[i] = newnum[len - i - 1];
        newnum[len - i - 1] = buf;       
    }

    return len;
}