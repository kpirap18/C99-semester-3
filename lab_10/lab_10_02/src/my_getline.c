#include "my_getline.h"

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	char simbol;
	ssize_t len = 0, size_str = 0;
	char *str = NULL, *str_buf = NULL;

	if (stream == NULL)
	{
		*lineptr = NULL;
		*n = 0;
		return -1;
	}
	
	if (((simbol = fgetc(stream)) != '\n') && (simbol != EOF))
	{
		++len;
	}
	else
	{
		*lineptr = NULL;
		*n = 0;
		return -1;
	}
	
	str = calloc(len * 2, sizeof(char));
	str[0] = simbol;
	size_str = len * 2;
	
	while (((simbol = fgetc(stream)) != '\n') && (simbol != EOF))
	{
		++len;
		
		if (size_str <= len)
		{
			str_buf = realloc(str, sizeof(char) * len * 2);
			size_str = len * 2;
			if (str_buf != NULL)
			{
				str = str_buf;
				str[len - 1] = simbol;
			}
			else
			{
				free(str);
				*lineptr = NULL;
				*n = 0;
				return -1;
			}
		}
		else
		{
			str[len - 1] = simbol;
		}
	}
	
	*n = len;
	str[len] = '\0';
	*lineptr = str;
	
	return len;
}
