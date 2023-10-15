#include <stdio.h>
#define MAX_SIZE 5
int q1[MAX_SIZE];
int front;
int rear;
void enqueue(int item)
{
    if (front == (rear + 1) % MAX_SIZE)
        printf("Queue is full!\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        q1[rear] = item;
        printf("Element added :%d\n", item);
    }
}

void dequeue()
{
    if (front == -1)
        printf("Queue is empty!\n\n");
    else
    {
        int del = q1[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % MAX_SIZE;
        printf("Element deleted :%d\n", del);
    }
}

void list()
{
    if (front == -1)
    {
        printf("Queue is empty!\n\n");
        return;
    }
    printf("Queue elements are :\n");
    int i = front;
    while (i != (rear + 1) % MAX_SIZE)
    {
        printf("%d \t", q1[i]);
       i = (i + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main()
{
    front = -1;
    rear = -1;
    int ch, item;
    while (1)
    {
        printf("Select operation:\n"
               "1. Enqueue\n2. Dequeue\n"
               "3. List\n4. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to add:\n");
            scanf("%d", &item);
            enqueue(item);
            break;

        case 2:
            dequeue();
            break;

        case 3:
            list();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid operation!\nTry again.\n");
        }
    }
}