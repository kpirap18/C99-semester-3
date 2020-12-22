#include <stdio.h>
#include <stdlib.h>

//error.h
#define OK 0
#define INPUTERR -1

//struct.h
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
int count(node_t *list);

// data.h
data_t *create_data(char *name, int age, node_t *grad);
data_t *input_data();
void free_data(data_t *data);


//io.c
int check_number()
{
    char num[16];
    fflush(stdin);
    if (fgets(num, 16, stdin) == NULL || num[0] == '\n')
        return -1;
    num[strlen(num) - 1] = '\0';

    return (int)atoi(num);
}
int print_menu()
{
    int command = -1;
    printf("MENU\n"
           "1 - Add\n"
           "2 - Delete\n"
           "3 - Print\n\n"
           "0 - Exit\n");
    printf("Your choice: \n");
    command = check_number();

    return command;
}
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
    fprintf(f, "\n");
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
    int c = count(list);
    if (list == list->next)
    {
        free_data((data_t *)list->data);
        free(list);
        list = NULL;
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
    cur = NULL;

    return (pos % c) ? list : next;
}

void free_list(node_t *list, int flag)
{
    if (list)
    {
        node_t *cur = list;
        node_t *start = list->prev;
        node_t *next = list->next;

        while (cur && (cur != start))
        {
            if (flag)
            {
                free_data((data_t *)cur->data);
                cur->data = NULL;
            }
            else
            {
                free(cur->data);
                cur->data = NULL;
            }
            free(cur);
            cur = NULL;
            cur = next;
            next = cur->next;            
        }
    }
}

int count(node_t *list)
{
    node_t *end = list->prev;
    int counter = 1;
    if (list->next == list)
        return 1;
    
    for (; list != end; list = list->next)
        counter++;
    
    return counter;
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

    char buf[16];
    data_t *data = NULL;
    node_t *grad = NULL;
    int age;
    int cur;
    int count = 0;
    int *pgrad;

    printf("\nInput name: \n");
    if (fgets(name, BUFSIZ, stdin))
    {
        name[strlen(name) - 1] = '\0';
        printf("Input age: \n");
        if (scanf("%d", &age))
        {
            printf("Input grad (1 1 1 f): \n");
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
            fgets(buf, 16, stdin);

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
            data->name = NULL;
        }
        free_list(data->grad, 0);
        free(data);
        data = NULL;
    }
}

int main()
{
    setbuf(stdout, NULL);
    
    node_t *list = NULL;
    char buf[16];
    int command = -1;

    while (command = print_menu())
    {
        switch (command)
        {
        case 1:
            fflush(stdin);
            int pos = 0;
            printf("Input index of added elem: ");
            if (scanf("%d", &pos) == 1)
            {
                getchar();
                push(&list, (void *)input_data(), pos);
            }
            else
            {
                fgets(buf, 16, stdin);
                printf("Input invalid number!\n");
            }
            
            break;
        case 2:
            if (list)
            {
                int pos = 0;
                printf("Input index o delete element: ");
                if (scanf("%d", &pos) == 1)
                {
                    getchar();
                    list = pop(list, pos);
                }
                else
                {
                    fgets(buf, 16, stdin);
                    printf("Input invalid number!\n");
                }
            }
            else
            {
                printf("List is empty\n");
            }
            break;
        case 3:
            if (list)
            {
                print_list(stdout, list, 1);
            }
            else
            {
                printf("List is empty\n");
            }
            
            break;
        default:
        printf("SOme error!\n");
            break;
        }
    }
}





// int comparator_age(const void *p, const void *q)
// {
//     const data_t *a = p;
//     const data_t *b = q;
//     return a->age - b->age;
// }

// int comparator_int(const void *p, const void *q)
// {
//     const int *a = p;
//     const int *b = q;
//     return *a - *b;
// }
// void front_back_split(node_t *head, node_t **back)
// {
//     node_t *cur = head;
//     node_t *end = head->prev;
//     if (head->next == head)
//     {
//         return;
//     }

//     node_t *b = head;

//     while (cur->next != end && cur->next->next != end)
//     {
//         b = b->next;
//         cur = cur->next->next;
//     }

//     *back = b->next;
//     (*back)->prev = end;
//     end->next = *back;

//     b->next = head;
//     head->prev = b;
// }

// node_t *sorted_merge(node_t **head_a, node_t **head_b, int (*comparator)(const void *, const void *))
// {
//     node_t *enda = (*head_a)->prev;
//     node_t *endb = (*head_b)->prev;
//     if (!head_a || !head_b)
//     {
//         return NULL;
//     }
	
//     if (comparator == NULL)
//     {
//         return NULL;
//     }

//     node_t *a = *head_a;
//     node_t *b = *head_b;
//     node_t *head = NULL;
//     node_t *c = NULL;

//     if (a || b)
//     {
//         if ((b == endb) || (a != enda && comparator(a->data, b->data) < 0))
//         {
//             head = a;
//             c = head;
//             a = a->next;
//         }
//         else if (b)
//         {
//             head = b;
//             c = head;
//             b = b->next;
//         }
//     }

//     while (a != enda && b != endb)
//     {
//         if (comparator(a->data, b->data) < 0)
//         {
//             c->next = a;
//             c = c->next;
//             a = a->next;
//         }
//         else
//         {
//             c->next = b;
//             c = c->next;
//             b = b->next;
//         }
//     }

//     while (a != enda)
//     {
//         c->next = a;
//         c = c->next;
//         a = a->next;
//     }

//     while (b != endb)
//     {
//         c->next = b;
//         c = c->next;
//         b = b->next;
//     }

//     a = NULL;
//     b = NULL;
//     c = NULL;
//     *head_a = NULL;
//     *head_b = NULL;

//     return head;
// }

// node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
// {
//     if (head->next == head)
//     {
//         return head;
//     }

//     if (!comparator)
//     {
//         return NULL;
//     }

//     node_t *a = NULL;
//     node_t *b = NULL;
//     node_t *back = NULL;
//     node_t *new_head = NULL;

//     front_back_split(head, &back);
//     a = sort(head, comparator);
//     b = sort(back, comparator);

//     new_head = sorted_merge(&a, &b, comparator);

//     return new_head;
// }