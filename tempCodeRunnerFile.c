typedef struct nod
{
    char linie[1000];
    struct nod *urm;
    struct nod *pred;
} nod;