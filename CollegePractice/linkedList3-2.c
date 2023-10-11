#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node* next;
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
int isEmpty(struct Node* top) {
    return (top == NULL);
}
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    if (newNode == NULL)
        return;
    newNode->next = *top;
    *top = newNode;
    printf("Pushed element: %d\n", data);
}
int pop(struct Node** top) {
    if (isEmpty(*top)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    struct Node* temp = *top;
    int poppedData = temp->data;
    *top = temp->next;
    free(temp);
    return poppedData;
}
void display(struct Node* top) {
    if (isEmpty(top)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack elements: ");
    while (top != NULL) {
        printf("%d ", top->data);
        top = top->next;
    }
    printf("\n");
}
int main() {
    struct Node* top = NULL;
    int choice, data;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push 2. Pop 3. Display 4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter element to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;
            case 2:
                data = pop(&top);
                if (data != -1)
                    printf("Popped element: %d\n", data);
                break;
            case 3:
                display(top);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }}
    return 0;
}
