#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
    int front;
    int rear;
    int size;
    int *arr;
};

bool is_full(struct queue *q){
    if(q->rear==q->size-1){
        return true;
    }
    return false;
}

bool is_empty(struct queue *q){
    if(q->front==q->rear){
        return true;
    }
    return false;
}


void enque(struct queue* q, int data){

    if(is_full(q)){
        printf("Queue is full\n");
        
    }
    else{
    q->rear++;
    q->arr[q->rear]=data;
    }
}

int dequeue(struct queue* q){
    int a;

    if(is_empty(q)){
        printf("Queue is Empty\n");
        return -1;
    }
    else{
        q->front++;
        a= q->arr[q->front];
        return a;
    }
}

void peek(struct queue* q, int index) {
    int pos = q->front + 1 + index;

    if (is_empty(q)) {
        printf("Queue is empty\n");
    }
    
    else if (pos > q->rear || index < 0) {
        printf("Invalid index\n");
    } 
    
    else {
        printf("Element at index %d = %d\n", index, q->arr[pos]);
    }
}


    





int main(){

    struct queue *q= (struct queue*)malloc(sizeof(struct queue));

    q->front= -1;
    q->rear=-1;
    q->size= 5;
    q->arr= (int*)malloc(q->size * sizeof(int));


    enque(q, 10);
    enque(q, 20);
    enque(q,30);
    enque(q,40);
    
    printf("removed:%d\n",dequeue(q));
    printf("removed:%d\n",dequeue(q));
    printf("removed:%d\n",dequeue(q));
    enque(q,50);
    peek(q,2);
    


}