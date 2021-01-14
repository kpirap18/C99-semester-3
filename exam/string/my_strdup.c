#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strdup(const char *str)
{
    size_t len = strlen(str);
    char *new_str = malloc((len + 1) * sizeof(char));
    for (size_t i = 0; i < len; ++i)
    {
        new_str[i] = str[i];
    }
    new_str[len] = '\0';

    return new_str;
}

char *my_strndup(const char *str, size_t n)
{
    size_t len = strlen(str);
    if (n < len)
    {
        len = n;
    }
    char *new_str = malloc((len + 1) * sizeof(char));
    for (size_t i = 0; i < len; ++i)
    {
        new_str[i] = str[i];
    }
    new_str[len] = '\0';

    return new_str;
}

int main()
{    
    // Исходная строка
    char str[11] = "0123456789";
    // переменная, в которую будет помещен указатель на дубликат строки
    char *istr;

    // Дублирование строки
    istr = my_strdup (str);

    // Вывод дубликата на консоль
    printf ("Дубликат: %s\n", istr);

    // Очищаем память, выделенную под дубликат
    free (istr);

    return 0;
}
