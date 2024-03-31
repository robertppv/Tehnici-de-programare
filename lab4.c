#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define CHUNK 10

typedef struct
{
    char nume[20];
    float nota;
} STUDENT;

void pb0()
{
    STUDENT stud1;
    scanf("%19s", &stud1.nume);
    scanf("%f", &stud1.nota);
    printf("\n");
    printf("%s     %f", stud1.nume, stud1.nota);
}

typedef struct
{
    int unsigned dim : 10;
    unsigned int extensie : 2;
    unsigned int tip : 1;
    char *nume;
} FIS;
FIS *fisiere = NULL;
int nr_fisiere = 0;
char *readword()
{
    char *buf = NULL;
    int index = 0;
    char c;
    if ((buf = malloc(15 * sizeof(char))) == NULL)
    {
        perror("nasol mem err");
        exit(EXIT_FAILURE);
    }
    while ((c = getchar()) != '\n' && index < 15)
    {
        if (c != '\n')
        {
            buf[index++] = c;
        }
        else
        {
            break;
        }
    }
    buf[index] = '\0';
    return buf;
}
void adaugareFis(FIS aux)
{
    static int currentsize = 0;
    if (nr_fisiere <= currentsize)
    {
        currentsize += CHUNK;
        if ((fisiere = realloc(fisiere, currentsize * sizeof(FIS))) == NULL)
        {
            perror("nasol mem err");
            exit(EXIT_FAILURE);
        }
    }
    fisiere[nr_fisiere++] = aux;
}
void citireFisier(FILE *fis)
{
    FIS fisaux;
    int aux;
    char *p = NULL;
    printf("Nume:");
    p = readword();
    fisaux.nume = p;
    fprintf(fis, "%s\n", fisaux.nume);
    printf("Dim:");
    scanf("%d", &aux);
    fprintf(fis, "%d\n", aux);
    fisaux.dim = aux;
    printf("Extensie .txt - 0, .doc - 1, .xls  2:");
    scanf("%d", &aux);
    fprintf(fis, "%d\n", aux);
    fisaux.extensie = aux;
    printf("Tip normal  0, read-only  1:");
    scanf("%d", &aux);
    fprintf(fis, "%d\n", aux);
    fisaux.tip = aux;
    adaugareFis(fisaux);
    fprintf(fis, "\n");
}
void freefis()
{
    for (int i = 0; i < nr_fisiere; i++)
    {
        free(fisiere[i].nume);
    }
    free(fisiere);
}
void pb1()
{
    FILE *fis;
    if ((fis = fopen("memorie.txt,", "w")) == NULL)
    {
        perror("nasol file err");
        exit(EXIT_FAILURE);
    }
    citireFisier(fis);
    getchar();
    citireFisier(fis);
    freefis();
    if (fclose(fis) != 0)
    {
        perror("nasol file err");
        exit(EXIT_FAILURE);
    }
}

typedef struct
{
    unsigned int nPicioare : 9;
    unsigned int varstaMax : 7;
    unsigned int periculos : 1;
    unsigned int : 10;
    char abrev[8];
    float greutate;
} ANIMAL;

void pb4()
{
    ANIMAL animal1;
    scanf("%d", animal1.nPicioare);
    scanf("%f", animal1.greutate);
    scanf("%d", animal1.periculos);
    scanf("%s", animal1.abrev);
    scanf("%d", animal1.varstaMax);
}

typedef struct
{
    unsigned int periculos : 2;
    unsigned int reteta : 1;
    unsigned int varstamin : 5;
} MEDICAMENT;

void pb5()
{
    MEDICAMENT xanax;
    unsigned int aux;
    printf("gradul de periculozitate: scazuta-0, medie-1, mare-2:");
    scanf("%d", &aux);
    xanax.periculos = aux;
    printf("se elibereaza doar pe baza de reteta: da-1, nu-0:");
    scanf("%d", &aux);
    xanax.reteta = aux;
    printf("varsta minima de administrare: 1...18 ani inclusiv:");
    scanf("%d", &aux);
    xanax.varstamin = aux;

    printf("%d %d %d",xanax.periculos,xanax.reteta,xanax.varstamin);
}


void pb6()
{

    
}
int main(void)
{
   

    return 0;
}