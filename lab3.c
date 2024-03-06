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
}
int main(void)
{
}