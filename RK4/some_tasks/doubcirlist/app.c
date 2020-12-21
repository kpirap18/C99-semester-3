#include <stdio.h>
#include <stdlib.h>

#define BUFSIZE 255

typedef struct node
{
    void *data;

    struct node *prev;
    struct node *next;
} node_t;

typedef struct data
{
    char *name;
    int age;
    struct node *grad;
} data_t;

// io.h
int print_menu();
void print_list(FILE *f, node_t *list, int flag);
void print_data(FILE *f, data_t *data);

// list.h
void push(node_t **list, void *data, int pos);
node_t *pop(node_t  *list, int pos);
void free_list(node_t *list, int flag);

// data.h
data_t *create_data(char *name, int age, node_t *grad);
data_t *input_data();
void free_data(data_t *data);


//io.c
int print_menu();
void print_list(FILE *f, node_t *list, int flag)
{
    if (!list)
    {
        fprintf(f, "Список пустой\n");
        return;
    }

    node_t *tmp = list;

    do
    {
        if (flag)
        {
            print_data(f, (data_t *)tmp->data);
        }
        else
        {
            fprintf(f, "%d ", *((int *)tmp->data));
        }
        tmp = tmp->next;
        
    } while (tmp && (tmp != list));
}

void print_data(FILE *f, data_t *data)
{
    if (data)
    {
        fprintf(f, "%s\n", data->name);
        fprintf(f, "%d\n", data->age);
        print_list(f, data->grad, 0);
    }
}

// list.c
void push(node_t **list, void *data, int pos)
{
    node_t *cur;
    node_t *tmp = malloc(sizeof(node_t));
    if (!tmp)
    {
        return;
    }

    tmp->data = data;

    if (*list)
    {
        cur = *list;
        for (int i = 0; i < pos; ++i, cur = cur->next)
            ;
        tmp->next = cur;
        tmp->prev = cur->prev;
        tmp->next->prev = tmp;
        tmp->prev->next = tmp;

        if (pos == 0)
        {
            *list = tmp;
        }
    }
    else
    {
        tmp->next = tmp;
        tmp->prev = tmp;
        *list = tmp;
    }
}

node_t *pop(node_t  *list, int pos)
{
    if (list == list->next)
    {
        free_data((data_t *)list->data);
        free(list);
        return NULL;
    }

    node_t *cur = list;
    node_t *next, *prev;

    for (int i = 0; i < pos; ++i, cur = cur->next)
        ;

    next = cur->next;
    prev = cur->prev;
    next->prev = cur->prev;
    prev->next = cur->next;
    
    free_data((data_t *)cur->data);
    free(cur);

    return pos ? list : next;
}

void free_list(node_t *list, int flag)
{
    if (list)
    {
        node_t *cur = list;
        node_t *start = list->prev;
        node_t *next = list->next;

        while (list && (list != start))
        {
            if (flag)
            {
                free_data((data_t *)cur->data);
            }
            else
            {
                free(cur->data);
            }
            free(cur);
            cur = next;
            next = cur->next;            
        }
    }
}

// data.c
data_t *create_data(char *name, int age, node_t *grad)
{
    data_t *data = malloc(sizeof(data_t));

    if (data)
    {
        data->name = name;
        data->age = age;
        data->grad = grad;
    }
    else
    {
        data = NULL;
    }
    
    return data;
}

data_t *input_data()
{
    char *name = malloc(BUFSIZ * sizeof(char));
    if (!name)
    {
        return NULL;
    }

    data_t *data = NULL;
    node_t *grad = NULL;
    int age;
    int cur;
    int count = 0;
    int *pgrad;

    if (fgets(name, BUFSIZ, stdin))
    {
        if (scanf("%d", &age))
        {
            while (scanf("%d ", &cur) == 1)
            {
                pgrad = malloc(sizeof(int));
                if (pgrad)
                {
                    *pgrad = cur;
                }
                push(&grad, (void *)pgrad, count);
                count++;
            }

            data = create_data(name, age, grad);
        }
        else
        {
            free(name);
        }
    }
    else
    {
        free(name);
    }

    return data;
}

void free_data(data_t *data)
{
    if (data)
    {
        if (data->name)
        {
            free(data->name);
        }
        free_list(data->grad, 0);
        free(data);
    }
}