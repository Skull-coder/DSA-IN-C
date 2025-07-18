#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void printList(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return;
    }

    struct Node *temp = head;
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("(HEAD)\n");
}

struct Node *insertAtBeginning(struct Node *head, int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node *temp = head;

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    while (temp->next != head)
        temp = temp->next;

    newNode->next = head;
    temp->next = newNode;
    return newNode;
}

struct Node *insertAtEnd(struct Node *head, int value)
{
    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    struct Node *temp = head;

    if (head == NULL)
    {
        newNode->next = newNode;
        return newNode;
    }

    while (temp->next != head)
        temp = temp->next;

    temp->next = newNode;
    newNode->next = head;
    return head;
}

struct Node *insertAtIndex(struct Node *head, int value, int index)
{
    if (index == 0)
        return insertAtBeginning(head, value);

    struct Node *temp = head;
    for (int i = 0; i < index - 1; i++)
    {
        if (temp->next == head)
        {
            printf("Index out of bounds.\n");
            return head;
        }
        temp = temp->next;
    }

    struct Node *newNode = malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

struct Node *deleteAtBeginning(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    struct Node *last = head;

    while (last->next != head)
        last = last->next;

    head = head->next;
    last->next = head;
    free(temp);
    return head;
}

struct Node *deleteAtEnd(struct Node *head)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    if (head->next == head)
    {
        free(head);
        return NULL;
    }

    struct Node *temp = head;
    while (temp->next->next != head)
        temp = temp->next;

    struct Node *toDelete = temp->next;
    temp->next = head;
    free(toDelete);
    return head;
}

struct Node *delete_value(struct Node *head, int target)
{
    if (head == NULL)
    {
        printf("List is empty.\n");
        return NULL;
    }

    struct Node *temp = head;
    struct Node *q = head->next;

    if (head->data == target)
    {
        head = deleteAtBeginning(head);
    }

    else
    {
        while (temp->next != head && temp->next->data != target)
        {
            temp = temp->next;
            q = q->next;
        }

        if (temp->next->data != target)
        {
            printf("not found");
        }

        else
        {
            temp->next = temp->next->next;
            free(q);
        }
    }

    return head;
}

int main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    

    head->data = 10;
    second->data = 20;
    third->data = 30;

    head->next = second;
    second->next = third;
    third->next = head;

    head = insertAtBeginning(head, 5);
    head = insertAtEnd(head, 40);
    head = insertAtIndex(head, 25, 3);

    head = deleteAtBeginning(head);
    head = deleteAtEnd(head);
    head = delete_value(head, 20);

    printList(head);

    return 0;
}