#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
    
};

void print(struct Node* head){
    struct Node* p = head;

    
    while(p!=NULL){
        printf("%d ", p->data);
        p=p->next;
    }
}


struct Node* insert_at_first(struct Node* head, int data){
    struct Node* new= (struct Node*)malloc(sizeof(struct Node));

    new->data= data;

    new->next= head;
    new->prev= NULL;
    if (head != NULL){
         head->prev = new;
    }
    head= new;

    return head;


}

struct Node* insert_at_last(struct Node* head, int data){
    
    if (head == NULL) 
        return insert_at_first(head, data);
    
    struct Node* new= (struct Node*)malloc(sizeof(struct Node));
    new->data= data;
    

    struct Node* p= head;

    while(p->next!=NULL){
        p=p->next;

    }

    p->next = new;
    new->prev = p;   
    new->next = NULL;

    return head;

}


struct Node* insert_at_index(struct Node* head, int data, int index){
    
    if (head == NULL) 
        return NULL;
    
    if (index == 0) 
        return insert_at_first(head, data);
    
    struct Node* new= (struct Node*)malloc(sizeof(struct Node));
    new->data= data;
    
    struct Node* p= head;
    int i=0;

    while(i!=index-1){
        p=p->next;
        i++;
    }

    new->next=p->next;
    p->next->prev= new;
    p->next= new;
    new->prev=p;


    return head;

}

struct Node* delete_first(struct Node* head){
    
    if (head == NULL) 
        return NULL;
    
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    
    struct Node* p= head;
    struct Node* q= head;
    p= head->next;

    p->prev= NULL;
    free(q);

    head=p;


    return head;
}

struct Node* delete_last(struct Node* head){
    
    if (head == NULL) 
        return NULL;
    
    if (head->next == NULL) {
        free(head);
        return NULL;
    }
    
    struct Node* p= head;

    while(p->next!=NULL){
        p=p->next;
        
    }

    p->prev->next= NULL;
    free(p);

    return head;



}


struct Node* delete_val(struct Node* head, int target){
    if (head == NULL) 
        return NULL;
    struct Node* p = head;

    while (p != NULL && p->data != target) 
        p = p->next;

    if (p == NULL) 
        return head; 
    
    if (p->prev != NULL) 
        p->prev->next = p->next;
    else 
        head = p->next; 

    if (p->next != NULL) 
        p->next->prev = p->prev;

    free(p);
    
    
    return head;




}


int main(){
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* second = (struct Node*)malloc(sizeof(struct Node));
    struct Node* third = (struct Node*)malloc(sizeof(struct Node));

    head->data = 10;
    second->data = 20;
    third->data = 30;

    head->next = second;
    head->prev= NULL;
    
    second->next = third;
    second->prev= head;


    third->next = NULL;
    third->prev= second;

    head= insert_at_first(head,0);

    head= insert_at_last(head, 40);

    head= insert_at_index(head,25,3);
    
    head= delete_first(head);

    head= delete_last(head);
    
    head= delete_val(head, 25);
    
    print(head);


}