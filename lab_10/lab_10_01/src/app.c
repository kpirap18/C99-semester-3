/*Условие для данной программы:
    В командной строке указывается файл с данными, 
    а так же команда отвечающая за действия со списком (в списке до 100 элементов):

    p - удалить последний элемент в односвязом списке;
    i - вставить элемент в список
        (элементы передаются агрументами
        командной строки (название и имя);
    r - развернуть список (с помощью 3х указателей);
    s - сортировка списка с помощью "Сортировки слиянием";
    
    Список печатается в файл-результат, название файла передается
    в командной строке.

    Пример командной строки
    ./app.exe in.txt out.txt atction [elem1, elem2]
    elem1 - элемент, который надо вставить (содержит 2 поля);
    elem2 - элемент, перед которым надо вставить (содержит 2 поля).
*/

#include "app.h"
#include "list.h"
#include "list_arr.h"
#include "task_01.h"
#include "task_02.h"
#include "task_03.h"

int main(int argc, char **argv)
{
    int rc = OK;
    FILE *f_in, *f_out;
    node_t *head = NULL;

    if (argc != 4 && argc != 8)
    {
        printf("NOTALLARG\n");
        return NOTALLARG;
    }

    f_in = fopen(argv[1], "r");
    if (f_in == NULL)
    {
        printf("OPENERROR 1 \n");
        return OPENERROR;
    }

    f_out = fopen(argv[2], "w");
    if (f_out == NULL)
    {
        fclose(f_in);
        printf("OPENERROR 2 \n");
        return OPENERROR;
    }

    if (argc == 4 && (strcmp(argv[3], "p") == 0))
    {
        head = listread(f_in);
        if (head != NULL)
        {
            book_r *del = pop_back(&head);
            freebook(del);
            listprint(f_out, head);
            listfree(head);
        }
        else
        {
            printf("POPERROR\n");
            rc = POPERROR;
        }
    }
    else if (argc == 8 && (strcmp(argv[3], "i") == 0))
    {
        head = listread(f_in);
        if (head != NULL)
        {
            if (rc != OK)
            {
                listprint(f_out, head);
            }
            else
            {
                node_t *data = listcreatenode(argv[6], argv[7]);
                node_t *res = find(head, data->data, comparator_book);
                node_t *node = listcreatenode(argv[4], argv[5]);
                insert(&head, node, res);
                listprint(f_out, head);
                listonefree(data);
            }
            listfree(head);
        }
        else
        {
            printf("INSERTERROR\n");
            rc = INSERTERROR;
        }
    }
    else if (argc == 4 && (strcmp(argv[3], "r") == 0))
    {
        head = listread(f_in);
        if (head != NULL)
        {
            node_t *new_head = reverse(head);
            listprint(f_out, new_head);
            listfree(new_head);
        }
        else
        {
            printf("REVERROR\n");
            rc = REVERROR;
        }
    }
    else if (argc == 4 && (strcmp(argv[3], "s") == 0))
    {
        head = listread(f_in);
        if (head != NULL)
        {
            node_t *new_head = sort(head, comparator_book);
            listprint(f_out, new_head);
            listfree(new_head);
        }
        else
        {
            printf("SORTERROR\n");
            rc = SORTERROR;
        }
    }
    else
    {
        printf("NOTALLARG\n");
        rc = NOTALLARG;
    }
    

    fclose(f_in);
    fclose(f_out);

    return rc;
}
