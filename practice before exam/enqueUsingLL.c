#include <stdio.h>
#include <stdlib.h>

// Node structure to represent each element in the queue
struct Node {
    int data;
    struct Node* next;
};

// Structure representing a queue
struct Queue {
    struct Node* front; // Front of the queue
    struct Node* rear;  // Rear of the queue
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to initialize an empty queue
struct Queue* initializeQueue() {
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int isEmpty(struct Queue* queue) {
    return (queue->front == NULL);
}

// Function to perform enqueue operation
void enqueue(struct Queue* queue, int data) {
    // Create a new node with the given data
    struct Node* newNode = createNode(data);

    // If the queue is empty, set both front and rear to the new node
    if (isEmpty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }

    printf("%d enqueued to the queue\n", data);
}

int main() {
    // Initialize an empty queue
    struct Queue* myQueue = initializeQueue();

    // Enqueue some elements
    enqueue(myQueue, 10);
    enqueue(myQueue, 20);
    enqueue(myQueue, 30);

    return 0;
}
