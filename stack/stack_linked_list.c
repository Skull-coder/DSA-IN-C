#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct Node{
    int data;
    struct Node* next;
};

void print_stack(struct Node* top){

    struct Node* p=top;

    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}



bool is_empty(struct Node*top){

    if(top==NULL){
        return true;
    }
    return false;
}

bool is_full() {
    struct Node* p = (struct Node*)malloc(sizeof(struct Node));
    if (p == NULL) {
        return true;
    }
    free(p);  
    return false;
}




struct Node* push(struct Node* top ,int data){
    if(is_full(top)){
        printf("stack is full push can't be done\n");
        return top;
    }

    struct Node* new= (struct Node*)malloc(sizeof(struct Node));
    new->data= data;
    new->next=top;

    top=new;

    return top;

}

struct Node* pop(struct Node* top, int* val) {
    if (is_empty(top)) {
        printf("stack is empty, pop can't be done\n");
        *val = -1;
        return top;
    }

    struct Node* p = top;
    *val = p->data;
    top = top->next;
    free(p);
    return top;
}

int peek(struct Node* top,int pos){
    struct Node* ptr= top;

    for(int i=0; i<(pos-1 && ptr!=NULL); i++){
        ptr=ptr->next;
    }
    if(ptr!=NULL){
        return ptr->data;
    }
    return -1;
}

int main(){
    struct Node* top=NULL;
    int pop_value;
    top= push(top, 10);
    top= push(top, 20);
    top= push(top, 30);
    top= push(top, 40);
    top=pop(top, &pop_value);
    // printf("popped element:%d\n",pop_value);

    // print_stack(top);
    printf("%d", peek(top, 1));
}











