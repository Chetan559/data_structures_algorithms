#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
};
struct Queue {
    struct Node* front;
    struct Node* rear;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if (queue == NULL) {
        printf("Memory error\n");
        return NULL;
    }
    queue->front = queue->rear = NULL;
    return queue;
}
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}
void enqueue(struct Queue* queue, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL)
        return;
    if (queue->rear == NULL) {
        queue->front = queue->rear = newNode;
        return;
    }
    queue->rear->next = newNode;
    queue->rear = newNode;
}
int dequeue(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }
    struct Node* temp = queue->front;
    int dequeuedData = temp->data;
    queue->front = temp->next;
    if (queue->front == NULL)
        queue->rear = NULL;
    free(temp);
    return dequeuedData;
}
void display(struct Queue* queue) {
    if (isEmpty(queue)) {
        printf("Queue is empty.\n");
        return;
    }
    struct Node* temp = queue->front;
    printf("Queue elements: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
int main() {
    struct Queue* queue = initializeQueue();
    int choice, data;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue 2. Dequeue 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to enqueue: ");
                scanf("%d", &data);
                enqueue(queue, data);
                break;
            case 2:
                data = dequeue(queue);
                if (data != -1)
                    printf("Dequeued element: %d\n", data);
                break;
            case 3:
                display(queue);
                break;
            case 4:
                free(queue);
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }}
    return 0;
}
