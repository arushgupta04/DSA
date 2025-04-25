//Implement queue using linked list
#include<stdio.h>
#include<stdlib.h>
typedef struct node{
    int data;
    struct node *next;} node;
node *front=NULL,*rear=NULL;
void enqueue(int value){
    node *temp=(node*)malloc(sizeof(node));
    if(temp==NULL){
        printf("Queue Overflow\n");
    }
    else{
        temp->data=value;
        temp->next=NULL;
        if(front == NULL){
            front=rear=temp;
            
        }
        else{
            rear->next=temp;
            rear=temp;
        }
        printf("%d added to queue\n",value);
    }}
int dequeue(){
    if(front==NULL){
        printf("Queue Underflow\n");
        return -1;
    }
    else{
        int value=front->data;
        node* temp=front;
        front =front->next;
        if(front==NULL){
            rear=NULL;
        }
        free(temp);
        return value;

    }
}
void peek(){
    if(front==NULL){
        printf("Queue is empty\n");
    }
    else{
        printf("Front element is %d\n",front->data);
    }
}
void display(){
    if(front==NULL){
        printf("Queue is empty\n");
    }
    else{
        node* temp=front;
        printf("Elements in the queue are: ");
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main(){
    system("cls");
    printf("\n----Queue using linked list----\n");
    printf("1. Enqueue\n2. Dequeue\n3. peek\n4. Display\n5. Exit\n");
    int val, choice;
    while (1){
        printf("Enter your choice: ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter element to be enqueue: ");
                scanf("%d",&val);
                enqueue(val);
                break;
            case 2:
                val=dequeue();
                if(val!=-1){
                    printf("Element dequeued is %d\n",val);
                }
                else{
                    printf("Queue is empty\n");
                }
                break;
            case 3:
                peek();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice!!!\n");
        }
    }
}
