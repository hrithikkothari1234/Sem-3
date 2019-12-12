//double ended queue : insert rear, remove rear
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
# define size 10

struct dequeue {
int Q[size];
int f,r;
}dq;

void insert_rear(int ele){

    if(dq.r == size-1)
       printf("queue is full\n");
    else if(dq.f==-1 && dq.r==-1){
         dq.f=0;
         dq.r=0;
         dq.Q[dq.r]=ele;
      }
    else{
          dq.r++;
          dq.Q[dq.r]=ele;
      }

}


int remove_rear(){

    int x;
    if(dq.r==-1)
        printf("Underflow \n" );
    else if (dq.f==dq.r){
        x=dq.Q[dq.r];
        dq.f=-1; dq.r=-1;
        return x;
    }
    else{
        x=dq.Q[dq.r];
        dq.r--;
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
    printf("\n Enter 3 to insert element from rear \n Enter 4 to remvove element from rear \n Enter 5 to display the existing elements of queue \n Enter 6 exit the menu\n");
    scanf("%d",&x);
    switch (x) {
      case 3:  printf("Enter element to be inserted from rear \n" );
               scanf("%d",&ele);
               insert_rear(ele);
               display();
               break;
      case 4:y=remove_rear();
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
