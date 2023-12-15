#include<stdio.h>
#include<stdlib.h>
struct term
{
    int exp,coef;
    struct term* link;
};
struct term *ptr,*head,*new;

struct term *readpoly()
{
    head=NULL;
    int n,c,e;
    printf("enter the number of terms");
    scanf("%d",&n);
    for (int i=0;i<n;i++)
        {
            new=(struct term*)malloc(sizeof(struct term));
            printf("enter the coefficient of term %d: ",i+1);
            scanf("%d",&new->coef);
            printf("enter the exponent of term %d: ",i+1);
            scanf("%d",&new->exp);
            if (head==NULL)
                head =new;
            else
                ptr->link=new;
            ptr=new;
        }
    return head;
}

struct term *addpoly(struct term *p1,struct term *p2)
{
    head=NULL;
    struct term *ptr0,*ptr1,*ptr2;
    ptr0=head;
    ptr1=p1;
    ptr2=p2;
    while(ptr1 != NULL && ptr2 != NULL)
    {
        new=(struct term*)malloc(sizeof(struct term));
        new->link=NULL;
        if(ptr1->exp==ptr2->exp)
        {
            new->coef=ptr1->coef+ptr2->coef;
            new->exp=ptr1->exp;
            ptr1=ptr1->link;
            ptr2=ptr2->link;
        }
        else if (ptr1->exp > ptr2->exp)
        {
            new->coef=ptr1->coef;
            new->exp=ptr1->exp;
            ptr1=ptr1->link;
        }
        else
        {
            new->coef=ptr2->coef;
            new->exp=ptr2->exp;
            ptr2=ptr2->link;
        }
        if (head==NULL)
        {
            head=new;
            ptr0=new;
        }
        else
        {
            ptr0->link= new;
            ptr0=new;
        }

    }
    while(ptr1 !=NULL)
    {
        new=(struct term*)malloc(sizeof(struct term));
        new->link=NULL;
        new->coef=ptr1->coef;
        new->exp=ptr1->exp;
        ptr1=ptr1->link;
        ptr0->link= new;
        ptr0=new;
    }
    while(ptr2 !=NULL)
    {
        new=(struct term*)malloc(sizeof(struct term));
        new->link=NULL;
        new->coef=ptr2->coef;
        new->exp=ptr2->exp;
        ptr2=ptr2->link;
        ptr0->link= new;
        ptr0=new;
    }
    return head;
}

void display(struct term *head)
{
    if (head !=NULL)
    {
        printf("Polynomial :");
        ptr=head;
        while(ptr->link!=NULL)
        {
            printf("%dX^%d+",ptr->coef,ptr->exp);
            ptr=ptr->link;
        }
        if (ptr->exp==0)
            printf("%d",ptr->coef);
        else if(ptr->exp==1)
            printf("%dX",ptr->coef);
        else
            printf("%dX^%d+",ptr->coef,ptr->exp);
    }
    printf("\n");
}
int main()
{
    head=NULL;
    struct term *p1= readpoly();
    display(p1);
    struct term *p2= readpoly();
    display(p2);
    struct term *res = addpoly(p1,p2);
    printf("sum :");
    display(res);
}