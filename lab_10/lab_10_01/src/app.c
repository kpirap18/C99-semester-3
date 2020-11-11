/*Условие для данной программы:
    В командной строке указывается файл с данными, 
    а так же команда отвечающая за действия со списком (в списке до 100 элементов):

    p - удалить последний элемент в односвязом списке;
    i - вставить элемент перед указанным
        (элемент, который надо вставить передается агрументом
        командной строки, элемент, перед которым надо
        вставиь также передается аргументом командной строки
        (если такого элеента нет, печатается исходный список));
    r - развернуть список (с помощью 3х указателей);
    s - сортировка списка с помощью "Сортировки слиянием";
    
    Список печатается в файл-результат, название файла передается
    в командной строке.

    Пример командной строки
    ./app.exe in.txt out.txt atction [elem1, elem2]
    elem1 - элемент, который надо вставить;
    elem2 - элемент, перед которым надо вставить.
*/

#include "app.h"
#include "list.h"
#include "task_01.h"
#include "task_02.h"
#include "task_03.h"
#include "my_check.h"

int main(int argc, char **argv)
{
    int rc = OK;
    FILE *f_in, *f_out;
    node_t *head = NULL;
    int *num = NULL;

    if (argc != 4 && argc != 6)
    {
        return NOTALLARG;
    }

    f_in = fopen(argv[1], "r");
    if (f_in == NULL)
    {
        return OPENERROR;
    }

    f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        fclose(f_in);
        return OPENERROR;
    }

    if (argc == 4 && (strcmp(argv[3], "p") == 0))
    {
        head = listread(f_in, &num);
        if (head != NULL)
        {
            void *buf = pop_back(&head);
            listprint(f_out, head);
            free(num);
            free(buf);
            listfree(head);
        }
        else
        {
            rc = POPERROR;
        }
    }
    else if (argc == 6 && (strcmp(argv[3], "i") == 0))
    {
        head = listread(f_in, &num);
        if (head != NULL)
        {
            int num_p; 
            int rc = my_check_key(argv[5]);
            if (rc == OK)
            {
                num_p = atoi(argv[5]);
            }
            int num_b;   
            rc += my_check_key(argv[4]);
            if (rc == OK)
            {
                num_b = atoi(argv[4]);
            }

            if (rc != OK)
            {
                listprint(f_out, head);
            }
            else
            {
                node_t *res = find(head, &num_p, comparator_int);
                node_t *node = listcreatenode((void *)&num_b);
                insert(&head, node, res);
                listprint(f_out, head);
            }
            free(num);
            listfree(head);
        }
        else
        {
            rc = INSERTERROR;
        }
    }
    else if (argc == 4 && (strcmp(argv[3], "r") == 0))
    {
        head = listread(f_in, &num);
        if (head != NULL)
        {
            node_t *new_head = reverse(head);
            listprint(f_out, new_head);
            free(num);
            listfree(new_head);
        }
        else
        {
            rc = REVERROR;
        }
    }
    else if (argc == 4 && (strcmp(argv[3], "s") == 0))
    {
        head = listread(f_in, &num);
        if (head != NULL)
        {
            node_t *new_head = sort(head, comparator_int);
            listprint(f_out, new_head);
            free(num);
            listfree(new_head);
        }
        else
        {
            rc = SORTERROR;
        }
    }

    fclose(f_in);
    fclose(f_out);

    return rc;
}
