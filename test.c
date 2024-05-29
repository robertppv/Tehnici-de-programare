#include <stdio.h>
#include <stdlib.h>
typedef struct nod
{
    int n;
    struct nod *urm;
} nod;

nod *nod_nou(int n, nod *urm)
{
    nod *p = NULL;
    if ((p = malloc(sizeof(nod))) == NULL)
    {
        perror("err");
    }
    p->n = n;
    p->urm = urm;
    return p;
}
nod *adauga_inc(int n, nod *lista)
 {   nod *nou = nod_nou(n, lista)
        lista = nou;
return lista;
}
int main(void)
{
}