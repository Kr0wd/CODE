#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *link;
} ;
struct node *top = NULL;
void push(int item)
{
    struct node *new = (struct node *)malloc(sizeof(struct node));
    new->data = item;
    new->link = NULL;
    if (top != NULL)
        new->link = top;
    top = new;
    printf("Inserted %d successfully!\n", new->data);
}

void pop()
{
    if (top == NULL)
        printf("Stack Underflow!\n");
    else
    {
        struct node *temp = top;
        if (top->link == NULL)
            top = NULL;
        else
            top = temp->link;
        printf("Deleted %d successfully!\n", temp->data);
        free(temp);
    }
}
void print()
{
    if (top == NULL)
        printf("Stack is empty!\n");
    else
    {
        struct node *ptr = top;
        while (ptr != NULL)
        {
            printf("%d\t", ptr->data);
            ptr = ptr->link;
        }
        printf("\n");
    }
}
int main()
{
    int choice, item;
    while (1)
    {
        printf("Select operation:\n"
               "1. Insertion\t2. Deletion\n"
               "3. Display\t4. Exit\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter element to be inserted: \n");
            scanf("%d", &item);
            push(item);
            break;

        case 2:
            pop();
            break;

        case 3:
            print();
            break;

        case 4:
            return 0;

        default:
            printf("Invalid option!\n");
        }
    }
}