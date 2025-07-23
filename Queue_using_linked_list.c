#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node{

    int data;
    struct Node* next;
};

struct Node* front= NULL;
struct Node* rear= NULL;

void print(struct Node *a){

    while(a!=NULL){

        printf("%d ", a->data);
        a= a->next;


    }
}


bool is_full(){

    struct Node *n= (struct Node*)malloc(sizeof(struct Node));

    if(n==NULL){
        return true;
    }
    free(n);
    return false;

}


void enqueue(int data){

    if(is_full()){
        printf("Queue is full\n");
    }
    
    else{
        struct Node* new= (struct Node*)malloc(sizeof(struct Node));

        new->data=data;

        if(front==NULL){
            front=new;
            rear=new;

            new->next=NULL;

        }
    
        else{
            new->next=NULL;
            rear->next=new;
            rear=new;
        }    
    }
}

bool is_empty(){
    if(front==NULL){
        return true;
    }
    return false;
}

int dequeue(){

    int a;

    if(is_empty()){
        printf("Queue is empty");
        return -1;
    }
    else{
        struct Node* ptr= front;

        a= front->data;
        front=front->next;

        free(ptr);

        return a;

    }
}




int main(){

    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    enqueue(60);

    dequeue();
    dequeue();
    dequeue();

    enqueue(70);
    enqueue(80);
    enqueue(90);


    print(front);
    
}