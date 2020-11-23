#include "io.h"
#include "app.h"
#include "list.h"
#include "parsing.h"
#include "specialfunc.h"
#include "my_getline.h"

int main()
{
    int rc = OK;
    char command[LENCOMMAND];
    
    rc = inputcommand(stdin, command);

    if (rc != OK)
    {
        return rc;
    }

    if (strcmp(command, "out") == 0)
    {
        node_t *list = NULL;
        rc = inputstring(stdin, &list);

        if (rc == OK)
        {
            printlist(stdout, list);
            listfree(list);
        }
    }
    else if (strcmp(command, "cat") == 0)
    {
        node_t *list1 = NULL;
        node_t *list2 = NULL;

        rc = inputstring(stdin, &list1);
        if (rc == OK)
        {
            rc = inputstring(stdin, &list2);
            if (rc == OK)
            {
                append(&list1, &list2);
                compact(list1);
                printlist(stdout, list1);
                listfree(list2);
            }
            listfree(list1);            
        }
    }
    else if (strcmp(command, "sps") == 0)
    {
        node_t *list = NULL;

        rc = inputstring(stdin, &list);
        if (rc == OK)
        {
            deletespice(list);
            compact(list);
            printlist(stdout, list);
            listfree(list);            
        }
    }
    else if (strcmp(command, "pos") == 0)
    {
        node_t *listwhere = NULL;
        node_t *listwhat = NULL;

        rc = inputstring(stdin, &listwhere);
        if (rc == OK)
        {
            rc = inputstring(stdin, &listwhat);
            if (rc == OK)
            {
                int pos = findpos(listwhere, listwhat);
                fprintf(stdout, "%d\n", pos);

                listfree(listwhat);
            }
            listfree(listwhere);            
        }
    }
    
    return rc;
}
