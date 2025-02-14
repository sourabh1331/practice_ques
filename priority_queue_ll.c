#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    int priority;
    struct node*next;
}node;

typedef struct priorityQueue{
    node*front;
    int size;
}priorityQueue;

void init(priorityQueue*q){
    q->front=NULL;
    q->size=0;
}

int isEmpty(priorityQueue*q){
    return q->size==0;
}

node*createNode(int data,int priority){
    node*newnode=(node*)malloc(sizeof(node));
    newnode->data=data;
    newnode->priority=priority;
    newnode->next=NULL;

    return newnode;
}

void enqueue(priorityQueue*q,int data,int priority){
    node*newnode=createNode(data,priority);
    if(q->front==NULL){
        q->front=newnode;
    }
    else if(q->front->priority>priority){
        newnode->next=q->front;
        q->front=newnode;
    
    }
    else{
        node*temp=q->front;
        while(temp->next!=NULL && temp->next->priority<=priority){
            temp=temp->next;
        }
        newnode->next=temp->next;
        temp->next=newnode;
    }
    q->size++;
}

int dequeue(priorityQueue*q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    node*temp=q->front;
    int data=temp->data;
    q->front=q->front->next;
    free(temp);
    q->size--;
    return data;
}

int getsize(priorityQueue*q){
    return q->size;
}

void display(priorityQueue*q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return;
    }
    node*temp=q->front;
    while(temp!=NULL){
        printf("%d (Priority: %d) ",temp->data,temp->priority);
        temp=temp->next;
    }
    printf("\n");
}

int main(){
    priorityQueue*pq=(priorityQueue*)malloc(sizeof(priorityQueue));
    init(pq);
    enqueue(pq,10,1);
    enqueue(pq,20,2);
    enqueue(pq,30,3);
    enqueue(pq,40,2);
    enqueue(pq,50,1);

    printf("Priority Queue: ");
    display(pq);
    printf("Queue size: %d\n", getsize(pq));

    printf("Dequeued: %d\n", dequeue(pq));
    printf("After dequeuing: ");
    display(pq);
    printf("Queue size: %d\n", getsize(pq));

    return 0;

}