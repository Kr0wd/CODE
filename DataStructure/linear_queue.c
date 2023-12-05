#include<stdio.h>
#define MAX_SIZE 3
int Queue[MAX_SIZE];
int front = -1, rear = -1;
void Enqueue(int item)
{
if (rear==MAX_SIZE-1)
        printf("Queue Overflow\n");
    else
    {
        if (front == -1)
            front = 0;
        Queue[++rear] = item;
        printf("Element added :%d\n", item);    
    }

}
void Dequeue()
{
    int element;
    if (front == -1)
        printf("Queue Underflow \n");
    else
    {
        element = Queue[front];
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
            front = front + 1;
        printf("Deleted element = %d \n", element);
        
    }
}
void display()
{
    int i;
    if (front == -1)
        printf("Empty Queue\n");
    else
    {
        printf("Queue elements are :\n");
        for (i = front;i < rear; i++)
            printf("%d ", Queue[i]);
        printf("%d \n", Queue[i]);
    }
}
int main()
{
    int c, i, item;
    while(1)
    {
        printf("Select operation:\n"
               "1. Enqueue\t2. Dequeue\n"
               "3. List\t4. Exit\n");       
        scanf("%d", &c);
        switch (c)
        {
            case 1:
                printf("Enter the item : ");
                scanf("%d", &item);
                Enqueue(item);
                break;
            case 2:
                Dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                printf("Invalid input \n");
        }
    }
} 