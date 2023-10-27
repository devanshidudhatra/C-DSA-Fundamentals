// #include <stdio.h>
// #include <stdlib.h>
// #include <limits.h>

// struct Queue {
//     int front, rear, size;
//     unsigned cap;
//     int* arr;
// };

// struct Queue* createQueue(unsigned cap) {
//     struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
//     queue->cap = cap;
//     queue->front = queue->size = 0;
//     queue->rear = cap - 1;
//     queue->arr = (int*)malloc(cap * sizeof(int));
//     return queue;
// }

// int isFull(struct Queue* queue) {
//     return (queue->size == queue->cap);
// }

// int isEmpty(struct Queue* queue) {
//     return (queue->size == 0);
// }

// void enqueue(struct Queue* queue, int item) {
//     if (isFull(queue))
//         return;
//     queue->rear = (queue->rear + 1) % queue->cap;
//     queue->arr[queue->rear] = item;
//     queue->size = queue->size + 1;
//     printf("%d Enqueued to Queue\n", item);
// }

// int dequeue(struct Queue* queue) {
//     if (isEmpty(queue))
//         return INT_MIN;
//     int item = queue->arr[queue->front];
//     queue->front = (queue->front + 1) % queue->cap;
//     queue->size = queue->size - 1;
//     return item;
// }

// int front(struct Queue* queue) {
//     if (isEmpty(queue))
//         return INT_MIN;
//     return queue->arr[queue->front];
// }

// int rear(struct Queue* queue) {
//     if (isEmpty(queue))
//         return INT_MIN;
//     return queue->arr[queue->rear];
// }

// int main() {
//     struct Queue* queue = createQueue(1000);
//     enqueue(queue, 10);
//     enqueue(queue, 20);
//     enqueue(queue, 30);
//     enqueue(queue, 40);
//     printf("%d Dequeued from queue\n", dequeue(queue));
//     printf("Front Item is %d\n", front(queue));
//     printf("Rear item is %d\n", rear(queue));

//     free(queue->arr);
//     free(queue);
//     return 0;
// }

#include <stdio.h>

#define MAX_SIZE 100

// Structure to represent a single-ended queue
struct Queue
{
    int elements[MAX_SIZE];
    int front, rear;
};

// Initialize the queue
void initQueue(struct Queue *q)
{
    q->front = -1;
    q->rear = -1;
}

// Check if the queue is empty
int isEmpty(struct Queue *q)
{
    return (q->front == -1);
}

// Check if the queue is full
int isFull(struct Queue *q)
{
    return (q->rear == MAX_SIZE - 1);
}

// Enqueue an element into the queue
void enqueue(struct Queue *q, int item)
{
    if (isFull(q))
    {
        printf("Queue is full. Cannot enqueue.\n");
    }
    else
    {
        if (q->front == -1)
        {
            q->front = 0;
        }
        q->rear++;
        q->elements[q->rear] = item;
        printf("Enqueued: %d\n", item);
    }
}

// Dequeue an element from the queue
void dequeue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty. Cannot dequeue.\n");
    }
    else
    {
        int item = q->elements[q->front];
        if (q->front == q->rear)
        {
            q->front = -1;
            q->rear = -1;
        }
        else
        {
            q->front++;
        }
        printf("Dequeued: %d\n", item);
    }
}

// Print the entire queue
void printQueue(struct Queue *q)
{
    if (isEmpty(q))
    {
        printf("Queue is empty.\n");
    }
    else
    {
        printf("Queue elements: ");
        for (int i = q->front; i <= q->rear; i++)
        {
            printf("%d ", q->elements[i]);
        }
        printf("\n");
    }
}

int main()
{
    struct Queue q;
    initQueue(&q);

    int size, input, choice;

    printf("Enter the size of the queue: ");
    scanf("%d", &size);

    if (size <= 0 || size > MAX_SIZE)
    {
        printf("Invalid queue size.\n");
        return 1;
    }

    printf("Enter %d initial elements for the queue:\n", size);
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &input);
        enqueue(&q, input);
    }

    while (1)
    {
        printf("\n1. Enqueue\n2. Dequeue\n3. Print Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the element to enqueue: ");
            scanf("%d", &input);
            enqueue(&q, input);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            printQueue(&q);
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice. Try again.\n");
        }
    }

    return 0;
}
