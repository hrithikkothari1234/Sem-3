// Singly Linked List
// Operations : Insert , delete , Reverse , display , split , copy , concat
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

struct node * insert(struct node * head){

    if(head == NULL){
        head = createnode();
        puts("Enter Data");
        scanf("%d",&head->data);
    }
    else{
        struct node * temp;
        temp=head;
        while(temp->next != NULL)
            temp=temp->next;
        temp->next = createnode();
        temp = temp->next;
        puts("Enter Data");
        scanf("%d",&temp->data);
    }
  return head;
}

struct node * delete(struct node * head, int ele){

    if(head==NULL)
        puts("List empty");
    else{
      struct node * temp1, * temp2;
      temp1=head;
      while(temp1!=NULL){
          if(temp1->data == ele){
              puts("Element found");
              break;
          }
          temp2=temp1;
          temp1=temp1->next;
      }

      if(temp1 == head){
          head=head->next;
          free(temp1);
      }
      else{
          temp2->next = temp1->next;
          free(temp1);
      }
    }

  return head;
}

struct node * reverse(struct node * head){

    struct node * p=NULL, * q=head, * r=q->next;

    while(q!=NULL){
        q->next=p;
        p=q;
        q=r;
         if(q!=NULL)
              r=q->next;
     }

  return p;
}

void split(struct node * head2,struct node * head1){

    int posi;
    puts("Enter posi to split at");
    scanf("%d",&posi);
    struct node * temp=head2;
    head1 = NULL;

    int i=1;
    while(i<posi){
        temp = temp->next;
        i++;
    }
    head1 = temp->next;
    temp->next = NULL;

    display(head1);
    printf("\n");
    display(head2);
    printf("\n");
}

struct node* concat(struct node* head1,struct node* head2){
    struct node* tmp;
    tmp=head1;
    while(tmp->next!=NULL)
        tmp=tmp->next;
    tmp->next=head2;
    return head1;
}


struct node * copy(struct node * head, struct node * head1){

    if(head==NULL)
        return head;
    else{
        struct node * temp=head;

        head1=createnode();
        head1->data=head->data;

        struct node * temp1=head1;
        while(temp->next!=NULL){
            temp1->next=createnode();
            temp1->data=temp->data;
            temp=temp->next;
            temp1=temp1->next;
        }
        temp1->data=temp->data;
        return head1;
    }
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
    struct node * head,* head1;
    head = NULL;
    int choice;
    int del;
    do{
      puts("\n1 : Insert \n2: Delete \n3: Reverse \n4: Display\n5: Split\n6: Copy \n7: Quit");
      scanf("%d",&choice);
      switch (choice) {
        case 1:
              head = insert(head);
              break;
        case 2:
              puts("Enter element to be deleted");
              scanf("%d",&del);
              head = delete(head,del);
              break;
        case 3:
              head = reverse(head);
              break;
        case 4:
              display(head);
              break;
        case 5:
              split(head,head1);
              break;
        case 6:
              head1=copy(head,head1); // copy head to head1
              display(head1);
              break;
        case 7:
              puts("Exitting..");
              break;
        default: puts("Invalid choice");
      }

    }while(choice!=7);
}
