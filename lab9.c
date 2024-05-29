#include <stdlib.h>
#include <stdio.h>

typedef struct elem
{
    int n;
    struct elem *urm;
} elem;

typedef struct nod
{
    int n;
    struct nod *urm;
    struct nod *prev;
} nod;

nod *nod_nou(int n)
{
    nod *p = NULL;
    if ((p = malloc(sizeof(nod))) == NULL)
        perror("dd");
    p->n = n;
    p->prev = NULL;
    p->urm = NULL;
    return p;
}
nod *addsf(nod *lista, int n)
{
    nod *p = NULL;
    nod *nou = nod_nou(n);
    nou->urm = NULL;
    if (lista == NULL)
    {
        nou->prev = NULL;
        lista = nou;
    }
    else
    {
        for (p = lista; p->urm != NULL; p = p->urm)
            ;
        nou->prev = p;
        p->urm = nou;
    }
    return lista;
}
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
void afis2(nod *lista)
{
    for (nod *p = lista; p != NULL; p = p->urm)
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
elem *pb3(elem *lista)
{
    elem *p = NULL;
    elem *nou = NULL;
    for (p = lista; p != NULL; p = p->urm)
    {
        if ((p->n) % 2 == 0)
        {
            nou = nodnou((p->n) / 2, p->urm);
            p->urm = nou;
            p = p->urm;
        }
    }
    return lista;
}

nod *pb4(nod *lista)
{
    int ok = 1;
    nod *p = NULL, *aux = NULL;
    if (lista == NULL)
        return lista;
    else
    {
        p = lista;
        aux = p->urm;
        p->urm = aux->urm;
        if (aux->urm != NULL)
            aux->urm->prev = p;
        aux->prev = NULL;
        aux->urm = p;
        p->prev = aux;
        lista = aux;

        for (p = lista->urm->urm; p->urm != NULL; p = p->urm)
        {
            afis2(lista);
            printf("?%d?\n", p->n);
            aux = p->urm;

            p->prev->urm = aux;
            aux->prev = p->prev;
            p->urm = aux->urm;
            aux->urm = p;
            if (aux->urm != NULL)
                aux->urm->prev = p;

            p->prev = aux;
            printf("?%d?\n", p->n);
            afis2(lista);
            if (p->urm == NULL)
                break;
        }
        return lista;
    }
}

nod *pb5(nod *lista)
{
    nod *p = lista;
    lista = p->urm;
    lista->prev = NULL;
    free(p);
    for (p = lista; p->urm != NULL; p = p->urm)
        ;
    p->prev->urm = NULL;
    free(p);
    return lista;
}

nod *pb6(nod *lista)
{
    nod *ultim = NULL, *p = NULL;
    for (ultim = lista; ultim->urm != NULL; ultim = ultim->urm)
        ;
    ultim->prev->urm = NULL;

    p = lista;

    p->urm->prev = ultim;
    ultim->urm = p->urm;
    ultim->prev = p;
    p->urm = ultim;
    return lista;
}
int palin(nod *lista)
{
    nod *prim = NULL, *ultim = NULL;
    int k = 1, k2 = 1;
    for (ultim = lista; ultim->urm != NULL; ultim = ultim->urm, k++)
        ;
    prim = lista;
    while (k2 <= k / 2)
    {
        if (prim->n != ultim->n)
            return 0;
        prim = prim->urm;
        ultim = ultim->prev;
        k2++;
    }
    return 1;
}

nod *pb8(nod *lista)
{
    nod *ultim = NULL, *prim = NULL;
    for (ultim = lista; ultim->urm != NULL; ultim = ultim->urm)
        ;
    prim = lista;

    lista = prim->urm;
    lista->prev = NULL;
    prim->prev = ultim;
    prim->urm = NULL;
    ultim->urm = prim;
    return lista;
}

elem *stpar(elem *lista)
{
    if (lista == NULL)
        return NULL;
    if (lista.n % 2 == 0)
    {
        elem *p = lista->urm;
        free(lista);
        lista = p;
    }
    for (elem *p = lista; p->urm != NULL; p = p->urm)
    {
        if (p->n % 2 == 0)
        {
            if(lista==p)
            {
                lista=p->urm;

            }
        }
    }
}
int main(void)
{
    elem *lista = NULL;
    lista = adsf(lista, 1);
    lista = adsf(lista, 2);
    lista = adsf(lista, 3);
    lista = adsf(lista, 4);
    lista = adsf(lista, 5);
    lista = adsf(lista, 6);
    lista = adsf(lista, 7);

    afis(lista);
}
