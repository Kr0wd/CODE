#include <stdio.h>
#include <stdlib.h>
struct node
{
	int data;
	struct node *next, *prev;
};
struct node *head, *tail;
void insertHead(int x)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = x;
	new->prev = NULL;
	if (head != NULL)
		new->next = head;
	else
	{
		new->next = NULL;
		tail = new;
	}
	head = new;
	printf("Inserted %d successfully!\n", x);
}
void insertAt(int x, int pos)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = x;
	if (pos == 1)
	{
		new->prev = NULL;
		if (head != NULL)
			new->next = head;
		else
		{
			new->next = NULL;
			tail = new;
		}
		head = new;
	}
	else
	{
		struct node *ptr = head;
		for (int i = 0; i < pos - 2; i++)
		{
			if (ptr->next == NULL)
				break;
			else
				ptr = ptr->next;
		}
		new->prev = ptr;
		new->next = ptr->next;
		if (ptr->next != NULL)
			ptr->next->prev = new;
		ptr->next = new;
		if (ptr == tail)
			tail = new;
		printf("Inserted %d successfully!\n", x);
	}
}
void insertEnd(int x)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = x;
	new->next = NULL;
	new->prev = tail;
	if (head == NULL)
		head = new;
	else
		tail->next = new;
	tail = new;
	printf("Inserted %d successfully!\n", x);
}
void deleteHead()
{
	if (head == NULL)
		printf("List is empty!");
	else
	{
		struct node *temp = head;
		if (head == tail)
		{
			tail = NULL;
			head = NULL;
		}
		else
			head = head->next;
		printf("Deleted %d\n", temp->data);
		free(temp);
	}
}
void deleteAt(int pos)
{
	if (head == NULL)
		printf("Linked list is empty!\n");
	else
	{
		struct node *temp;
		if (pos == 1)
		{
			temp = head;
			head = head->next;
			if (head == NULL)
				tail = NULL;
			else
				head->prev = NULL;
		}
		else
		{
			struct node *ptr = head;
			for (int i = 0; i < pos - 2; i++)
			{
				if (ptr->next == NULL)
				{
					printf("Deletion not possible, Invalid index!\n");
					return;
				}
				else
					ptr = ptr->next;
			}

			temp = ptr->next;
			ptr->next = temp->next;
			if (temp->next == NULL)
				tail = ptr;
			else
				temp->next->prev = ptr;
		}
		printf("Deleted %d successfully!\n", temp->data);
		free(temp);
	}
}
void deleteEnd()
{
	if (head == NULL)
		printf("List is empty!");
	else
	{
		struct node *temp = tail;
		if (head == tail)
		{
			tail = NULL;
			head = NULL;
		}
		else
		{
			tail = tail->prev;
			tail->next = NULL;
		}
		printf("Deleted %d\n", temp->data);
		free(temp);
	}
}
void print()
{
	if (head == NULL)
		printf("List is empty!\n");
	else
	{
		printf("List elements are:\n");
		struct node *ptr = head;
		while (ptr != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->next;
		}
		printf("\n\n");
	}
}
int main()
{
	head = NULL;
	tail = NULL;

	int choice, x, pos;
	while (1)
	{
		printf("Select operation:\n"
			   "1.Insertion at Beginning\t"
			   "2.Insertion at N\t"
			   "3.Insertion at End\n"
			   "4.Deletion at Beginning\t\t"
			   "5.Deletion at N\t\t"
			   "6.Deletion at End\n"
			   "7.Print list\t\t\t"
			   "8.Exit\n");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter the element to be inserted: \n");
			scanf("%d", &x);
			insertHead(x);
			break;
		case 2:
			printf("Enter the position to insert into: \n");
			scanf("%d", &pos);
			printf("Enter the element to be inserted: \n");
			scanf("%d", &x);
			insertAt(x, pos);
			break;
		case 3:
			printf("Enter the element to be inserted: \n");
			scanf("%d", &x);
			insertEnd(x);
			break;
		case 4:
			deleteHead();
			break;
		case 5:
			printf("Enter the position to delete from: \n");
			scanf("%d", &pos);
			deleteAt(pos);
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
			printf("Invalid choice!\n"
				   "Try again.\n");
		}
	}
}