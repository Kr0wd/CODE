#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_SIZE 100
#define SIZE 100

int stack[MAX_SIZE];
int top = -1;

void push(int obj)
{
    if (top >= MAX_SIZE - 1)
    {
        printf("Stack overflow!\n");
        exit(-1);
    }
    top++;
    stack[top] = obj;
}

int pop()
{
    if (top < 0)
    {
        printf("Stack underflow!\n");
        exit(-1);
    }
    int del = stack[top];
    top--;
    return del;
}

int type(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^':
        return 0;
    case ' ':
    case '\n':
        return 1;
    default:
        return 2;
    }
}
int evaluate(char symbol, int x, int y)
{
    switch (symbol)
    {
    case '+':
        return y + x;

    case '-':
        return y - x;

    case '*':
        return y * x;

    case '/':
        return y / x;

    case '^':
        return pow(y, x);

    default:
        printf("Invalid operator error!\n");
        exit(-1);
    }
}

int int_of(char num)
{
    if (num >= '0' && num <= '9')
        return num - '0';

    else
    {
        printf("Character '%c' is not a digit.\n", num);
        exit(-1);
    }
}

int main()
{
    char postfix[SIZE];

    printf("Enter postfix representation :");
    gets(postfix);
    printf("You have entered: %s\n", postfix);

    int i = 0;
    char symbol;
    while ((symbol = postfix[i]) != '\0' && symbol != '\n')
    {
        switch (type_of(symbol))
        {
        case operator:
            push(evaluate(symbol, pop(), pop()));
            break;

        case operand:
            push(int_of(symbol));
            break;
        }
        i++;
    }

    printf("The evaluvation of the postfix expression is: %d\n", pop());

    return 0;
}