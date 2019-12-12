// insert and delete at specific posi.

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node{
    int data;
    struct node * next;
};

struct node * createnode(){
    struct node * newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    newnode->next=NULL;
    return newnode;
}

struct node * insert_at_posi(struct node * head,int posi){

    if(head==NULL){
        head=createnode();
        puts("Enter data");
        scanf("%d",&head->data);
    }else if(posi==1){
        struct node * newnode;
        newnode=createnode();
        puts("Enter data");
        scanf("%d",&newnode->data);
        newnode->next=head;
        head=newnode;
    }
    else{
        struct node * temp=head,* newnode;
        newnode=createnode();
        puts("Enter data");
        scanf("%d",&newnode->data);
        int i=1;

        while(i<posi-1){
            if(temp->next!=NULL)
                temp=temp->next;
            i++;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }

  return head;
}

struct node * remove_at_posi(struct node * head,int posi){

    if(head==NULL)
        puts("Empty LL");
    else if(posi==1){
        struct node * temp=head;
        head=head->next;
        free(temp);
    }
    else{
        struct node * temp=head;
        int i=1;
        while(i<posi-1){
            if(temp->next!=NULL)
                temp=temp->next;
            i++;
        }
        if(temp->next!=NULL)
          {
            struct node * temp1=temp->next;
            temp->next=temp1->next;
            free(temp1);
          }

    }

  return head;
}


void display(struct node * head){

    struct node * temp;
    temp=head;
    while(temp!=NULL){
        printf("%d \t",temp->data);
        temp=temp->next;
    }

}

void main(){
    int choice;
    int posi;
    struct node * head=NULL;
    do{
      puts("\n1: Insert at posi\n2: Remove from posi\n3: Display\n4: Exit");
      scanf("%d",&choice);

      switch (choice) {
        case 1:
              puts("Enter posi");
              scanf("%d",&posi);
              head=insert_at_posi(head,posi);
              break;
        case 2:
              puts("Enter posi");
              scanf("%d",&posi);
              head=remove_at_posi(head,posi);
              break;
        case 3:
              display(head);
              break;
        case 4:puts("Bye");
              break;
        default:puts("Invalid");
      }
    }while(choice!=4);
}
