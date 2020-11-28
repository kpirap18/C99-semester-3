#include "my_snprintf.h"
#include <stdio.h>

int my_snprintf(char *s, size_t n, const char *format, ...)
{
    va_list args;
    va_start(args, format);

    size_t lenout = 0;
    
    while (*format)
    {
        if (*format == '%')
        {
            if (*(format + 1) == 's')
            {
                char *str = va_arg(args, char *);
                if (!str)
                {
                    format++;
                }
                else
                {
                    while (*str != '\0')
                    {
                        if (s && n && lenout < n)
                        {
                            s[lenout] = *str;
                        }
                        str++;
                        lenout++;
                    }
                }
                format += 2;
            }
            else if (*(format + 1) == 'x')
            {
                uint32_t num = va_arg(args, uint32_t);

                if (num == 0)
                {
                    s[lenout] = '0';
                    lenout++;
                }
                else
                {
                    char newnum[BUFSIZE] = "\0";
                    int len = toanysystem(newnum, num, 16);
                    int i = 0;
                    while (i < len && newnum[i])
                    {
                        if (s && n && lenout < n)
                        {
                            s[lenout] = newnum[i];
                        }
                        i++;
                        lenout++;
                    }
                }

                format += 2;
            }
            else if (*(format + 1) == 'd')
            {
                int num = va_arg(args, int);
                if (num == 0)
                {
                    s[lenout] = '0';
                    lenout++;
                }
                else
                {
                    if (num < 0)
                    {
                        s[lenout] = '-';
                        lenout++;
                    }

                    char newnum[BUFSIZE] = "\0";
                    int len = inttostring(newnum, num);
                    int i = 0;
                    while (i < len && newnum[i])
                    {
                        if (s && n && lenout < n)
                        {
                            s[lenout] = newnum[i];
                        }
                        i++;
                        lenout++;
                    }
                }
                
                format += 2;
            }
            else if (*(format + 1) == 'h' && *(format + 2) == 'd')
            {
                int16_t num = va_arg(args, int);
                if (num == 0)
                {
                    s[lenout] = '0';
                    lenout++;
                }
                else
                {
                    if (num < 0)
                    {
                        s[lenout] = '-';
                        lenout++;
                    }

                    char newnum[BUFSIZE] = "\0";
                    int len = inttostring(newnum, num);
                    int i = 0;
                    while (i < len && newnum[i])
                    {
                        if (s && n && lenout < n)
                        {
                            s[lenout] = newnum[i];
                        }
                        i++;
                        lenout++;
                    }
                }
                
                format += 3;
            }
            else if (*(format + 1) == 'l' && *(format + 2) == 'l' && *(format + 3) == 'x')
            {
                uint64_t num = va_arg(args, uint64_t);
                if (num == 0)
                {
                    s[lenout] = '0';
                    lenout++;
                }
                else
                {
                    char newnum[BUFSIZE] = "\0";
                    int len = toanysystem(newnum, num, 16);
                    int i = 0;
                    while (i < len && newnum[i])
                    {
                        if (s && n && lenout < n)
                        {
                            s[lenout] = newnum[i];
                        }
                        i++;
                        lenout++;
                    }
                }
                
                format += 4;
            }
        }
        else
        {
            if (s && n && lenout < n)
            {
                s[lenout] = *format;
                format++;
            }
            else
            {
                format++;
            }
            lenout++;
        }
    }

    va_end(args);

    if (s && n)
    {
        if (lenout < n)
        {
            s[lenout] = '\0';
        }
        else
        {
            s[n - 1] = '\0';
        }
    }

    return lenout;
}