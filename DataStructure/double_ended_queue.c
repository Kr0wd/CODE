#include <stdio.h>
#define MAX_SIZE 5
int q1[MAX_SIZE];
int front;
int rear;
void enqueue_front(int item)
{
    if (front == (rear + 1) % MAX_SIZE)
        printf("Queue is full!\n");
    else
    {
        if (front == -1)
        {
            front = 0;
            rear = 0;
        }
        else
            front = (front + MAX_SIZE - 1) % MAX_SIZE;
        q1[front] = item;
        printf("Added %d\n", item);
    }
}

void enqueue_rear(int item)
{
    if (front == (rear + 1) % MAX_SIZE)
        printf("Queue is full!\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1) % MAX_SIZE;
        q1[rear] = item;
        printf("Added %d\n", item);
    }
}

void dequeue_front()
{
    if (front == -1)
        printf("Queue is empty!\n");
    else
    {
        int del = q1[front];
        printf("Deleted %d\n", del);
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = (front + 1) % MAX_SIZE;
    }
}

void dequeue_rear()
{
    if (front == -1)
        printf("Queue is empty!\n");
    else
    {
        int del = q1[rear];

        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            rear = (rear + MAX_SIZE - 1) % MAX_SIZE;
        printf("Deleted %d\n", del);
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
               "1. Enqueue via FRONT\n2. Dequeue via FRONT\n"
               "3. Enqueue via REAR\n4. Dequeue via REAR\n"
               "5. List\n6. Exit\n");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            printf("Enter item to add:\n");
            scanf("%d", &item);
            enqueue_front(item);
            break;
        case 2:
            dequeue_front();
            break;
        case 3:
            printf("Enter item to add:\n");
            scanf("%d", &item);
            enqueue_rear(item);
            break;
        case 4:
            dequeue_rear();
            break;
        case 5:
            list();
            break;
        case 6:
            return 0;
        default:
            printf("Invalid operation!\nTry again.\n");
        }
    }
}