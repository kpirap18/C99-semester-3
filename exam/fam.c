/*
c C99
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s
{
    int n;
    double d[];
};

struct s* create_s(int n, const double *d)
{
    assert(n >= 0);

    struct s *elem = malloc(sizeof(struct s) + n * sizeof(double));
    /*
    // Чтобы успокоить valgrind
    struct s *elem = calloc(sizeof(struct s) + n * sizeof(double), 1);
    */

    if (elem)
    {
        elem->n = n;
        memmove(elem->d, d, n * sizeof(double));
    }

    return elem;
}

int save_s(FILE *f, const struct s *elem)
{
    int size = sizeof(*elem) + elem->n * sizeof(double);
    int rc = fwrite(elem, 1, size, f);

    if (size != rc)
        return 1;

    return 0;
}

struct s* read_s(FILE *f)
{
    struct s part_s;
    struct s *elem;
    int size;

    size = fread(&part_s, 1, sizeof(part_s), f);
    if (size != sizeof(part_s))
        return NULL;

    elem = malloc(sizeof(part_s) + part_s.n * sizeof(double));
    /*
    // Чтобы успокоить valgrind
    elem = calloc(sizeof(part_s) + part_s.n * sizeof(double), 1);
    */
    if (!elem)
        return NULL;

    memmove(elem, &part_s, sizeof(part_s));

    size = fread(elem->d, sizeof(double), elem->n, f);
    if (size != elem->n)
    {
        free(elem);

        return NULL;
    }

    return elem;
}

void print_s(const struct s *elem)
{
    printf("n = %d\n", elem->n);

    for (int i = 0; i < elem->n; i++)
        printf("%4.2f ", elem->d[i]);

    printf("\n\n");
}


int main(void)
{
    double a[] = {1, 2, 3, 4, 5};

    struct s *elem_1 = create_s(3, a);
    struct s *elem_2 = create_s(1, a);
    struct s *elem_3 = create_s(0, a);
    struct s *elem_4 = create_s(5, a);
    struct s *elem;
    FILE *f;

    printf("sizeof(struct s) %d\n\n", (int) sizeof(struct s));

    f = fopen("test.dat", "wb");

    save_s(f, elem_1);
    save_s(f, elem_2);
    save_s(f, elem_3);
    save_s(f, elem_4);

    fclose(f);

    f = fopen("test.dat", "rb");

    while(!feof(f))
    {
        elem = read_s(f);

        if (elem)
        {
            print_s(elem);

            free(elem);
        }
    }

    fclose(f);

    free(elem_4);
    free(elem_3);
    free(elem_2);
    free(elem_1);

    return 0;
}


/*
до C99
*/

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct s
{
    int n;
    double d[1];
};


void print_s(const struct s *elem)
{
    printf("n = %d\n", elem->n);

    for (int i = 0; i < elem->n; i++)
        printf("%4.2f ", elem->d[i]);

    printf("\n\n");
}


struct s* create_s(int n, const double *d)
{
    assert(n >= 0);

    struct s *elem = calloc(sizeof(struct s) + (n > 1 ? (n - 1) * sizeof(double) : 0), 1);

    if (elem)
    {
        elem->n = n;
        memmove(elem->d, d, n * sizeof(double));
    }

    return elem;
}

int save_s(FILE *f, const struct s *elem)
{
    int size = sizeof(*elem) + (elem->n > 1 ? (elem->n - 1) * sizeof(double) : 0);
    int rc = fwrite(elem, 1, size, f);

    if (size != rc)
        return 1;

    return 0;
}

struct s* read_s(FILE *f)
{
    struct s part_s;
    struct s *elem;
    int size;

    size = fread(&part_s, 1, sizeof(part_s), f);
    if (size != sizeof(part_s))
        return NULL;

    elem = calloc(sizeof(part_s) + (part_s.n > 1 ? (part_s.n - 1) * sizeof(double) : 0), 1);
    if (!elem)
        return NULL;

    memmove(elem, &part_s, sizeof(part_s));

    if (elem->n > 1)
    {
        size = fread(elem->d + 1, sizeof(double), elem->n - 1, f);
        if (size != elem->n - 1)
        {
            free(elem);

            return NULL;
        }
    }

    return elem;
}

int main(void)
{
    double a[] = {1, 2, 3, 4, 5};

    struct s *elem_1 = create_s(3, a);
    struct s *elem_2 = create_s(1, a);
    struct s *elem_3 = create_s(0, a);
    struct s *elem_4 = create_s(5, a);
    struct s *elem;
    FILE *f;

    printf("sizeof(struct s) %d\n\n", (int) sizeof(struct s));

    f = fopen("test.dat", "wb");

    save_s(f, elem_1);
    save_s(f, elem_2);
    save_s(f, elem_3);
    save_s(f, elem_4);

    fclose(f);

    f = fopen("test.dat", "rb");

    while(!feof(f))
    {
        elem = read_s(f);

        if (elem)
        {
            print_s(elem);

            free(elem);
        }
    }

    fclose(f);

    free(elem_4);
    free(elem_3);
    free(elem_2);
    free(elem_1);

    return 0;
}
