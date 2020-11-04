//
//  Linked list operation.c
//  
//
#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};

struct node* insert(struct node* head,int n){           /* We have to insert the elements from the end */
    if(head==NULL){
        head = (struct node*) malloc(sizeof(struct node));      /* We are allocating */
        head->data=n;                                           /* Put in data */
        head->next=NULL;
        return head;
    }
    struct node* temp=head;
    while(temp->next){
        temp=temp->next;
    }
    struct node *ptr = (struct node*) malloc(sizeof(struct node));
    ptr->data=n;
    ptr->next=NULL;
    temp->next=ptr;
    return head;
}

struct node* reverse(struct node* head){                /* We have to reverse the elements of the linked list */
    struct node* prev=NULL;
    while(head){
        struct node* temp=head->next;
        head->next=prev;
        prev=head;
        head=temp;
    }
    return prev;
}

void sum(struct node* head){            /* we are adding each element of the list */
    long int sum=0;
    while(head){
        sum+=head->data;
        head=head->next;
    }
    printf("%ld\n",sum);
}
void print(struct node* head){
    while(head){
        printf("%d\t",head->data);
        head=head->next;
    }
}

int main(){
    struct node* head=NULL;
    int t;
    float count=0;
    while((scanf("%d",&t)==1)){
        head=insert(head,t);
        count+=t;
    }
    head=reverse(head);
    sum(head);
    print(head);
    return 0;
}
