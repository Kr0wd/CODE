#include<stdio.h>
#include<stdlib.h>
struct node
{
	struct node *lptr,*rptr;
	int data;
};
struct node *root,*new1,*parent;
void insert(int val)
{
	struct node *ptr;
	new1=(struct node*)malloc(sizeof(struct node));
	new1->data=val;
	new1->rptr=new1->lptr=NULL;
	if(root==NULL)
		root=new1;
	else
	{
		ptr=root;
		while(ptr!=NULL)
		{
			parent=ptr;
			if(ptr->data>val)
				ptr=ptr->lptr;
			else
				ptr=ptr->rptr;
		}
		if(parent->data>val)
			parent->lptr=new1;
		else
			parent->rptr=new1;
	}
}
struct node* insuc(struct node *ptr)
{
	ptr=ptr->rptr;
	while(ptr->lptr!=NULL)
		ptr=ptr->rptr;
	return ptr;
}
void del(int val)
{
	struct node *insucces,*ptr;
	int succes;
	ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->data==val)
			break;
		else
		{
			parent=ptr;
			if(ptr->data>val)
				ptr=ptr->lptr;
			else
				ptr=ptr->rptr;
		}
	}	
	if(ptr==NULL)
		printf("Element not found deletion not possible \n");
	else
	{
		if(ptr->lptr==NULL&&ptr->rptr==NULL)
		{	
			if(ptr==root)
				root=NULL;
			else if(parent->lptr==ptr)
				parent->lptr=NULL;
			else
				parent->rptr=NULL;
		}
		else if(ptr->rptr==NULL)
		{
			if(ptr==root)
				root=ptr->lptr;
			else if(parent->lptr==ptr)
				parent->lptr=ptr->lptr;
			else
				parent->rptr=ptr->lptr;
		}
		else if(ptr->lptr==NULL)
		{
			if(ptr==root)
				root=ptr->rptr;
			else if(parent->lptr==ptr)
				parent->lptr=ptr->rptr;
			else
				parent->rptr=ptr->rptr;
		}
		else
		{
			insucces=insuc(ptr);
			del(insucces->data);
			ptr->data=insucces->data;
		}
	}
}
void preorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		printf(" %d",ptr->data);
		preorder(ptr->lptr);
		preorder(ptr->rptr);
	}
}
void postorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		postorder(ptr->lptr);
		postorder(ptr->rptr);
		printf(" %d",ptr->data);
	}
}
void inorder(struct node *ptr)
{
	if(ptr!=NULL)
	{
		inorder(ptr->lptr);
		printf(" %d",ptr->data);
		inorder(ptr->rptr);
	}
}
struct node* search(int val)
{
	struct node *ptr;
	ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->data==val)
		{
			printf("%d is found\n",val);
			break;
		}
		else if(ptr->data>val)
			ptr=ptr->lptr;
		else
			ptr=ptr->rptr;
	}
	if(ptr==NULL)
		printf("%d is not found\n",val);
}
void display()
{
	if(root==NULL)
		printf("Tree is empty\n");
	else
	{
	       printf("Preorder representation of tree : ");
	       preorder(root);
	       printf("\n");
	       printf("Inorder representation of tree : ");
	       inorder(root);
	       printf("\n");
	       printf("Postorder representation of tree : ");
	       postorder(root);
	       printf("\n");
	 }
}
int main()
{
	int c,val;
	while(1)
	{
		printf("Select Operation:\n"
               "1. Insert\t2. Delete\t"
               "3. Search\n4. Display\t5. Exit\n");
		scanf("%d",&c);
		switch(c)
		{
			case 1:
                printf("Enter the value to insert :");
			    scanf("%d",&val);
			    insert(val);
			    break;
			case 2:
                printf("Enter the value of node to delete : ");
			    scanf("%d",&val);
			    del(val);
			    break;
			case 3:
                printf("Enter the value of node to search : ");
			    scanf("%d",&val);
			    search(val);
			    break;
			case 4:
                display();
				break;
			
			case 5:
			    return 0;

			default:
                printf("Invalid input\n");
		}
	}
}