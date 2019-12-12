// Postfix Evaluation using array
#include<stdio.h>
#include<ctype.h>
#include<string.h>
# define size 15

char stack[size];
int top=-1;

void push(char ele){
    stack[++top]=ele;
}

char pop(){
    return stack[top--];
}

int evaluate(char postfix[]){
    int i=0;
    int x,y,result;

    while(i<strlen(postfix)){

        if(isalnum(postfix[i]))
            push(postfix[i]-'0'); // convert char to int
        else{
            x=pop();
            y=pop();

            switch (postfix[i]) {
              case '*': result = x*y;
                        break;
              case '/': result = x/y;
                        break;
              case '+': result = x+y;
                        break;
              case '-': result = x-y;
                        break;
              default:
                        puts("invalid");

            }
          push(result);
        }
        i++;
    }
  return pop();
}

void main(){
    puts("Enter Postfix Expn : ");
    char postfix[size];
    gets(postfix);

    int result = evaluate(postfix);
    printf("\nResult is : %d",result);
}
