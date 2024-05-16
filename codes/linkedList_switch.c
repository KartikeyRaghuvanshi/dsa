#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a node at the beginning of the linked list
struct Node* insertAtBeginning(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    newNode->next = head;
    return newNode;
}

// Function to insert a node at the end of the linked list
void insertAtEnd(struct Node* head, int value) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert a node at a specific position in the linked list
void insertAtPosition(struct Node* head, int value, int position) {
    struct Node* newNode = createNode(value);
    struct Node* temp = head;
    int currentPosition = 1;
    while (currentPosition < position - 1 && temp != NULL) {
        temp = temp->next;
        currentPosition++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete the first node of the linked list
struct Node* deleteAtBeginning(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return NULL;
    }
    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

// Function to delete the last node of the linked list
void deleteAtEnd(struct Node* head) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    free(temp);
}

// Function to delete a node at a specific position in the linked list
void deleteAtPosition(struct Node* head, int position) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    struct Node* temp = head;
    struct Node* prev = NULL;
    int currentPosition = 1;
    while (currentPosition < position && temp != NULL) {
        prev = temp;
        temp = temp->next;
        currentPosition++;
    }
    if (temp == NULL) {
        printf("Invalid position\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to traverse and display the linked list
void display(struct Node* head) {
    printf("Linked List: ");
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Function to reverse the linked list
struct Node* reverse(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;
    struct Node* next = NULL;
    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    return prev;
}

// Function to perform insertion sort on the linked list
struct Node* insertionSort(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    struct Node* sorted = NULL;
    struct Node* current = head;
    while (current != NULL) {
        struct Node* next = current->next;
        sorted = sortedInsert(sorted, current);
        current = next;
    }
    return sorted;
}

// Helper function for insertion sort
struct Node* sortedInsert(struct Node* head, struct Node* newNode) {
    if (head == NULL || newNode->data <= head->data) {
        newNode->next = head;
        return newNode;
    }
    struct Node* temp = head;
    while (temp->next != NULL && temp->next->data < newNode->data) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
    return head;
}

int main() {
    struct Node* head = NULL;
    int choice, value, position;

    while (1) {
        printf("\n----- Menu -----\n");
        printf("1. Insert at beginning\n");
        printf("2. Insert at end\n");
        printf("3. Insert at specific position\n");
        printf("4. Delete at beginning\n");
        printf("5. Delete at end\n");
        printf("6. Delete at specific position\n");
        printf("7. Display linked list\n");
        printf("8. Reverse linked list\n");
        printf("9. Sort linked list (Insertion Sort)\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                head = insertAtBeginning(head, value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(head, value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(head, value, position);
                break;
            case 4:
                head = deleteAtBeginning(head);
                break;
            case 5:
                deleteAtEnd(head);
                break;
            case 6:
                printf("Enter position: ");
                scanf("%d", &position);
                deleteAtPosition(head, position);
                break;
            case 7:
                display(head);
                break;
            case 8:
                head = reverse(head);
                break;
            case 9:
                head = insertionSort(head);
                break;
            case 10:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

