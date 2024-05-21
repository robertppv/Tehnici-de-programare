#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int cmmdc(int a, int b)
{
    if (b == 0)
        return a;
    else
        return cmmdc(b, a % b);
}
int max(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}
int suma_cifrelor(int n)
{
    if (n < 10)
        return n;
    else
        return n % 10 + suma_cifrelor(n / 10);
}

int ciframax(int n)
{
    if (n < 10)
        return n;
    else
        max(n % 10, ciframax(n / 10));
}

int fib(int n)
{
    if (n == 1 || n == 0)
        return 1;
    else
        return fib(n - 1) + fib(n - 2);
}

char *pb5(char *s1, char *s2, int n)
{
    if (n == 0)
        return s1;
    if (n == 1)
        return s2;
    if (n > 1)
    {
        char *r = malloc((strlen(s1) + strlen(s2) + 1) * sizeof(char));
        if (r == NULL)
            exit(EXIT_FAILURE);
        strcpy(r, s1);
        strcat(r, s2);
        return pb5(s2, r, n - 1);
    }
}

double phi(int n)
{
    if (n <= 1)
        return 1.0;
    else
    {
        return (double)fib(n) / fib(n - 1);
    }
}

double taylor(int x, int tol, int xn, int val, int n)
{

    if (xn < tol)
        return val;
    else
    {
        xn = xn * x / n;
        val = val + xn;
        return taylor(x, tol, xn, val, n + 1);
    }
}

int binarys(int *v, int st, int dr, int x)
{
    int mij = (st + dr) / 2;
    if (st > dr)
        return -1;
    if (v[mij] == x)
    {
        return mij;
    }
    if (v[mij] > x)
    {
        return binarys(v, st, mij - 1, x);
    }
    if (v[mij] < x)
    {
        return binarys(v, mij + 1, dr, x);
    }
}
int main(void)
{
}
