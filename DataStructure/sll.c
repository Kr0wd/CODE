#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *link;
};
struct node* head,*new,*ptr,*temp;
void inserthead (int x)
{
    new=(struct node *)malloc(sizeof (struct node));
    new->data=x;
    new->link=NULL;
    if (head==NULL)
    {
        head=new;
    }
    else
    {
        new->link=head;
        head=new;
    }
    printf("inserted %d successfully \n",x);
}
void insertend(int x)
{
    new =(struct node *)malloc(sizeof (struct node));
    new->data=x;
    new->link=NULL;
    if (head==NULL)
    {
        head=new;
    }
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        ptr->link=new;
    }
    printf("inserted %d successfully \n",x);
}

void insertat (int x,int pos)
{
    new=(struct node *)malloc(sizeof (struct node));
    new->data=x;
    new->link=NULL;
    if(pos==1)
    {
        inserthead(x);
    }
    else
    {
        if (ptr->link==NULL)
        {
            printf("postion %d is out of order\n",pos);
            printf("inserting element %d at the end instead\n",x);
            insertend(x);
        }
        ptr=head;
        for(int i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
        temp=ptr->link;
        ptr->link=new;
        new->link=temp;
    }
    printf("inserted %d successfully \n",x);
}
void deletehead()
{
    if (head==NULL)
        printf("deletion not possible\n");
    else
    {
        ptr=head;
        head=ptr->link;
        printf("%d has been deleted\n",ptr->data);
        free(ptr);
    }
}
void deleteend()
{
    if (head==NULL)
        printf("deletion not possible\n");
    else
    {
        ptr=head;
        while(ptr->link!=NULL)
            ptr=ptr->link;
        printf("%d has been deleted\n",ptr->data);
        free(ptr);
    }
}
void deleteat(int pos)
{
    if (head ==NULL)
    {
        printf("deletion not possible\n");
    }
    else
    {
        if (pos==1)
        {
        printf("deletion ouut of order\n");
        printf("deleting last element instead\n");
        deletehead();
        }
        else
        {
        ptr=head;
        for(int i=1;i<pos-1;i++)
        {
            ptr=ptr->link;
        }
        temp=ptr->link;
        ptr->link=temp->link;
        printf("%d has been deleted\n",temp->data);
        }
    }
}
void display()
{
    if (head==NULL)
        printf("list is empty\n");
    else
    {
        ptr=head;
        while (ptr->link!=NULL)
        {
            printf("%d\t",ptr->data);
            ptr=ptr->link;
        }
        printf("%d\n",ptr->data);
    }
}
int main()
{
    head=NULL;
    int option,item,n;
    while (1)
    {
        printf("Select operation\n"
               "1.Insert at HEAD\t2.Insert at N\t"
               "3.Insert at END\n4.Delete at HEAD\t"
               "5.Delete at N\t6.Delete at END\n"
               "7.Display list\t\t8.Exit\n");
        scanf("%d", &option);
        switch(option)
        {
            case 1:
                printf("enter the element to be inserted: ");
                scanf("%d",&item);
                inserthead(item);
                break;
            case 2:
                printf("enter the element to be inserted: ");
                scanf("%d",&item);
                printf("enter the position to insert %d :",item);
                scanf("%d",&n);
                insertat(item,n);
                break;
            case 3:
                printf("enter the element to be inserted: ");
                scanf("%d",&item);
                insertend(item);
                break;
            case 4 :
                deletehead(item);
                break;
            case 5:
                printf("enter the position to delete : ");
                scanf("%d",&n);
                deleteat(n);
                break;
            case 6:
                deleteend();
                break;
            case 7:
                display();
                break;
            case 8:
                return 0;
            default:
                printf("invalid operation\n");
        }
    }
}