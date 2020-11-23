#include "parsing.h"

void stringtolist(char *string, node_t **list)
{
    int len = strlen(string);
    int pos = 0;
    node_t *tmp = *list;
    node_t *cur;

    while (len)
    {
        cur = listcreatenode(string, &pos, &len);

        if (cur)
        {
            tmp = listaddbegin(tmp, cur);
        }
        else
        {
            free(tmp);
            *list = NULL;
            cur = NULL;
            tmp = NULL;
        }
    }

    *list = reverse(tmp);
}

/*
void listtostring(node_t *list, char *string, int count)
{
    int pos = 0;
    int i = 0;
    for (int j = 0; j < count; ++j)
    {
        i = 0;
        while (i < LENSTATICSTR && list->string[i] != '\0')
        {
            string[pos] = list->string[i];
            i++;
            pos++;
        }
        list = list->next;
    }
}
*/