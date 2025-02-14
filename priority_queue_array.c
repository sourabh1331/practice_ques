#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 100

// Priority Queue structure
typedef struct PriorityQueue {
    int data[MAX_SIZE];
    int priority[MAX_SIZE];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

int isEmpty(PriorityQueue* pq) {
    return pq->size == 0;
}

int isFull(PriorityQueue* pq) {
    return pq->size == MAX_SIZE;
}

void enqueue(PriorityQueue* pq, int data, int priority) {
    if (isFull(pq)) {
        printf("Queue is full!\n");
        return;
    }
    int i = pq->size - 1;
    while (i >= 0 && pq->priority[i] > priority) {
        pq->data[i + 1] = pq->data[i];
        pq->priority[i + 1] = pq->priority[i];
        i--;
    }
    pq->data[i + 1] = data;
    pq->priority[i + 1] = priority;
    pq->size++;
}

int dequeue(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    int data = pq->data[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return data;
}

int peek(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty!\n");
        return -1;
    }
    return pq->data[0];
}

int getSize(PriorityQueue* pq) {
    return pq->size;
}

void display(PriorityQueue* pq) {
    if (isEmpty(pq)) {
        printf("Queue is empty\n");
        return;
    }
    for (int i = 0; i < pq->size; i++) {
        printf("%d (Priority: %d) -> ", pq->data[i], pq->priority[i]);
    }
    printf("NULL\n");
}

int main() {
    PriorityQueue pq;
    initQueue(&pq);

    enqueue(&pq, 10, 2);
    enqueue(&pq, 20, 1);
    enqueue(&pq, 30, 3);
    enqueue(&pq, 40, 0);

    printf("Priority Queue: ");
    display(&pq);
    printf("Queue size: %d\n", getSize(&pq));

    printf("Dequeued: %d\n", dequeue(&pq));
    printf("After dequeuing: ");
    display(&pq);
    printf("Queue size: %d\n", getSize(&pq));

    return 0;
}
