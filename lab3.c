#include <stdlib.h>
#include <stdio.h>

#define MAXSIZE 100
int stack[MAXSIZE];
int top = -1;

void push(int item)
{
    if (top == MAXSIZE - 1)
    {
        printf("The stack is full!!!");
    }
    else
    {
        stack[++top] = item;
    }
}

int pop()
{
    if (top == -1)
    {
        printf("The stack is empty!!!");
    }
    else
    {
        return stack[--top];
    }
}

void display()
{
    if (top == -1)
    {
        printf("The stack is empty !!!");
    }
    else
    {
        for (int i = top; i >= 0; i--)
        {
            printf("%d ", stack[i]);
        }
    }
}

int queue[MAXSIZE];
int rear = -1, front = -1;

void enqueue(int item)
{
    if (rear == MAXSIZE - 1)
    {
        printf("The queue is full!!!");
    }
    else
    {
        if (front == -1)
        {
            front = 0;
        }
        queue[++rear] = item;
    }
}

int dequeue()
{
    if (front == -1 || front > rear)
    {
        printf("The queue is empty!!!");
    }
    else
    {
        return queue[front++];
    }
}
void qdisplay()
{
    if (front == -1 || front > rear)
    {
        printf("The queue is empty!!!");
    }
    else
    {
        for (int i = front; i <= rear; i++)
        {
            printf("%d ", queue[i]);
        }
    }
    printf("\n");
}
void qpeek()
{
    if (front == -1 || front > rear)
    {
        printf("The queue is empty!!!");
    }
    else
    {
        printf("%d", queue[front]);
    }
    printf("\n");
}

typedef struct
{
    char s[100];
    int rand;
} DATA;

DATA dStack[MAXSIZE];
int top2 = -1;

void add(DATA item)
{
    if (top2 == MAXSIZE - 1)
    {
        printf("Stack is full!!!");
    }
    else
    {
        dStack[++top2] = item;
    }
}
void undo()
{
    if (top2 == -1)
    {
        printf("Stack is empty!!!");
    }
    else
    {
        top2--;
    }
}

void Display()
{
    if (top2 == -1)
    {
        printf("Stack is empty!!!");
    }
    else
    {
        printf("%s  %d\n", dStack[top2].s, dStack[top2].rand);
    }
}

typedef struct
{
    int trans;
    char msj[100];
} BUF;

BUF dQueue[MAXSIZE];
int dfront = -1, drear = -1;

void Add(BUF item)
{
    if (drear == MAXSIZE - 1)
    {
        printf("Queue is full!!!");
    }
    else
    {
        if (dfront == -1)
            dfront = 0;
        dQueue[++drear] = item;
    }
}

void transmit()
{
    if (dfront == -1 || dfront > drear)
    {
        printf("Queue is empty!!!");
    }
    else
    {
        dfront++;
    }
}
void tDisplay()
{
    if (dfront == -1 || dfront > drear)
    {
        printf("Queue is empty!!!");
    }
    else
    {
        printf("%d   %s", dQueue[dfront].trans, dQueue[dfront].msj);
        printf("\n");
    }
}
int main(void)
{
    

}