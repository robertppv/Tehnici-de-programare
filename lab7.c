#include <stdio.h>
#include <stdlib.h>

typedef struct elem
{
    int info;
    struct elem *urm;
} elem;

void afisare(elem *lista)
{
    elem *p = NULL;
    for (p = lista; p != NULL; p = p->urm)
    {
        printf("%d ", p->info);
    }
    printf("\n");
}

elem *nod_nou(int n, elem *urm)
{
    elem *p = NULL;
    if ((p = malloc(sizeof(elem))) == NULL)
    {
        perror("mem err");
        exit(EXIT_FAILURE);
    }
    p->info = n;
    p->urm = urm;
    return p;
}

elem *adaugaInceput(elem *lista, int n)
{
    elem *p = NULL;
    p = nod_nou(n, lista);
    lista = p;
    return lista;
}

elem *adaugaSfarsit(elem *lista, int n)
{
    elem *p = NULL, *q;
    p = nod_nou(n, NULL);
    if (lista == NULL)
    {
        lista = p;
    }
    else
    {
        for (q = lista; q->urm != NULL; q = q->urm)
            ;
        q->urm = p;
    }
    return lista;
}

elem *stergeInceput(elem *lista)
{
    elem *p = NULL;
    if (lista == NULL)
        return lista;
    p = lista;
    lista = lista->urm;
    free(p);
    return lista;
}

elem *stergeSfarsit(elem *lista)
{
    elem *p = NULL, *q = NULL;
    if (lista == NULL)
        return lista;
    if (lista->urm == NULL)
    {
        free(lista);
        lista = NULL;
        return lista;
    }
    for (p = lista; p->urm->urm != NULL; p = p->urm)
        ;
    q = p->urm;
    p->urm = NULL;
    free(q);
    return lista;
}

elem *stergeElement(elem *lista, int n)
{
    elem *p = NULL, *prev = NULL;
    if (lista == NULL)
        return lista;
    if (lista->info == n)
    {
        p = lista;
        lista = lista->urm;
        free(p);
    }
    else
    {
        for (prev = lista, p = lista->urm; p != NULL; prev = prev->urm, p = p->urm)
        {
            if (p->info = n)
            {
                prev->urm = p->urm;
                free(p);
                break;
            }
        }
        return lista;
    }
}

int pb1(elem *list1, elem *list2)
{
    if (list1 == NULL && list2 == NULL)
        return 1;
    if (list1 == NULL || list2 == NULL)
        return 0;
    while (list1 != NULL || list2 != NULL)
    {
        if (list1 == NULL || list2 == NULL)
        {
            return 0;
        }

        if (list1->info != list2->info)
        {
            return 0;
        }

        list1 = list1->urm;
        list2 = list2->urm;
    }
    return 1;
}

int cautare(elem *list, int n)
{
    for (elem *p = list; p != NULL; p = p->urm)
    {
        if (p->info == n)
            return 1;
    }
    return 0;
}

elem *pb3(elem *list1, elem *list2)
{
    elem *newlist = NULL, *p = NULL;
    for (p = list1; p != NULL; p = p->urm)
    {
        if (cautare(newlist, p->info) == 0)
        {
            newlist = adaugaSfarsit(newlist, p->info);
        }
    }
    for (p = list2; p != NULL; p = p->urm)
    {
        if (cautare(newlist, p->info) == 0)
        {
            newlist = adaugaSfarsit(newlist, p->info);
        }
    }
    return newlist;
}

int egal(elem *list1, elem *list2)
{
    elem *p = NULL;

    for (p = list1; p != NULL; p = p->urm)
    {
        if (cautare(list2, p->info) == 0)
            return 0;
    }
    for (p = list2; p != NULL; p = p->urm)
    {
        if (cautare(list1, p->info) == 0)
            return 0;
    }
    return 1;
}
int main(void)
{
    elem *lista = NULL;
    elem *lista2 = NULL;
    lista = adaugaInceput(lista, 7);
    lista = adaugaInceput(lista, 8);
    lista = adaugaInceput(lista, 9);
    lista = adaugaInceput(lista, 9);
    lista2 = adaugaInceput(lista2, 7);
    lista2 = adaugaInceput(lista2, 7);
    lista2 = adaugaInceput(lista2, 8);
    lista2 = adaugaInceput(lista2, 9);
    lista2 = adaugaInceput(lista2, 9);
    printf("%d", egal(lista, lista2));
}