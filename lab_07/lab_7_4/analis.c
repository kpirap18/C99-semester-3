#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>

#define OK 0
#define ERR -1
#define N_mas 10000
#define N_povt 10000

int compare(const void *x1, const void *x2)
{
    const int *a = x1;
    const int *b = x2;
    return *a - *b;
}
void swap(void *first, void *second, size_t size)
{
    char t;
    char *a = (char*)first;
    char *b = (char*)second;

    do
    {
        t = *a;
        *a++ = *b;
        *b++ = t;
    }while (--size > 0);
}
void mysort(void *const first, size_t number, size_t size, int (*func_cmp)(const void *, const void *))
{
    char *pb = first;
    char *pe = (char *)first + (number - 1) * size;

    int flag = 1;

    while ((pb < pe) && flag > 0)
    {
        flag = 0;
        for (char *i = pb; i < pe; i += size)
        {
            if (func_cmp(i, i + size) > 0)
            {
                swap(i, i + size, size);
                flag = 1;
            }
        }
        pe -= size;

        for (char *i = pe; i > pb; i -= size)
        {
            if (func_cmp(i - size, i) > 0)
            {
                swap(i - size, i, size);
                flag = 1;
            }
        }
        pb += size;
    }
}

void random_arr(int *a)
{
    for (int i = 0; i < N_mas; i++)
        a[i] = -100 + rand() % 100;
}

int64_t find_time0(int *a, int n)
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time, common_time, sum;
    sum = 0;
    for (int i = 0; i < N_povt; i++)
    {
        gettimeofday(&tv_start, NULL);
        mysort(a, n, sizeof(int), compare);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +\
        (tv_stop.tv_usec - tv_start.tv_usec);
        sum += elapsed_time;
    }
    common_time = (int) sum / N_povt;
    return common_time;
}


int64_t find_time1(int *a, int n)
{
    struct timeval tv_start, tv_stop;
    int64_t elapsed_time, common_time, sum;
    sum = 0;
    for (int i = 0; i < N_povt; i++)
    {
        gettimeofday(&tv_start, NULL);
        qsort(a, n, sizeof(int), compare);
        gettimeofday(&tv_stop, NULL);
        elapsed_time = (tv_stop.tv_sec - tv_start.tv_sec) * 1000000LL +\
        (tv_stop.tv_usec - tv_start.tv_usec);
        sum += elapsed_time;
    }
    common_time = (int) sum / N_povt;
    return common_time;
}


int main()
{
    int64_t time_0, time_1;
    int a[N_mas];

    random_arr(a);

	for (int i = 100; i < N_mas / 100; i += 100)
	{
		time_0 = find_time0(a, i);
		printf("%d", (int)time_0);
	}
	
	for (int i = 100; i < N_mas / 100; i += 100)
	{
		time_1 = find_time1(a, i);
		printf("%d", (int)time_1);
	}
    /*printf("Working with pointers: %I64u \n", time_0);
    time_1 = find_time1(a);
    printf("Using a[i]: %I64u \n", time_1);
    time_2 = find_time2(a);
    printf("Using *(a + i): %I64u \n", time_2);*/
}

