#include<stdio.h>
#include<string.h>

int stack[20];
int top1=-1,top2=20;

void push(int ele,int stacknumber){

    if(top2-top1==1)
        puts("Overflow\n" );
    else{
        if(stacknumber==1)
            stack[++top1]=ele;
        else
          stack[--top2]=ele;
      }

}

void pop(int stacknumber){

    if(stacknumber==1){
        if(top1==-1)
            puts("underflow\n");
        else
            printf("popped element is %d\n",stack[top1--]);
    }
    else{
        if(top2==20)
            puts("Underflow\n");
        else
            printf("popped element is %d\n",stack[top2++]);
    }

}

void display(){
    int i;
    puts("\nCurrent stack 1 is : " );
    for(i=0;i<=top1;i++)
        printf("%d \t",stack[i]);

    puts("\nCurrent stack 2is : " );
    for(i=19;i>=top2;i--)
        printf("%d \t",stack[i]);
}

void main(){
    int choice,ele,stacknumber;

    do{
        printf("\n1: Push\n2: Pop\n3: Display\n4: Exit");
        scanf("%d",&choice);
        switch (choice){

          case 1:
                puts("Enter element and stack number");
                scanf("%d %d",&ele,&stacknumber);
                if(stacknumber!=1 && stacknumber!=2)
                    puts("invalid stack number");
                else
                    push(ele,stacknumber);
                break;
          case 2:
                puts("Enter stack number");
                scanf("%d",&stacknumber);
                if(stacknumber!=1 && stacknumber!=2)
                    puts("invalid stack number");
                else
                    pop(stacknumber);
                break;
          case 3:
                display();
                break;
          case 4:
                puts("bye\n");
                break;
          default:
                puts("invalid option \n" );
          }
      }while (choice!=4);
}
