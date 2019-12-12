//double ended queue : insert front , remove front
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
# define size 5

struct dequeue {
int Q[size];
int f,r;
}dq;

void insert_front(int ele){

    if(dq.r == size-1 || dq.f==dq.r+1)
       printf("queue is full\n");
    else if(dq.f==-1 && dq.r==-1){
         dq.f=0;
         dq.r=0;
         dq.Q[dq.f]=ele;
      }
    else{
          if(dq.f==0)
              dq.f=size-1;
          else
              dq.f--;

          dq.Q[dq.f]=ele;
      }

}


int remove_front(){

    int x;
    if(dq.r==-1 && dq.f==-1)
        printf("Underflow \n" );
    else if (dq.f==dq.r){
        x=dq.Q[dq.f];
        dq.f=-1; dq.r=-1;
        return x;
    }
    else{
        x=dq.Q[dq.f];
        dq.f=(dq.f+1)%size;
        return x;
    }

}

void display(){
      int i;
      for(i=dq.f;i!=dq.r;i=(i+1)%size)
          printf("%d\t",dq.Q[i]);
      printf("%d\t",dq.Q[i]);
}

void main()
  {
    dq.f=-1;
    dq.r=-1;
    int x,ele,y;
    do{
    printf("\n Enter 3 to insert element from front \n Enter 4 to remvove element from front \n Enter 5 to display the existing elements of queue \n Enter 6 exit the menu\n");
    scanf("%d",&x);
    switch (x) {
      case 3:  printf("Enter element to be inserted from front \n" );
               scanf("%d",&ele);
               insert_front(ele);
               display();
               break;
      case 4:y=remove_front();
               printf("Removed element was %d\n",y );
               break;
      case 5:  display();
               break;
      case 6:  printf("Exitting the menu :) \n" );
               break;
      default: printf("invalid option\n" );
    }
  }
  while(x!=6);
}
