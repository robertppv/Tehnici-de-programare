#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[100];
    float grad;

} STUDENT;

#define MAXARRAY 100

int cmp(const void *el1, const void *el2)
{
    const STUDENT *s1 = (const STUDENT *)el1;
    const STUDENT *s2 = (const STUDENT *)el2;

    if (s1->grad == s2->grad)
    {
        if (strcmp(s1->name, s2->name) > 0)
            return 1;
        else
            return -1;
    }
    if (s1->grad > s2->grad)
        return 1;
    if (s1->grad < s2->grad)
    {
        return -1;
    }
    return 0;
}

int test(int a)
{
    return a > 0;
}

void pb2(int *v, int *n, int (*test)(int))
{
    int nr = *n;
    for (int i = 0; i < nr; i++)
    {
        if (test(v[i]) == 0)
        {
            for (int j = i; j < nr; j++)
            {
                v[j] = v[j + 1];
            }
            i--;
            nr--;
        }
    }
    for (int i = 0; i < nr; i++)
    {
        printf("%d ", v[i]);
    }
}

int cmp2(const void *el1, const void *el2)
{
    const float *e1 = (const float *)el1;
    const float *e2 = (const float *)el2;
    if (*e1 > *e2)
        return 1;
    if (*e1 < *e2)
        return -1;
    return 0;
}

void pb3()
{
    int n, x;
    float v[MAXARRAY];
    printf("n:");
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%f", &v[i]);
    }
    qsort(v, n, sizeof(float), cmp2);
    printf("x:");
    scanf("%f", &x);

    int *rez = (int *)bsearch(&x, v, n, sizeof(float), cmp2);
    if (rez != NULL)
    {
        printf("Exista!");
    }
    else
    {
        printf("Nu exista!:(");
    }
}

double func(double a)
{
    return a+10;
}
void tabelare(int a, int b, int seg, double (*func)(double))
{
    int k = (b - a) / seg;
    int x = a;
    while (x <= b)
    {
        printf("f(%d)=%f\n", x, func(x));
        x += k;
    }
}


void tabelare2(int a ,int b,int p, double(*func)(double))
{
    for(int i=a;i<=b;i+=p)
    {
        printf("f(%d)=%f\n",i,func(i));
    }
}

void p1()
{
    int n = 3;
    STUDENT v[MAXARRAY] = {{"marian", 8.9}, {"laurentiu", 5.01}, {"stefanel", 10}};
    qsort(v, n, sizeof(STUDENT), cmp);

    for (int i = 0; i < n; i++)
    {
        printf("%s-----%f\n", v[i].name, v[i].grad);
    }
}

int main(void)
{
    int v[100] = {1, 2, 3, 4, 5, 6, -1, -1, -3, 5};
    int n = 10;
    tabelare(-10, 10, 20, func);
}