#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue {
    int front, rear, size;
    unsigned cap;
    int* arr;
};

struct Queue* createQueue(unsigned cap) {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->cap = cap;
    queue->front = queue->size = 0;
    queue->rear = cap - 1;
    queue->arr = (int*)malloc(cap * sizeof(int));
    return queue;
}

int isFull(struct Queue* queue) {
    return (queue->size == queue->cap);
}

int isEmpty(struct Queue* queue) {
    return (queue->size == 0);
}

void enqueue(struct Queue* queue, int item) {
    if (isFull(queue))
        return;
    queue->rear = (queue->rear + 1) % queue->cap;
    queue->arr[queue->rear] = item;
    queue->size = queue->size + 1;
    printf("%d Enqueued to Queue\n", item);
}

int dequeue(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    int item = queue->arr[queue->front];
    queue->front = (queue->front + 1) % queue->cap;
    queue->size = queue->size - 1;
    return item;
}

int front(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->front];
}

int rear(struct Queue* queue) {
    if (isEmpty(queue))
        return INT_MIN;
    return queue->arr[queue->rear];
}

int main() {
    struct Queue* queue = createQueue(1000);
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    printf("%d Dequeued from queue\n", dequeue(queue));
    printf("Front Item is %d\n", front(queue));
    printf("Rear item is %d\n", rear(queue));

    free(queue->arr);
    free(queue);
    return 0;
}
