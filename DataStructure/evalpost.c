#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define SIZE 100
int top=-1;
int i;
char stack[SIZE],postfix[SIZE],symbol;
char pop()
{
    if (top>0)
            printf("underflow\n");
    else
    {
        top--;
        return stack[top+1];
    }
        
}
void push(char symbol)
{
    if (top>=SIZE-1)
        printf("overflow\n");
    else
    {
        top++;
        stack[top]=(symbol-'0');
        puts(stack);
    }
}
int types(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
    case '*':
    case '/':
    case '^':
        return 1;
        break;
    default:
        return 0;
        break;
    }
}
int evaluate (char symbol, int y, int x)
{
    switch (symbol)
    {
    case '+':
        return (x+y);
        break;
    case '-':
        return (x-y);
        break;
    case '*':
        return (x*y);
        break;
    case '/':
        return (x/y);
        break;
    case '^':
        return pow(x,y);
        break;
    default:
        break;
    }
}
void main()
{   //int i,n;
    printf("enter");
    gets(postfix);
    int i=0;
    while ((symbol = postfix[i]) != '\0' && symbol != '\n')
    {
        switch (types(symbol))
        {
        case '0':
            push(symbol);
            break;
        case '1':
            push(evaluate(symbol,pop(),pop()));
            break;
        default:
            break;
        }
    i++;
    }
    printf("The evaluvation of the postfix expression %s is: %d\n", postfix, pop());
}