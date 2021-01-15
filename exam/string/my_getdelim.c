// By Alena
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int my_getdelim(char **lineptr, size_t *n, int delim, FILE *stream)
{
	*lineptr = NULL;
	char *temp = NULL;
    char c;
    int rc = 0;
    
    size_t len = 0;
    while (((c = fgetc(stream)) != delim) && (c != EOF) && (rc == 0))
    {
		len++;
		temp = realloc((*lineptr), (len + 1) * sizeof(char));
		if (temp != NULL)
		{
			(*lineptr) = temp;
			(*lineptr)[len - 1] = c;
		}
		else
		{
			free(*lineptr);
			rc = -1;
		}			
    }
	if (rc == 0)
	{
		if (len == 0)
		{
			if (feof(stream))
				rc = -1;
			else
				rc = -1;
		}
		else 
			(*lineptr)[len] = '\0';
	}
    *n = len;
    return rc;
}
