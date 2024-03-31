#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

int **allocDyn(int n, int m)
{
    int **matrix = NULL;

    if ((matrix = malloc(m * sizeof(int *))) == NULL)
    {
        printf("memorie insuficienta\n");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < m; i++)
    {
        if ((matrix[i] = malloc(n * sizeof(int))) == NULL)
        {
            for (int j = i--; i >= 0; i--)
                free(matrix[j]);
            free(matrix);
            printf("memorie insuficienta\n");
            exit(EXIT_FAILURE);
        }
    }

    return matrix;
}
void pb1(int **matrix, int n, int m)
{
    int count = 1;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            matrix[i][j] = count++;
}
void afis(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%3d", matrix[i][j]);
        printf("\n");
    }
}

void readMatrix(int **matrix, int n, int m)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &matrix[i][j]);
}

void pb2(int **matrix, int n)
{
    int aux = 0;
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
        {
            aux = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = aux;
        }
}

int *allocDynArr(int n)
{
    int *a = NULL;
    if ((a = malloc(n * sizeof(int))) == 0)
    {
        perror("mem insud");
        exit(EXIT_FAILURE);
    }
    return a;
}
int *getSumRow(int **matrix, int n)
{
    int *a = NULL;
    a = allocDynArr(n);
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += matrix[i][j];
        a[i] = sum;
    }
    return a;
}

int *getSumCol(int **matrix, int n)
{
    int *a = NULL;
    a = allocDynArr(n);
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
            sum += matrix[j][i];
        a[i] = sum;
    }
    return a;
}
void afisArr(int *v, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", v[i]);
    }
}
void freeMatrix(int **matrix, int n)
{
    for (int i = 0; i < n; i++)
        free(matrix[i]);
    free(matrix);
}
void pb3()
{
    int n;
    int **matrix = NULL;
    int *sumRow = NULL, *sumCol = NULL;
    scanf("%d", &n);
    matrix = allocDyn(n, n);
    readMatrix(matrix, n, n);
    sumRow = getSumRow(matrix, n);
    sumCol = getSumCol(matrix, n);
    afis(matrix, n, n);
    afisArr(sumRow, n);
    printf("\n");
    afisArr(sumCol, n);
    freeMatrix(matrix, n);
}

void pb4()
{
    int n, a = 0;
    int **friends = NULL;
    scanf("%d", &n);
    friends = allocDyn(n, n);
    // friends=memset(friends,0,n*sizeof(int));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            friends[i][j] = 0;
        }
    for (int i = 0; i < n; i++)
    {
        while (scanf("%d", &a))
        {
            if (!(a >= 0 && a <= n - 1))
            {
                break;
            }
            friends[i][a] = 1;
            friends[a][i] = 1;
        }
    }

    afis(friends, n, n);
    for (int i = 0; i < n; i++)
    {
        int nrprieteni = 0;
        for (int j = 0; j < n; j++)
            nrprieteni += friends[i][j];
        printf("%d:%d", i, nrprieteni);
        printf("\n");
    }

    freeMatrix(friends, n);
}
void pb5()
{
    int nrTowns = 0;
    scanf("%d", &nrTowns);
    int min1 = 999999999, t1, t2;
    int **distance = NULL;
    distance = allocDyn(nrTowns, nrTowns);
    for (int i = 0; i < nrTowns; i++)
    {
        for (int j = i + 1; j < nrTowns; j++)
        {
            printf("%d-%d", i, j);
            scanf("%d", &distance[i][j]);
            if (distance[i][j] != 0 && distance[i][j] < min1)
            {
                min1 = distance[i][j];
                t1 = i;
                t2 = j;
            }
        }
    }
    printf("%d-%d:%d", t1, t2, min1);
}
void pb6()
{
    int m = 2, n = 2, p = 2;
    int **a = NULL, **b = NULL, **c = NULL;
    a = allocDyn(m, n);
    b = allocDyn(n, p);
    c = allocDyn(m, p);

    printf("a:");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);

    printf("b:");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            scanf("%d", &b[i][j]);

    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int z = 0; z < p; z++)
            for (int q = 0; q < n; q++)
                sum += a[i][z] * b[z][i];
        printf("%d ", sum);
    }
    printf("\n");
    afis(a, m, n);
    afis(b, n, p);
    afis(c, m, p);
}

void pb7()
{
    int n;
    scanf("%d", &n);
    int **m = NULL;
    m = allocDyn(n, n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j)
                m[i][j] = 1;
            else
                m[i][j] = 0;
        }
    }

    afis(m, n, n);
}

void pb8()
{
    int n, ok = 1;
    scanf("%d", &n);
    int **m = NULL;
    m = allocDyn(n, 4);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        ok = 1;
        int el_cur = m[i][0];
        for (int j = 1; j < 4; j++)
        {
            if (el_cur >= m[i][j])
            {
                ok = 0;
                break;
            }
        }
        if (ok)
            printf("%d ", i);
    }
}

void pb10()
{
    int n;
    scanf("%d", &n);
    getchar();
    char a;
    char m[10][10], cuv[10];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            while ((a = getchar()))
            {
                if (strchr(" \n ", a) == NULL)
                {
                    m[i][j] = a;
                    break;
                }
            }

            m[i][j] = a;
        }
    }
    scanf("%9s", cuv);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int ok = 1;
            if (m[i][j] == cuv[0])
            {
                ok = 1;
                if (j + strlen(cuv) - 1 < n)
                {
                    for (int i2 = 1; i2 < strlen(cuv); i2++)
                    {
                        if (cuv[i2] != m[i][j + i2])
                        {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok)
                    {
                        printf("De la linia %d coloana %d spre drepta.\n", i, j);
                    }
                }
                ok = 1;
                if (j >= strlen(cuv) - 1)
                {
                    for (int i2 = 1; i2 < strlen(cuv); i2++)
                    {
                        if (cuv[strlen(cuv) - 1 - i2] != m[i][j - i2])
                        {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok)
                    {
                        printf("De la linia %d coloana %d spre stanga.\n", i, j);
                    }
                }
                ok = 1;

                if (i + strlen(cuv) - 1 < n)
                {
                    for (int i2 = 1; i2 < strlen(cuv); i2++)
                    {
                        if (cuv[i2] != m[i + i2][j])
                        {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok)
                    {
                        printf("De la linia %d coloana %d in jos.\n", i, j);
                    }
                }
                ok = 1;
                if (i >= strlen(cuv) - 1)
                {
                    for (int i2 = 1; i2 < strlen(cuv); i++)
                    {
                        if (cuv[i2] != m[i - i2][j])
                        {
                            ok = 0;
                            break;
                        }
                    }
                    if (ok)
                    {
                        printf("De la linia %d coloana %d in sus.", i, j);
                    }
                }
            }
        }
    }
}
void pb9()
{
    int n = 5, m = 3, ok = 1;
    int **a = NULL;
    int **b = NULL;
    a = allocDyn(n, n);
    b = allocDyn(m, m);
    readMatrix(a, n, n);
    readMatrix(b, m, m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            ok = 1;
            if (j + m <= n && i + m <= n && b[0][0] == a[i][j])
            {

                for (int i2 = 0; i2 < m && ok; i2++)
                {
                    for (int j2 = 0; j2 < m && ok; j2++)
                    {
                        if (b[i2][j2] != a[i + i2][j + j2])
                        {
                            ok = 0;
                        }
                    }
                }

                if (ok == 1)
                {
                    printf("(%d,%d)", i, j);
                }
            }
        }
    }
}

int main(void)
{
}
