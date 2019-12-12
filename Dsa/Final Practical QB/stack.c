// STack push , pop , stacktop , display
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define size 10

int stack[size];
int top=-1;

void push(int ele){

    if(top==-1){
        top=0;
        stack[top++]=ele;
    }
    else if(top==size-1)
        puts("Overflow");
    else
        stack[top++]=ele;
}

int pop(){

    if(top==-1)
        puts("Underflow");
    else{
        return stack[--top];
    }
}

int stacktop(){
    return stack[top-1];
}

void display(){
    int i;
    for(i=0;i<top;i++)
        printf("%d \t",stack[i]);
}

void main(){
    int choice;
    int ele;

    do{
      puts("\n1: Push\n2: Pop\n3: Stacktop\n4: Display Stack\n5: Quit");
      scanf("%d",&choice);

      switch (choice) {
        case 1:puts("Enter ele to push");
              scanf("%d",&ele);
              push(ele);
              break;
        case 2:printf("%d\n",pop());
              break;
        case 3:printf("%d\n",stacktop());
              break;
        case 4:display();
              break;
        case 5:
              break;
        default:
              puts("Invalid choice");
      }
    }while(choice!=5);
}
