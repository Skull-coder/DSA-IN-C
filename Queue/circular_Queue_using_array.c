#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct queue {
    int front;
    int rear;
    int size;
    int *arr;
};

bool is_full(struct queue *q) {
    return ((q->rear + 1) % q->size) == q->front;
}

bool is_empty(struct queue *q) {
    return q->front == -1;
}

void enque(struct queue *q, int data) {
    if (is_full(q)) {
        printf("Queue is full\n");
        return;
    }

    if (is_empty(q)) {
        q->front = 0;
        q->rear = 0;
    } else {
        q->rear = (q->rear + 1) % q->size;
    }

    q->arr[q->rear] = data;
}

int dequeue(struct queue *q) {
    if (is_empty(q)) {
        printf("Queue is Empty\n");
        return -1;
    }

    int data = q->arr[q->front];

    if (q->front == q->rear) {
        
        q->front = q->rear = -1;
    } else {
        q->front = (q->front + 1) % q->size;
    }

    return data;
}

void peek(struct queue *q, int index) {
    if (is_empty(q)) {
        printf("Queue is empty\n");
        return;
    }

    int count = (q->rear - q->front + q->size) % q->size + 1;

    if (index >= count) {
        printf("Index %d does not exist\n", index);
        return;
    }

    int pos = (q->front + index) % q->size;
    printf("Element at index %d = %d\n", index, q->arr[pos]);
}

int main() {
    struct queue *q = (struct queue *)malloc(sizeof(struct queue));
    q->size = 5;
    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    enque(q, 10);
    enque(q, 20);
    enque(q, 30);
    enque(q, 40);
    enque(q, 50);

    for (int i = 0; i < 5; i++) peek(q, i);

    printf("removed: %d\n", dequeue(q));
    printf("removed: %d\n", dequeue(q));
    printf("removed: %d\n", dequeue(q));

    enque(q, 60);
    enque(q, 70);

    for (int i = 0; i < 5; i++) peek(q, i);

    return 0;
}
