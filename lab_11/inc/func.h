#ifndef _FUNC_H_
#define _FUNC_H_

#include <string.h>
#include <stdint.h>
#include <stdlib.h>
#include <limits.h>

#define OK            0
#define ERROR        -1

#define BUFSIZE     255

int toanysystem(char *newnum, unsigned long long int number, int foundation);

size_t my_strlen(const char *string);

int lennumber(long long int number);

int leninsystem(long long int number, int foundation);

int inttostring(char *newnum, long long int number);

#endif //_FUNC_H_