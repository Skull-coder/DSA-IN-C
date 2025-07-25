#include <stdio.h>
#include <string.h>
#include<stdlib.h>



struct Task{

    char data[100];
    struct Task* next;
};

struct Task* head=NULL;
struct Task* tail= NULL;

struct Task* h=NULL;
struct Task* t= NULL;


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

void completed_task(int n){
    int i = 1;
    struct Task* ptr = head;
    
    while (i < n && ptr != NULL) {
        ptr = ptr->next;
        i++;
    }

    if (ptr == NULL) {
        printf("Task number %d does not exist.\n", n);
        return;
    }

    
    struct Task* new = (struct Task*)malloc(sizeof(struct Task));
    strcpy(new->data, ptr->data);
    new->next = NULL;

   
    if (h == NULL) {
        h = t = new;
    } else {
        t->next = new;
        t = new;
    }

    delete_task(n);
}



void Display_completed(){

    int index=1;
    struct Task* ptr= h;
    while(ptr!=NULL){
        printf("%d) %s\n", index,ptr->data);
        index++;
        ptr=ptr->next;
    }
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
    printf("How many tasks do you have today? ");
    scanf("%d", &n);
    getchar();  // flush leftover newline

    for (int i = 0; i < n; i++) {
        char data[100];
        printf("Write your task no. %d: ", i + 1);
        fgets(data, sizeof(data), stdin);
        data[strcspn(data, "\n")] = '\0'; // remove newline
        create_task(data);
    }
    printf("\n");
    Display();
    int choice;

    while (1) {
        printf("\n----Task Manager----\n");
        printf("1. Add Task\n");
        printf("2. Edit Task\n");
        printf("3. Delete Task\n");
        printf("4. Completed a task\n");
        printf("5. View Tasks\n");
        printf("6. View Completed Tasks\n");
        printf("7. Exit\n");
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar(); // flush newline before reading strings

        switch (choice) {
            case 1: {
                int n;
                printf("How many tasks you have to add? ");
                scanf("%d", &n);
                getchar();

                for (int i = 0; i < n; i++) {
                    char data[100];
                    printf("Write your task no. %d: ", i + 1);
                    fgets(data, sizeof(data), stdin);
                    data[strcspn(data, "\n")] = '\0';
                    create_task(data);
                }
                printf("\n");
                Display();
                
                break;
            }

            case 2: {
                int index;
                char data[100];
                printf("Which task no. to edit? ");
                scanf("%d", &index);
                getchar();
                printf("Provide new edited-task: ");
                fgets(data, sizeof(data), stdin);
                data[strcspn(data, "\n")] = '\0';
                edit(index, data);
                printf("\n");
                Display();
                break;
            }

            case 3: {
                int d;
                printf("Which task no. to delete? ");
                scanf("%d", &d);
                delete_task(d);
                printf("\n");
                Display();
                break;
            }

            case 4:{

                int c;
                printf("which task no. did you completed? ");
                scanf("%d", &c);

                completed_task(c);

                printf("your completed task till now\n");
                Display_completed();
                printf("\n your remaining tasks\n\n");
                Display();
                break;
            }


            case 5:{
                Display();
                break;
            }
            
            case 6:{
                Display_completed();
                break;
            }
          
            case 7:
                printf("Exiting Task Manager...\n");
                return 0;

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
}