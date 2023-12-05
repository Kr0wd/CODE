#include <stdio.h>
#include <stdlib.h>

 struct node
{
	int data;
	struct node *link;
} ;

struct node *front = NULL, *rear = NULL;

void enqueue(int item)
{
	struct node *new = (struct node *)malloc(sizeof(struct node));
	new->data = item;
	new->link = NULL;
	if (front == NULL)
		front = new;
	else
		rear->link = new;
	rear = new;
}

void dequeue()
{
	if (front == NULL)
		printf("Queue is empty!\n");
	else
	{
		struct node *temp = front;
		printf("Deleted: %d\n", temp->data);
		if (front->link == NULL)
		{
			front = NULL;
			rear = NULL;
		}
		else
			front = front->link;
		free(temp);
	}
}

void print()
{
	if (front == NULL)
		printf("Queue is empty!\n");
	else
	{
		printf("\nQueue elements are:\t");
		struct node *ptr = front;
		while (ptr->link != NULL)
		{
			printf("%d\t", ptr->data);
			ptr = ptr->link;
		}
		printf("%d\n", ptr->data);
	}
}

int main()
{
	int item, choice;
	while (1)
	{
		printf("Operations\n"
			   "1. Enqueue\t2. Dequeue\n"
			   "3. Print queue items\t4. Exit\n"
			   "\nEnter the choice:");
		scanf("%d", &choice);
		switch (choice)
		{
		case 1:
			printf("Enter element to be inserted:\n");
			scanf("%d", &item);
			enqueue(item);
			break;

		case 2:
			dequeue();
			break;

		case 3:
			print();
			break;

		case 4:
			return 0;

		default:
			printf("Invalid choice\n");
		}
	}
}