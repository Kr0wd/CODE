#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 50
int top=-1;
int top_post = -1;
void push(char symbol);
char pop();
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
void posteval()
{
    int result,i,x,y,val;
    for (i = 0; i < strlen(post); i++)
    {
        if((65<=post[i]&&post[i]<=90)||(97<=post[i]&&post[i]<=122))
        {
            printf("Enter the value of %c :",post[i]);
            scanf("%d",&val);
            push(val);
        }
        else
        {
            y =pop();
            x =pop();
            switch (post[i])
            {
            case '+': 
                    push(x+y);
                    break;
            case '-': 
                    push(x-y);
                    break;
            case '*': 
                    push(x*y);
                    break;
            case '/': 
                    push(x/y);
                    break;
            case '^': 
                    push(pow(x,y));
                    break;
            }
        }
    }
    result=pop();
    printf("Result = %d\n",result);
}
void postfix()
{
    char del,symbol;    
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
                    while (top > -1 && precedence(stack[top]) >= precedence(symbol))
                    {
                        append(pop());
                    }
                    push(symbol);
                    break;
            case '^':
                    while (top > -1 && precedence(stack[top]) > precedence(symbol))
                    {
                        append(pop());
                    }
                    push(symbol);
                    break;
            case '(':
                    push(symbol);
                    break;
            case ')':
                    while((del = pop()) != '(')
                        append(del);
                    break;
            default:
                append(symbol);
            }
        }
    while(top>-1)
        append(pop());
    append('\0');
    puts(post); 
}
void main()
{
    printf("Enter the infix expression\n");
    gets(infix);
    printf("Postfix expression : ");
    postfix(infix);
    posteval();
}