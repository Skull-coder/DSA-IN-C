#include <stdio.h>
#include <string.h>
#include<stdlib.h>



struct Task{

    char data[100];
    struct Task* next;
};

struct Task* head=NULL;
struct Task* tail= NULL;

void create_task(char data[]){

    struct Task* new= (struct Task*)malloc(sizeof(struct Task));

    if(new==NULL){
        
        printf("Can't add more task first finish privious TASKS");
    }

    else{

        strcpy(new->data, data);
        new->next = NULL;
        
        if (head==NULL){

            head=tail=new;
            
        }
        
        else{

            tail->next=new;
            tail=new;
        }
    }

} 


void delete_task(int index) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Task* temp = head;

    
    if (index == 1) {
        head = temp->next;
        free(temp);

        
        if (head == NULL) {
            tail = NULL;
        }
        
        return;
    }

    struct Task* prev = NULL;
    int i = 1;

    
    while (temp != NULL && i < index) {
        prev = temp;
        temp = temp->next;
        i++;
    }

    
    if (temp == NULL) {
        printf("Index %d is out of range.\n", index);
        return;
    }
    
    prev->next = temp->next;

    
    if (temp == tail) {
        tail = prev;
    }

    free(temp);
    
}



void Display(){

    int index=1;
    struct Task* ptr= head;
    while(ptr!=NULL){
        printf("%d) %s\n", index,ptr->data);
        index++;
        ptr=ptr->next;
    }
}

void edit(int index, char data[]){

    delete_task(index);

    int i=1;

    struct Task* new= (struct Task*)malloc(sizeof(struct Task));
    strcpy(new->data, data);
    
    struct Task* ptr=head;

    if(index==1){
        
        new->next=head;
        head=new;
        return;
    }


    while(i<index-1){

        ptr=ptr->next;
        i++;
    }

    new->next=ptr->next;
    ptr->next=new;

}








int main() {
    
    int n;
    printf("How many task you have today?");
    scanf("%d", &n);
            
            
    for(int i=0; i< n; i++){

        char data[100];
        printf("write your task no. %d  ", i+1);
        scanf("%s", data);

        create_task(data);
    }
    
    
    
    int choice;

    while (1) {
        printf("\n----Task Manager----\n");
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Delete task\n");
        printf("4. View Tasks\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        

        switch (choice) {
            case 1: {

                int n;
                printf("How many task you have today?");
                scanf("%d", &n);
            
            
                for(int i=0; i< n; i++){

                char data[100];
                printf("write your task no. %d  ", i+1);
                scanf("%s", data);

                create_task(data);    
            }
                break;
            }

            case 2: {
                int n;
                printf("which task no. to edit ?");
                scanf("%d", &n);

                char data[100];
                printf("provide new edited-task ");
                scanf("%s", data);

                edit(n, data);
                break;
            }

            case 3: {
                int d;
                printf("which task no. to delete? ");
                scanf("%d", &d);
                delete_task(d);
                break;
            }

            case 4:
                Display();
                break;

            case 5:
                printf("Exiting Task Manager...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}
