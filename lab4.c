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
    char nume[15];
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
void citireFisier()
{
    FIS fisaux;
    int aux;
    printf("Nume:");
    strcpy(fisaux.nume, readword());
    printf("Dim:");
    scanf("%d", &aux);
    fisaux.dim = aux;
    printf("Extensie .txt - 0, .doc - 1, .xls  2:");
    scanf("%d", &aux);
    fisaux.extensie = aux;
    printf("Tip normal  0, read-only  1:");
    scanf("%d", &aux);
    fisaux.tip = aux;
    adaugareFis(fisaux);
}
void pb1()
{

    citireFisier();
}
int main(void)
{
    pb1();
    printf("%s",fisiere[0].nume);
    return 0;
}