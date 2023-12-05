#include <stdio.h>
#include <stdlib.h>

struct term
{
	int coef, exp;
	 struct term *link;
};

struct term *readpoly()
{
	struct term *ptr;
	int num, c, e;
	struct term *head = NULL;
	printf("Enter the number of terms: \n");
	scanf("%d", &num);
	for (int i = 0; i < num; i++)
	{
		struct term *new = (struct term *)malloc(sizeof(struct term));
		printf("Enter the coefficient of %d term: ", i + 1);
		scanf("%d", &new->coef);
		printf("Enter the exponent of %d term: ", i + 1);
		scanf("%d", &new->exp);
		if (head == NULL)
			head = new;
		else
			ptr->link = new;
		ptr = new;
	}
	return head;
}

struct term *addpoly(struct term *p1, struct term *p2)
{
	struct term *head = NULL;
	struct term *ptr0, *ptr1, *ptr2;
	ptr0 = head;
	ptr1 = p1;
	ptr2 = p2;
	while (ptr1 != NULL && ptr2 != NULL)
	{
		struct term *new = (struct term *)malloc(sizeof(struct term));
		new->link = NULL;
		if (ptr1->exp == ptr2->exp)
		{
			new->coef = ptr1->coef + ptr2->coef;
			new->exp = ptr1->exp;
			ptr1 = ptr1->link;
			ptr2 = ptr2->link;
		}
		else if (ptr1->exp > ptr2->exp)
		{
			new->coef = ptr1->coef;
			new->exp = ptr1->exp;
			ptr1 = ptr1->link;
		}
		else
		{
			new->coef = ptr2->coef;
			new->exp = ptr1->exp;
			ptr2 = ptr2->link;
		}
		if (head == NULL)
		{
			head = new;
			ptr0 = new;
		}
		else
		{
			ptr0->link = new;
			ptr0 = new;
		}
	}

	while (ptr1 != NULL)
	{
		struct term *new = (struct term *)malloc(sizeof(struct term));
		new->link = NULL;
		new->coef = ptr1->coef;
		new->exp = ptr1->exp;
		ptr1 = ptr1->link;
		ptr0->link = new;
		ptr0 = new;
	}

	while (ptr2 != NULL)
	{
		struct term *new = (struct term *)malloc(sizeof(struct term));
		new->link = NULL;
		new->coef = ptr2->coef;
		new->exp = ptr2->exp;
		ptr2 = ptr2->link;
		ptr0->link = new;
		ptr0 = new;
	}
	return head;
}

void display(struct term *head)
{
	if (head != NULL)
	{
		printf("Polynomial: ");
		struct term *ptr = head;
		while (ptr->link != NULL)
		{
			printf("%dX^%d+", ptr->coef, ptr->exp);
			ptr = ptr->link;
		}
		if (ptr->exp == 0)
			printf("%d ", ptr->coef);
		else if (ptr->exp == 1)
			printf("%dX ", ptr->coef);
		else
			printf("%dX^%d", ptr->coef, ptr->exp);
	}
	printf("\n");
}

int main()
{
	struct term *head = NULL;
	struct term *p1 = readpoly();
	display(p1);
	struct term *p2 = readpoly();
	display(p2);
	struct term *res = addpoly(p1, p2);
    printf("\n");
	printf("Sum: ");
	display(res);
}