#include <stdio.h>
#include <stdlib.h>
struct Node {
    int data;
    struct Node *next;
};
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}
void insertFront(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}
void insertEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}
void insertSorted(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL || (*head)->data >= data) {
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL && temp->next->data < data) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
void deleteFront(struct Node** head) {
    if (*head == NULL) {
        printf("The list is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
}
void deleteBeforePosition(struct Node** head, int position) {
    if (*head == NULL || position <= 1) {
        printf("Invalid position or the list is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    int i;
    for (i = 1; i < position - 1 && temp->next != NULL; i++) {
        temp = temp->next;
    }
    if (i != position - 1 || temp->next == NULL) {
        printf("Position not found. Cannot delete.\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
void deleteAfterPosition(struct Node** head, int position) {
    if (*head == NULL || position < 1) {
        printf("Invalid position or the list is empty. Cannot delete.\n");
        return;
    }
    struct Node* temp = *head;
    int i;
    for (i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    if (i != position || temp == NULL || temp->next == NULL) {
        printf("Position not found. Cannot delete.\n");
        return;
    }
    struct Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);
}
void printList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = NULL;
    int choice, data, position;

    do {
        printf("\nMenu:\n");
        printf("1. Insert a node at the front\n");
        printf("2. Insert a node at the end\n");
        printf("3. Insert a node in ascending order\n");
        printf("4. Delete the first node\n");
        printf("5. Delete a node before a specified position\n");
        printf("6. Delete a node after a specified position\n");
        printf("7. Print the list\n");
        printf("0. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter data to insert at the front: ");
                scanf("%d", &data);
                insertFront(&head, data);
                break;
            case 2:
                printf("Enter data to insert at the end: ");
                scanf("%d", &data);
                insertEnd(&head, data);
                break;
            case 3:
                printf("Enter data to insert in ascending order: ");
                scanf("%d", &data);
                insertSorted(&head, data);
                break;
            case 4:
                deleteFront(&head);
                break;
            case 5:
                printf("Enter the position before which to delete: ");
                scanf("%d", &position);
                deleteBeforePosition(&head, position);
                break;
            case 6:
                printf("Enter the position after which to delete: ");
                scanf("%d", &position);
                deleteAfterPosition(&head, position);
                break;
            case 7:
                printList(head);
                break;
            case 0:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
                break;
        }
    } while (choice != 0);
    return 0;
}
