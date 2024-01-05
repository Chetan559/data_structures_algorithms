// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node *head=NULL;

struct node *createnode(int data){
    struct node *newnode;
    newnode = (struct node*)malloc(sizeof(struct node));
    newnode->data=data;
    newnode->next=NULL;
    return newnode;
}

void insert(){
    int data;
    struct node *newnode;
    printf("enter data\n");
    scanf("%d",&data);
    newnode = createnode(data);
    if(head==NULL){
        head = newnode;
    }
    else{
        newnode->next = head;
        head = newnode;
    }
};

void display(){
    if(head==NULL){
        printf("underflow\n");
    }
    else{
        struct node *temp;
        temp=head;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}

void delatend(){
    if(head==NULL){
        printf("underflow\n");
    }
    else if(head->next==NULL){
        struct node *temp;
        temp=head;
        head=NULL;
        printf("%d deleted \n", temp->data);
        free(temp);
    }
    else{
        struct node *temp;
        struct node *temp1;
        temp=head;
        while(temp->next!=NULL){
            temp1=temp;
            temp=temp->next;
        }
        temp1->next=NULL;
        printf("%d deleted \n",temp->data);
        free(temp);
    }
}

int main() {
    int choice;
    do{
        printf(" 1.add at front\n2. delete from end\n3. display all elements\n0. exit\n");
        scanf("%d",&choice);
        switch(choice){
            case 1:
            insert();
            break;
            case 2:
            delatend();
            break ;
            case 3:
            display();
            break;
            default:
            printf("Invalid number\n");
        }
    }while(choice!=0);
    return 0;
}