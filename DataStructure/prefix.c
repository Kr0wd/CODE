#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 100
int top=-1,top_post = -1;
char stack[SIZE],infix[SIZE],post[SIZE],a;
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
int highest_precedence()
{
    int high = 0;
    for (int i = top; i >= 0; i--)
    {
        char symbol = stack[i];
        if (symbol == ')')
            break;
        int now = precedence(symbol);
        if (now != -1)
        {

            if (now > high)
                high = now;
        }
    }
    return high;
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
        top_post++;
        post[top_post]=symbol;
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
                    while (top != -1 && highest_precedence()>precedence(symbol))
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
    reverse(post);
    for(int i=0;i<top_post;i++)
        {
        printf("%c  ",post[i]);
        }
        printf("\n");
return 0;
}