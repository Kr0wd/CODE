#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node *head;
void insertHead(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = head;
    head = temp;
    printf("Inserted %d successfully!\n", x);
}
void insertEnd(int x)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    temp->link = NULL;
    struct node *ptr = head;
    while (ptr->link != NULL)
        ptr = ptr->link;
    ptr->link = temp;
    printf("Inserted %d successfully!\n", x);
}
void insertAt(int x, int n)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = x;
    if (n == 1)
    {
        temp->link = head;
        head = temp;
    }
    else
    {
        struct node *ptr = head;
        for (int i = 0; i < n - 2; i++)
        {
            if (ptr->link == NULL)
            {
                printf("Position %d is out of order!\n"
                       "Inserting at the end instead.\n",
                       n);
                insertEnd(x);
                printf("Inserted %d successfully!\n", x);
                free(temp);
                return;
            }
            ptr = ptr->link;
        }
        temp->link = ptr->link;
        ptr->link = temp;
    }
    printf("Inserted %d at postion %d successfully!\n", x, n);
}
void deleteHead()
{
    if (head == NULL)
        printf("Deletion not possible\n");
    else
    {
        struct node *temp = head;
        head = temp->link;
        printf("Deleted %d\n\n", temp->data);
        free(temp);
    }
}
void deleteEnd()
{

    if (head == NULL)
        printf("Deletion not possible\n");
    else
    {
        struct node *ptr = head;
        if (ptr->link == NULL)
        {
            head = NULL;
            printf("Deleted %d\n\n", ptr->data);
            free(ptr);
        }
        else
        {
            while (ptr->link->link != NULL)
                ptr = ptr->link;
            struct node *temp = ptr->link;
            ptr->link = NULL;
            printf("Deleted %d\n\n", temp->data);
            free(temp);
        }
    }
}
void deleteAt(int n)
{
    if (head == NULL)
        printf("Deletion not possible\n");
    else
    {
        int i = 0;
        struct node *ptr = head;
        while (i < n - 2)
        {
            if (ptr->link == NULL)
                printf("Deletion not possible, Invalid position!\n\n");
            else
            {
                i++;
                ptr = ptr->link;
            }
        }
        struct node *temp = ptr->link;
        ptr->link = temp->link;
        printf("Deleted %d\n\n", temp->data);
        free(temp);
    }
}
void print()
{
    if (head == NULL)
        printf("List is empty!\n");
    else
    {
        struct node *temp = head;
        printf("List elements are :\n");
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->link;
        }
        printf("\n");
    }
}
int main()
{
    head = NULL;
    int option, item, n;
    while (1)
    {
        printf("Select operation\n"
               "1.Insert at HEAD\t2.Insert at N\t"
               "3.Insert at END\n4.Delete at HEAD\t"
               "5.Delete at N\t6.Delete at END\n"
               "7.Display list\t\t8.Exit\n");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            printf("Enter the item to be inserted: \n");
            scanf("%d", &item);
            insertHead(item);
            break;

        case 2:
            printf("Enter the item to be inserted: \n");
            scanf("%d", &item);
            printf("Enter the position to insert %d: \n", item);
            scanf("%d", &n);
            insertAt(item, n);
            break;

        case 3:
            printf("Enter the item to be inserted: \n");
            scanf("%d", &item);
            insertEnd(item);
            break;

        case 4:
            deleteHead();
            break;

        case 5:
            printf("Enter the position to delete: \n");
            scanf("%d", &n);
            deleteAt(n);
            break;

        case 6:
            deleteEnd();
            break;

        case 7:
            print();
            break;

        case 8:
            return 0;

        default:
            printf("Invalid operation!\n");
        }
    }
}