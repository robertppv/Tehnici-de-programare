#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int n, v[101], k;
int valid(int k)
{
    for (int i = 1; i < k; i++)
    {
        if (v[i] && v[i + 1])
            return 0;
    }
    return 1;
}
void afisare()
{
    for (int i = 1; i <= n; i++)
        printf("%d", v[i]);
    printf("\n");
}
void back(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        v[k] = i;
        if (valid(k))
        {
            if (k == n)
            {
                afisare();
            }
            else
            {
                back(k + 1);
            }
        }
    }
}

int main(void)
{
    n = 3;
    back(1);
}