#include <stdio.h>

#define MAX_QUEUE_SIZE 100

int queue[MAX_QUEUE_SIZE];
int front = -1;
int rear = -1;

int isFull() {
    if(rear == MAX_QUEUE_SIZE - 1){
        return 1;
    }
    else
    return 0;
}

int isEmpty() {
     if(front == -1 || front > rear){
        return 1;
     }
     else{
        return 0;
     }
}

void enqueue(int item) {
    if (isFull()) {
        printf("Queue is full. Cannot insert.\n");
        return;
    }

    if (front == -1)
        front = 0;

    rear++;
    queue[rear] = item;
}

int dequeue() {
    int item;
    if (isEmpty()) {
        printf("Queue is empty. Cannot delete.\n");
        return -1;
    }

    item = queue[front];
    front++;

    return item;
}

void display() {
    if (isEmpty()) {
        printf("Queue is empty.\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }
    printf("\n");
}

int main() {
    int choice, item;

    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Insert 2. Delete 3. Display 4. Exit \nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element to insert: ");
                scanf("%d", &item);
                enqueue(item);
                break;

            case 2:
                item = dequeue();
                if (item != -1)
                    printf("Deleted element: %d\n", item);
                break;

            case 3:
                display();
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
