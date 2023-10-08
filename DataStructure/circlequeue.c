#include <stdio.h>
#define MAX_SIZE 5
char Queue[MAX_SIZE];
int front = -1;
int rear = -1;
void pop()
{
    int del_item;
    if (front == -1)
    {
        printf("Queue Underflow\n");
    }
    else
    {
        del_item = Queue[front];
        front = front + 1;
        printf("Pop item = %d\n", del_item);
        if (front > rear)
        {
            front = -1;
            rear = -1;
        }
    }
}
void push(int item)
{
    if (front == (rear + 1) % MAX_SIZE)
        printf("Queue overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        rear = (rear + 1);
        Queue[rear] = item;
    }
}
void main()
{
    int c, i, item;
    do
    {
        printf("Type 1:Push 2:Pop 3:Display  4:Exit\n");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            printf("Enter the item to be pushed\n");
            scanf("%d", &item);
            push(item);
            break;
        case 2:
            pop();
            break;
        case 3:
            for (i = front; i <= rear && front != -1; i++)
            {
                printf("%d ", Queue[i]);
            }
            printf("\n");
            if (front == -1)
                printf("Queue is empty\n");
            break;
        case 4:
            break;
        default:
            printf("Invalid input \n");
        }
    } while (c != 4);
}