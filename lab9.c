#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
    int n;
    struct elem *urm;
} elem;

elem *permutari(elem *lista, int perm)
{
    elem *p = NULL, *q = NULL;
    for (int i = 0; i < perm; i++)
    {
        for (p = lista; p->urm != NULL; p = p->urm)
            ;
        q = lista->urm;
        p->urm = lista;
        lista->urm = NULL;
        lista = q;
    }
    return lista;
}

elem *nodnou(int n, elem *urm)
{
    elem *p = NULL;
    if ((p = malloc(sizeof(elem))) == NULL)
        perror("err");
    p->n = n;
    p->urm = urm;
    return p;
}
elem *adsf(elem *lista, int n)
{
    elem *nou = nodnou(n, NULL);
    elem *p = NULL;
    if (lista == NULL)
        lista = nou;
    else
    {
        for (p = lista; p->urm != NULL; p = p->urm)
            ;
        p->urm = nou;
    }
    return lista;
}

void afis(elem *lista)
{
    for (elem *p = lista; p != NULL; p = p->urm)
    {
        printf("%d ", p->n);
    }
    printf("\n");
}

void pb1()
{
    FILE *filein, *fileout;
    elem *lista = NULL;
    elem *p = NULL;
    int k, n;
    if ((filein = fopen("date.in", "r")) == NULL)
    {
        perror("mem err");
        exit(EXIT_FAILURE);
    }

    if ((fileout = fopen("date.out", "w")) == NULL)
    {
        perror("mem err");
        exit(EXIT_FAILURE);
    }

    fscanf(filein, "%d", &k);

    while (fscanf(filein, "%d", &n) == 1)
    {
        lista = adsf(lista, n);
    }

    lista = permutari(lista, k);

    for (p = lista; p != NULL; p = p->urm)
    {
        fprintf(fileout, "%d ", p->n);
    }

    if (fclose(filein) != 0)
    {
        perror("mem err");
        exit(EXIT_FAILURE);
    }

    if (fclose(fileout) != 0)
    {
        perror("mem err");
        exit(EXIT_FAILURE);
    }
}
void pb2()
{
    FILE *filein;
    elem *par = NULL, *impar = NULL, *p = NULL;
    int n;
    if ((filein = fopen("date.in", "r")) == NULL)
    {
        perror("mem err");
        exit(EXIT_FAILURE);
    }

    while (fscanf(filein, "%d", &n) == 1)
    {
        if (n % 2 == 0)
            par = adsf(par, n);
        else
            impar = adsf(impar, n);
    }

    for (p = par; p->urm != NULL; p = p->urm)
        ;
    p->urm = impar;

    afis(par);
    if (fclose(filein) != 0)
    {
        perror("mem err");
        exit(EXIT_FAILURE);
    }
}
elem *insp(elem *lista)
{
    elem *p = NULL;
    elem *nou = NULL;
    for (p = lista; p != NULL; p->urm)
    {
        if (p->n % 2 == 0)
        {
            
        }
    }
}
int main(void)
{
    pb2();
}