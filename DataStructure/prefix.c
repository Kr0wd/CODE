#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int top=-1,top_pre = -1;
char stack[SIZE],infix[SIZE],pre[SIZE],a;
int precedence(char symbol)
{
    switch (symbol)
    {
    case '+':
    case '-':
        return 1;

    case '*':
    case '/':
        return 2;

    case '^':
        return 3;
    default:
        return -1;
    }
}
void push(char symbol)
{
    if(top>=SIZE-1)
    {
        printf("overflow");
        exit(1);
    }
    else
    {
        top++;
        stack[top]=symbol;
    }
}
char pop()
{
    if (top<0)
        printf("underflow\n");
    else 
    {
        top--;
        return stack[top+1];
    }
}
void append(char symbol)
{
    if(top>=SIZE-1)
    {
        printf("overflow\n");
        exit(1);
    }
    else
    {
        top_pre++;
        pre[top_pre]=symbol;
    }
}
void reverse(char str[])
{
    int i,n;
    n=strlen(str);
    for(i=0;i<n/2;i++)
    {
        char c=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=c;
    }
}

int main()
{
    char del;
    printf("enter the infix expression:\n");
    gets(infix);
    reverse(infix);
    int len=strlen(infix);
    for (int i=0;i<len;i++)
        {
            char symbol=infix[i];
            switch (symbol)
            {
            case '+':
            case '-':
            case '*':
            case '/':
            case '^':
                    while (top > -1 && precedence(stack[top]) > precedence(symbol))
                    {
                        append(pop());
                    }
                    push(symbol);
                    break;
            case ')':
                    push(symbol);
                    break;
            case '(':
                    while((del = pop()) != ')') 
                        append(del);
                    break;
            default:
                append(symbol);
            }
        }
    while(top>-1)
        append(pop());
    append('\0');
    reverse(pre);
    printf("the resultant prefix expression is :\n");
    for(int i=0;i<top_pre;i++)
        {
        printf("%c  ",pre[i]);
        }
        printf("\n");
return 0;
}