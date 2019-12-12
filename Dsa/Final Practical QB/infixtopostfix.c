// infix to postfix
#include<stdio.h>
#include<ctype.h>
#include<string.h>

char stack[20];
int top = -1;

void push(char x){
    stack[++top] = x;
}

char pop(){

    if(top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x){

    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    else
        return 0;
}

void main()
{
    char infix[20],x;
    int i=0,j=0;
    printf("Enter the expression :: ");
    scanf("%s",infix);
    int len  = strlen(infix);
    char postfix[len];

    while(i<len)
    {
        if(isalnum(infix[i]))
            postfix[j++]=infix[i];
        else if(infix[i] == '(')
            push(infix[i]);
        else if(infix[i] == ')')
        {
            while((x = pop()) != '(')
                  postfix[j++]=x;
        }
        else
        {
            while(priority(stack[top]) >= priority(infix[i]))
                postfix[j++]=pop();
            push(infix[i]);
        }
        i++;
    }
    while(top != -1)
        postfix[j++]=pop();

    for(i=0;i<j;i++)
        printf("%c",postfix[i]);
}
