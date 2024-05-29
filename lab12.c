#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// int v[101], n = 3, x[101], kr;

// int valid(int k)
// {
//     if (v[1] == 0)
//         return 0;
//     return 1;
// }

// int solutie(int k)
// {
//     int sum = 0;
//     for (int i = 1; i <= k; i++)
//     {
//         if (v[i] == 1)
//             sum++;
//     }
//     return (k == n && sum == kr);
// }
// void back(int k)
// {
//     if (k == n + 1)
//     {
//         return;
//     }
//     for (int i = 0; i <= 9; i++)
//     {
//         v[k] = i;
//         if (valid(k))
//         {
//             if (solutie(k))
//                 afisare();
//             else
//                 back(k + 1);
//         }
//     }
// }
// void p1()
// {
//     scanf("%d", &n);
//     scanf("%d", &kr);

//     back(1);
// }

// int v[100];
// int valid2(int k, int n)
// {
//     for (int i = 1; i < k; i++)
//         if (v[i] == v[k])
//             return 0;

//     int mij = (k + 1) / 2;
//     for (int i = 1; i < mij; i++)
//         if (v[i] < v[i + 1])
//             return 0;

//     if (k == n)
//     {
//         for (int i = mij; i < k; i++)
//             if (v[i] > v[i + 1])
//                 return 0;
//     }

//     return 1;
// }
// void afisare(int n)
// {
//     for (int i = 1; i <= n; i++)
//         printf("%d", v[i]);
//     printf("\n");
// }
// void back2(int k, int n)
// {
//     for (int i = 1; i <= n; i++)
//     {
//         v[k] = i;
//         if (valid2(k, n))
//         {
//             if (k == n)
//             {
//                 afisare(n);
//             }
//             else
//             {
//                 back2(k + 1, n);
//             }
//         }
//     }
// }

// char cul[10][10] = {"alb", "galben", "rosu", "verde", "albastru", "negru"};
// int v[100];
// int valid4(int k)
// {
//     for (int i = 0; i < k; i++)
//     {
//         if (v[i] == v[k])
//             return 0;
//     }
//     if (k > 0)
//     {
//         if (v[1] == 1 || v[1] == 3)
//             return 1;
//         else
//             return 0;
//     }
//     return 1;
// }
// void afisare4()
// {
//     for (int i = 0; i < 3; i++)
//         printf("%s ", cul[v[i]]);
//     printf("\n");
// }
// void back4(int k)
// {
//     for (int i = 0; i < 6; i++)
//     {
//         v[k] = i;
//         if (valid4(k))
//         {
//             if (k == 2)
//                 afisare4();
//             else
//                 back4(k + 1);
//         }
//     }
// }

int v8[101];
int valid8(int k, int n, int d)
{

    for (int i = 1; i < k; i++)
        if (v8[i] >= v8[i + 1])
            return 0;
    if (k == n)
    {
        int sum = 0;
        for (int i = 1; i <= n; i++)
        {
            sum = sum + v8[i];
        }
    

        if (sum == d)
            return 1;
        else
            return 0;
    }
}
void afisare8(int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d ", v8[i]);
    printf("\n");
}

int solutie(int k, int n, int d)
{
    int sum = 0;
    if (k < n)
        return 0;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            sum = sum + v8[i];
        }
        printf("%d==%d\n", sum, d);

        // if (sum == d)
        //     return 1;
        // else
        // return 0;
    }
}
void back8(int k, int n, int d)
{
    for (int i = 1; i <= d; i++)
    {
        v8[k] = i;
        if (valid8(k, n, d))
        {
            if (k == n)
                afisare8(n);
            else
                back8(k + 1, n, d);
        }
    }
}
int main(void)
{
    back8(1, 2, 100);
}