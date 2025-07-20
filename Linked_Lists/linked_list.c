#include <stdio.h>
#include <stdlib.h>

struct Node{

    int data;
    struct Node *next;

};

void print(struct Node *a){

    while(a!=NULL){

        printf("%d ", a->data);
        a= a->next;


    }
}

void free_list(struct Node* head) {
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}


struct Node * insert_at_first(struct Node *head, int data){

    struct Node * new= (struct Node*)malloc(sizeof(struct Node));

    new->data= data;
    new->next= head;

    return new;

}

struct Node * insert_at_last(struct Node *head, int data){
    struct Node * new_node= (struct Node*)malloc(sizeof(struct Node));
    new_node->data= data;
    struct Node * p= head;

    

    while(p->next!=NULL){
        p=p->next;
    }


    p->next= new_node;
    new_node->next= NULL;

    return head;
}

struct Node * insert_at_index(struct Node *head, int data, int index){
    
    if(index==0){
        head=insert_at_first(head,data);
        return head;
    }
   
    struct Node * new_node=  (struct Node*)malloc(sizeof(struct Node));
    new_node->data= data;
    struct Node * p= head;
    int i=0;
    while(i != index-1){
        p=p->next;
        i++;
    }

    new_node->next= p->next;
    p->next= new_node;

    return head;
}

struct Node * delete_first(struct Node *head){

    struct Node *p= head;

    head= head->next;
    free(p);

    return head;
}


struct Node * delete_at_index(struct Node *head, int index){

    struct Node *p= head;
    struct Node *q= head->next;
    int i=0;

    while(i!=index-1){
        p=p->next;
        q=q->next;
        i++;
    }

    p->next= p->next->next;
    free(q);
    return head;

}


struct Node * delete_last(struct Node *head){

    struct Node *p= head;

    while(p->next->next!=NULL){
        p=p->next;
    }
    free(p->next);
    p->next= NULL;

    return head;

}


struct Node * delete_value(struct Node * head, int target){

    struct Node *p= head;
    struct Node *q= head->next;

    if(p->data==target){
        head= delete_first(head);
        
    }
    else{
        while(p->next != NULL && p->next->data != target){
            p=p->next;
            q=q->next;
        }

        if (p->next != NULL) {     
            p->next = p->next->next;
            if (q->data == target)
                free(q);
        }

        
    }
    return head;

}



int main(){

    struct Node *head= (struct Node*)malloc(sizeof(struct Node));
    struct Node *second= (struct Node*)malloc(sizeof(struct Node));
    struct Node *third= (struct Node*)malloc(sizeof(struct Node));

    head->data= 10;
    head->next= second;


    second->data= 20;
    second->next= third;


    third->data= 30;
    third->next= NULL;


    head= insert_at_first(head, 0);
    
    

    head= insert_at_last(head, 40);
    
    head= insert_at_index(head, 99, 3);
    

    head= delete_first(head);

    head= delete_at_index(head, 2);
    
    head= delete_last(head);

    head= delete_value(head, 10);

    print(head);

    free_list(head);

    return 0;

}

