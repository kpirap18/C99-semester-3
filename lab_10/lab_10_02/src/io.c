#include "io.h"

int inputcommand(FILE *stream, char *command)
{
    int rc = OK;
    
    char *tmp = fgets(command, LENCOMMAND, stream);
    command[strlen(command) - 1] = '\0';
    // printf("tmp = %s\n", tmp);
    // printf("tmp = %s\n", command);

    if (tmp == NULL)
    {
        rc = COMMANDERROR;
    }

    rc = mycheckcommand(tmp);

    return rc;
}

int inputstring(FILE *stream, node_t **list)
{
    int rc = OK;
    char *string;
    size_t len = 0;
    ssize_t read;

    read = my_getline(&string, &len, stream);
    
    if (read != -1)
    {
        stringtolist(string, list);
        free(string);
    }
    else
    {
        rc = INPUTERROR;
    }
    
    return rc;
}

void printdata(FILE *stream, char *string, int len)
{
    for (int i = 0; i < len; ++i)
    {
        fprintf(stream, "%c", string[i]);
    }
}

void printlist(FILE *stream, node_t *list)
{
    int len = 0;
    while (list != NULL)
    {
        if (list->string[LENSTATICSTR - 1] == '\0')
        {
            len = strlen(list->string);
        }
        else
        {
            len = LENSTATICSTR;
        }
        
        printdata(stream, list->string, len);
        list = list->next;
    }
    fprintf(stream, "\n");
}
