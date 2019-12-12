#include<stdio.h>
#include<string.h>
#include<ctype.h>
# define size 5
int r=-1,f=-1;
int queue[size];

void insert(int ele){

   if(f==-1 && r==-1){
     f=r=0;
     queue[r]=ele;
    }
    else if(r==4)
        printf("queue is full\n");
    else{
      r++;
      queue[r]=ele;
    }
}

int rem(){

      if(f==r && r==-1)
          printf("q is empty\n" );
      else if(f==r){
          int a=queue[f];
          f=-1;
          r=-1;
          return a;
      }
      else
          return queue[f++];
}

void display(){
    int i;
    for(i=f;i<=r;i++)
        printf("%d\n",queue[i]);
}

void main()
{
  int x,ele,y;

    do{
    printf("\n1: Insert\n2: Remove\n3: Display\n4: Exit\n");
    scanf("%d",&x);
      switch (x) {
        case 1 : printf("Enter the element to be inserted");
                 scanf("%d",&ele);
                 insert(ele);
                 display();
                 break;
        case 2: y=rem();
                printf("REmoved element was % d\n",y );
                 break;
        case 3: display();
                break;
        case 4: printf("Exitting the menu :) \n" );
                 break;
        default : printf("invalid option\n" );
          }
    }while(x!=4);
}
