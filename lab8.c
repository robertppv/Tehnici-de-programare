#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct nod
{
    char linie[1000];
    struct nod *urm;
    struct nod *pred;
} nod;

typedef struct
{
    nod *prim;
    nod *ultim;
} Lista;

nod *nou(char linie[1000])
{
    nod *nou = NULL;
    if ((nou = malloc(sizeof(nod))) == NULL)
    {
        perror("mem");
        exit(-1);
    }
    strcpy(nou->linie, linie);
    return nou;
}

Lista Lista_init(Lista L)
{
    L.prim = L.ultim = NULL;
    return L;
}

Lista adaugasf(Lista L, char linie[1000])
{

    nod *c = nou(linie);
    c->pred = L.ultim;
    if (L.ultim)
    {
        L.ultim->urm = c;
    }
    else
    {
        L.prim = c;
    }
    L.ultim = c;
    c->urm = NULL;
    return L;
}

void afisare(Lista L)
{

    for (nod *p = L.prim; p != NULL; p = p->urm)
    {
        printf("%s ", p->linie);
    }
}

Lista adaugaord(Lista L, char linie[1000])
{
    nod *p = NULL;
    if (strcmp(linie, L.prim->linie) < 0)
    {
        nod *noun = nou(linie);
        L.prim->pred = noun;
        noun->urm = L.prim;
        noun->pred = NULL;
        L.prim = noun;
        return L;
    }
    if (strcmp(linie, L.ultim->linie) > 0)
    {
        nod *noun = nou(linie);
        L.ultim->urm = noun;
        noun->urm = NULL;
        noun->pred = L.ultim;
        L.ultim = noun;
        return L;
    }

    for (p = L.prim; p != NULL; p = p->urm)
    {
        if (strcmp(linie, p->linie) > 0)
        {
            continue;
        }
        else
        {
            nod *noun = nou(linie);
            p->pred->urm = noun;
            noun->urm = p;
            noun->pred = p->pred;
            p->pred = noun;
            break;
        }
    }
    return L;
}
void pb3(int argc, char **argv)
{
    Lista L;
    L = Lista_init(L);
    char buf[1000];
    FILE *in;
    if ((in = fopen(argv[1], "r")) == NULL)
    {
        perror("f err");
        exit(EXIT_FAILURE);
    }

    while (fgets(buf, 1000, in))
    {

        buf[strcspn(buf, "\n")] = 0;

        if (L.prim != NULL)
        {
            L = adaugaord(L, buf);
        }
        else
        {
            L = adaugasf(L, buf);
        }
    }
    if (fclose(in) != 0)
    {
        perror("ferr");
        exit(EXIT_FAILURE);
    }
    afisare(L);
}

typedef struct prod
{
    char nume[1000];
    struct prod *urm;
    struct prod *pred;
} prod;
typedef struct categ
{
    char nume[15];
    struct prod *produse;
    struct categ *urm;
    struct categ *pred;
} categ;

categ *categnou(char *nume)
{
    categ *nou;
    if ((nou = malloc(sizeof(categ))) == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nou->nume, nume);
    nou->pred = NULL;
    nou->produse = NULL;
    nou->urm = NULL;
}

categ *adaugacateg(categ *L, char *nume)
{
    categ *nou = categnou(nume), *p;
    if (L == NULL)
    {
        L = nou;
    }
    else
    {
        for (p = L; p->urm != NULL; p = p->urm)
            ;
        nou->pred = p;
        p->urm = nou;
    }
    return L;
}
prod *produsnou(char *nume)
{
    prod *nou;
    if ((nou = malloc(sizeof(prod))) == NULL)
    {
        exit(EXIT_FAILURE);
    }
    strcpy(nou->nume, nume);
    nou->pred = NULL;
    nou->urm = NULL;
    return nou;
}
categ *adaugaprodus(categ *L, char *numecat, char *numeprodus)
{
    prod *nou = produsnou(numeprodus);

    for (categ *p = L; p != NULL; p = p->urm)
    {
        if (strcmp(p->nume, numecat) == 0)
        {
            if (p->produse == NULL)
            {
                p->produse = nou;
            }
            else
            {
                prod *p2;

                for (p2 = p->produse; p2->urm != NULL; p2 = p2->urm)
                    ;
                p2->urm = nou;
                nou->pred = p2;
            }
            break;
        }
    }
    return L;
}
void afisarecat(categ *L)
{
    for (categ *p = L; p != NULL; p = p->urm)
    {
        printf("%s\n", p->nume);
    }
}

void afisareprod(categ *L, char *numecateg)
{
    for (categ *p = L; p != NULL; p = p->urm)
    {
        if (strcmp(p->nume, numecateg) == 0)
        {
            for (prod *p2 = p->produse; p2 != NULL; p2 = p2->urm)
            {
                printf("%s ", p2->nume);
            }
        }
    }
    printf("\n");
}

void pb4()
{
    categ *categorii = NULL;
    int opt = 6;
    char buf[100], buf2[100];
    while (opt)
    {
        printf(" 1-adauga categorie; 2-adauga produs ; 3-afisare categorii ; 4-afisare produse ; 5-iesire\n");
        printf("Optiunea:");
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            printf("nume:");
            scanf("%s", &buf);
            categorii = adaugacateg(categorii, buf);

            break;
        case 2:
            printf("categ:");
            scanf("%s", &buf);
            printf("nume produs:");
            scanf("%s", &buf2);
            categorii = adaugaprodus(categorii, buf, buf2);

            break;
        case 3:
            afisarecat(categorii);
            break;
        case 4:
            printf("categ:");
            scanf("%s", &buf);
            afisareprod(categorii, buf);

            break;
        case 5:
            opt = 0;
            break;

        default:
            break;
        }
    }
}

typedef struct car
{
    int cod : 14;
    int nrloc : 4;
    int hp : 9;
    char marca[100];
    char cul[100];
    int an : 12;
    struct car *urm;
    struct car *pred;
} car;
car *newcar(int cod, int nrloc, int hp, char *marc, char *cul, int an)
{
    car *new;
    if ((new = malloc(sizeof(car))) == NULL)
    {
        exit(EXIT_FAILURE);
    }
    new->an = an;
    new->hp = hp;
    new->cod = cod;
    new->nrloc = nrloc;
    strcpy(new->cul, cul);
    strcpy(new->marca, marc);
    new->urm = NULL;
    new->pred = NULL;
    return new;
}

car *addcar(car *cars, int cod, int nrloc, int hp, char *marc, char *cul, int an)
{
    car *new = newcar(cod, nrloc, hp, marc, cul, an);
    if (cars == NULL)
    {
        cars = new;
    }
    else
    {
        cars->pred = new;
        new->urm = cars;
        cars = new;
    }
    return cars;
}

car *deletecar(car *cars, int cod)
{
    car *p;
    for (p = cars; p != NULL; p = p->urm)
    {
        if (p->cod == cod)
        {
            if (p->urm == NULL)
            {
                p->pred->urm = NULL;
                break;
            }
            if (p->pred == NULL)
            {
                p->urm->pred = NULL;
                cars = p->urm;
                break;
            }
            p->pred->urm = p->urm;
            p->urm->pred = p->pred;
            break;
        }
    }
    free(p);
    return cars;
}

void showcar(car *cars)
{
    for (car *p = cars; p != NULL; p = p->urm)
    {
        printf("%d ", p->cod);
    }
    printf("\n");
}

void showcarwithseats(car *cars, int nrseats)
{
    for (car *p = cars; p != NULL; p = p->urm)
    {
        if (p->nrloc == nrseats)
            printf("%d\n", p->cod);
    }
}

car *ordonare(car *cars)
{
    car *p1, *p2, aux;
    for (p1 = cars; p1 != NULL; p1 = p1->urm)
    {

        for (p2 = p1->urm; p2 != NULL; p2 = p2->urm)
        {

            if (p1->an > p2->an)
            {
                printf("%d-%d ", p1->an, p2->an);
                car temp = *p1;
                *p1 = *p2;
                *p2 = temp;
            }
        }
    }
    return cars;
}

car *sortareAnFabricatie(car *listaDeAutomobile)
{
    car *aux, *aux2;
    for (aux = listaDeAutomobile; aux != NULL; aux = aux->urm)
    {
        for (aux2 = aux->urm; aux2 != NULL; aux2 = aux2->urm)
        {
            if (aux->an > aux2->an)
            {
            }
        }
    }
    return listaDeAutomobile;
}
void pb5()
{
    car *cars = NULL;
    cars = addcar(cars, 12, 4, 77, "toyota", "red", 20);
    cars = addcar(cars, 17, 2, 77, "toyota", "red", 2004);
    cars = addcar(cars, 156, 2, 77, "toyota", "red", 100);

    cars = sortareAnFabricatie(cars);
    printf("\n");
    showcar(cars);
}

typedef struct Cuvant
{
    char text[16];       // max 15 litere+terminator
    struct Cuvant *pred; // inlantuire la predecesor
    struct Cuvant *urm;  // inlantuire la urmator
} Cuvant;
// aloca un nou cuvant si ii seteaza campul text
// campurile pred si urm raman neinitializate
Cuvant *Cuvant_nou(const char *text)
{
    Cuvant *c = (Cuvant *)malloc(sizeof(Cuvant));
    if (!c)
    {
        printf("memorie insuficienta");
        exit(EXIT_FAILURE);
    }
    strcpy(c->text, text);
    return c;
}
typedef struct
{
    Cuvant *prim;  // primul cuvant din lista
    Cuvant *ultim; // ultimul cuvant din lista
} Propozitie;
// initializare propozitie noua
void Propozitie_init(Propozitie *p)
{
    p->prim = p->ultim = NULL;
}
// adauga un cuvant la sfarsitul propozitiei

void Propozitie_adauga(Propozitie *p, Cuvant *c)
{
    c->pred = p->ultim; // predecesorul cuvantului este ultimul cuvant din lista
    if (p->ultim)
    {                      // daca mai sunt si alte cuvinte in lista
        p->ultim->urm = c; // ultimul cuvant din lista va pointa catre noul cuvant
    }
    else
    {                // altfel, daca c este primul cuvant din lista
        p->prim = c; // seteaza si inceputul listei la el
    }
    p->ultim = c;  // seteaza sfarsitul listei pe noul cuvant
    c->urm = NULL; // dupa cuvantul introdus nu mai urmeaza niciun cuvant
}
// cauta un text in propozitie si daca il gaseste returneaza un pointer la cuvantul respectiv
// daca nu-l gaseste, returneaza NULL
Cuvant *Propozitie_cauta(Propozitie *p, const char *text)
{
    Cuvant *c;
    for (c = p->prim; c; c = c->urm)
    {
        if (!strcmp(c->text, text))
            return c;
    }
    return NULL;
}
// sterge un cuvant din propozitie
void Propozitie_sterge(Propozitie *p, Cuvant *c)
{
    if (c->pred)
    {                          // cuvantul nu este primul in propozitie
        c->pred->urm = c->urm; // campul urm al predecesorului lui c va pointa la cuvantul de dupa c
    }
    else
    {                     // cuvantul este primul in propozitie
        p->prim = c->urm; // seteaza inceputul listei pe urmatorul cuvant de dupa c
    }
    if (c->urm)
    {                           // cuvantul nu este ultimul din propozitie
        c->urm->pred = c->pred; // campul pred al cuvantului de dupa c va pointa la cuvantul de dinainte de c
    }
    else
    {                       // cuvantul este ultimul din propozitie
        p->ultim = c->pred; // seteaza sfarsitul listei pe predecesorul lui c
    }
    free(c);
}
// elibereaza cuvintele din memorie si reinitializeaza propozitia ca fiind vida
void Propozitie_elibereaza(Propozitie *p)
{
    Cuvant *c, *urm;
    for (c = p->prim; c; c = urm)
    {
        urm = c->urm;
        free(c);
    }
    Propozitie_init(p);
}

Cuvant *inserareProp(Propozitie *p,Cuvant *ins,Cuvant *succ)
{
    
}
int main()
{
    Propozitie p;
    int op; // optiune
    char text[16];
    Cuvant *c;
    Propozitie_init(&p); // initializare propozitie vida
    do
    {
        printf("1 - propozitie noua\n");
        printf("2 - afisare\n");
        printf("3 - stergere cuvant\n");
        printf("4 - iesire\n");
        printf("optiune: ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            Propozitie_elibereaza(&p); // elibereaza posibila propozitie anterioara
            for (;;)
            {
                scanf("%s", text);
                // intre ultimul cuvant si punct trebuie sa existe un spatiu, pentru ca punctul sa fie considerat separat
                if (!strcmp(text, "."))
                    break; // atentie: "." este un sir de caractere, nu o litera (char)
                Cuvant *c = Cuvant_nou(text);
                Propozitie_adauga(&p, c);
            }
            break;
        case 2:
            for (c = p.prim; c; c = c->urm)
                printf("%s ", c->text);
            printf(".\n");
            break;
        case 3:
            printf("cuvant de sters:");
            scanf("%s", text);
            c = Propozitie_cauta(&p, text);
            if (c)
            {
                Propozitie_sterge(&p, c);
            }
            else
            {
                printf("cuvantul \"%s\" nu se gaseste in propozitie\n", text);
            }
            break;
        case 4:
            break;
        default:
            printf("optiune invalida");
        }
    } while (op != 4);
    return 0;
}

