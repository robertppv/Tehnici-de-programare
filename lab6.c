#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

void err(const int cond, const char *fmt, ...)
{
    if (cond)
    {
        va_list va;
        va_start(va, fmt);
        fprintf(stderr, "eroare: ");
        vfprintf(stderr, fmt, va);
        va_end(va);
        fputc('\n', stderr);
        exit(EXIT_FAILURE);
    }
}
void pb1()
{
    int i, n;
    float x, y, e, min, max;
    printf("n=");
    scanf("%d", &n);
    err(n <= 0 || n > 100, "n invalid: %d\n", n);
    printf("x=");
    scanf("%g", &x);
    printf("y=");
    scanf("%g", &y);
    err(x >= y, "x=%g nu este mai mic decat y=%g\n", x, y);
    max = x;
    min = y;
    for (i = 0; i < n; i++)
    {
        printf("e=");
        scanf("%g", &e);
        err(e < x || e > y, "element invalid: %g\n", e);
        if (e < min)
            min = e;
        if (e > max)
            max = e;
    }
    printf("min: %g, max: %g\n", min, max);
}

float *allocVec(int n, ...)
{
    va_list va;
    va_start(va, n);
    float *vec = NULL;

    if ((vec = malloc(n * sizeof(float))) == NULL)
    {
        perror("mem err");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
    {
        vec[i] = va_arg(va, double);
    }
    va_end(va);
    return vec;
}

void absN(int n, ...)
{
    va_list va;
    va_start(va, n);
    double *aux;
    for (int i = 0; i < n; i++)
    {
        aux = va_arg(va, double *);
        if (*aux < 0)
            *aux *= -1;
    }
    va_end(va);
}

int crescator(int n, char tip, ...)
{
    va_list va;
    va_start(va, tip);
    int aux1, aux2;
    int ok = 1;
    double auxd1, auxd2;
    if (tip == 'd')
    {
        aux1 = va_arg(va, int);
    }
    else
    {
        auxd1 = va_arg(va, double);
    }
    for (int i = 1; i < n; i++)
    {
        if (tip == 'd')
        {
            aux2 = va_arg(va, int);
            if (aux1 > aux2)
            {
                ok = 0;
                break;
            }
            aux1 = aux2;
        }
        else
        {
            auxd2 = va_arg(va, double);
            if (auxd1 > auxd2)
            {
                ok = 0;
                break;
            }
            auxd1 = auxd2;
        }
    }

    return ok;
}

int main()
{
    return 0;
}