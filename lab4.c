#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
    int unsigned dim : 11;
    
    int nume[15];
} FIS;

void pb1()
{
    
}
int main(void)
{
}