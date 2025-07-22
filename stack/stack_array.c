#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct Stack{
    int size;
    int top;
    int *arr;
};

bool is_full(struct Stack* p){

    if(p->size-1==p->top){
        // printf("Full\n");
        return true;
    }
    // printf("NOT FULL\n");
    return false;

}


bool is_empty(struct Stack *p){

    if(p->top==-1){
        // printf("EMPTY\n");
        return true;
    }
    // printf("Not EMPTY\n");
    return false;
}


int pop(struct Stack*p){

    if(p->top==-1){
        return -1;
    }
        
    int top_value= p->arr[p->top];
    p->top--;
    return top_value;
}

int push(struct Stack *p, int data){

    if (is_full(p)){
        return -1;
    }

    p->top++;

    p->arr[p->top]=data;

    return 1;
}

void peak(struct Stack *p){

    if(is_empty(p)){
        printf("stack is empty\n");
    }
    else{
    printf("%d\n",p->arr[p->top]);
    }
}



int main(){

    struct Stack* p= (struct Stack*)malloc(sizeof(struct Stack));

    p->size= 5;
    p->top=-1;

    p->arr= (int*)malloc(p->size * sizeof(int));

    push(p, 10);
    push(p, 10);
    push(p, 10);
    push(p, 10);
    push(p, 500);
    printf("removed:%d\n", pop(p));
    peak(p);

    printf("empty:%d\n",is_empty(p));
    printf("full:%d\n",is_full(p));

}