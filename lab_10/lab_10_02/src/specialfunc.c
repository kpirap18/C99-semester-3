#include "specialfunc.h"

int mycheckcommand(char *feild)
{
    if ((strcmp(feild, "out") != 0) && \
        (strcmp(feild, "cat") != 0) && \
        (strcmp(feild, "sps") != 0) && \
        (strcmp(feild, "pos") != 0))
        return COMMANDERROR;

    return OK;
}

// void compact(node_t **list)
// {
//     int count = 0;
//     listcount(*list, &count);
//     //printf("%d\n", count);///
//     char *string = calloc(count * LENSTATICSTR, sizeof(char));
//     listtostring(*list, string, count);
//     listfree(*list);
//     *list = NULL;
//     stringtolist(string, list);
//     //printf("%s\n", string);////
//     free(string);
// }

void compact(node_t *list)
{
    int comp = 0;

    while (list && list->string[comp] != '\0')
    {
        if (comp == LENSTATICSTR - 1)
        {
            list = list->next;
            comp = 0;
        }
        else
        {
            comp++;
        }
    }

    node_t *tmp;
    int old; 
    if (comp == LENSTATICSTR - 1)
    {
        tmp = list->next;
        old = 0;
    }
    else
    {
        tmp = list;
        old = comp + 1;
    }
    
    while (tmp)
    {
        if (tmp->string[old] == '\0')
        {
            if (old == LENSTATICSTR - 1)
            {
                old = 0;
                tmp = tmp->next;
            }
            else
            {
                old++;
            }
        }
        else if (tmp->string[old] != '\0')
        {
            list->string[comp] = tmp->string[old];
            if (old == LENSTATICSTR - 1)
            {
                old = 0;
                tmp = tmp->next;
            }
            else
            {
                old++;
            }
            if (comp == LENSTATICSTR - 1)
            {
                comp = 0;
                list = list->next;
            }
            else
            {
                comp++;
            }
        }
    }

    while (list)
    {
        list->string[comp] = '\0';
        if (comp == LENSTATICSTR - 1)
        {
            comp = 0;
            list = list->next;
        }
        else
        {
            comp++;
        }
    }
}

void deletespice(node_t *list)
{
    int count = 0;
    int flag = 0;
    listcount(list, &count);

    for (int i = 0; i < count; ++i)
    {
        for (int j = 0; j < LENSTATICSTR; ++j)
        {
            if (list->string[j] == '\0')
            {
                continue;
            }
            if (list->string[j] == ' ' && flag == 0)
            {
                flag = 1;
            }
            else if (list->string[j] == ' ' && flag == 1)
            {
                for (int k = j; k < LENSTATICSTR; ++k)
                {
                    if (k == LENSTATICSTR - 1)
                    {
                        list->string[k] = '\0';
                    }
                    else
                    {
                        list->string[k] = list->string[k + 1];
                    }
                }
                if (j != LENSTATICSTR - 1)
                {
                    j--;
                }
                else
                {
                    list->string[j] = '\0';
                }
            }
            else if (list->string[j] != ' ' && flag == 1)
            {
                flag = 0;
            }
        }
        list = list->next;
    }
}

int findpos(node_t *listwhere, node_t *listwhat)
{
    node_t *where = listwhere;
    node_t *what = listwhat;
    int iwhat = 0;
    int iwhere = 0;
    int pos = -1;
    int flag = 0;
    int lenwhere = 0;
    int lenwhat = 0;

    listcount(listwhere, &lenwhere);
    listcount(listwhat, &lenwhat);

    for (int i = 0; i < lenwhere;)
    {
        if (what->string[iwhat] == '\0')
        {
            break;
        }
        if (where->string[iwhere] == what->string[iwhat])
        {
            if (flag == 0)
                pos = iwhere + LENSTATICSTR * i;

            flag = 1;
            if (iwhat == LENSTATICSTR - 1)
            {
                iwhat = 0;
                what = what->next;
                i++;
            }
            else
            {
                iwhat++;
            }
            if (iwhere == LENSTATICSTR - 1)
            {
                iwhere = 0;
                where = where->next;
                i++;
            }
            else
            {
                iwhere++;
            }  
        }
        else if (where->string[iwhere] != what->string[iwhat] && flag == 1)
        {
            where = listwhere;
            what = listwhat;
            int s = 0;
            while (s < pos)
            {
                where = where->next;
                s += LENSTATICSTR;
            }
            iwhere = pos + 1;
            i = iwhere / LENSTATICSTR;
            if (iwhere == 4)
            {
                iwhere = 0;
            }
            pos = -1;
            iwhat = 0;
            flag = 0;
        }
        else if (where->string[iwhere] != what->string[iwhat] && flag == 0)
        {
            if (iwhere == LENSTATICSTR - 1)
            {
                iwhere = 0;
                where = where->next;
                i++;
            }
            else
            {
                iwhere++;
            }
        }
    }

    return pos;
}