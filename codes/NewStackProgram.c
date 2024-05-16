#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure representing the stack implemented using an array
typedef struct {
    int items[MAX_SIZE];
    int top; // Index of the top element
} ArrayStack;

// Structure representing a node in the linked list
typedef struct ListNode {
    int data;
    struct ListNode *next;
} ListNode;

// Structure representing the stack implemented using a linked list
typedef struct {
    ListNode *top; // Pointer to the top node
} LinkedListStack;

// Initialize the array-based stack
void initializeArrayStack(ArrayStack *s) {
    s->top = -1; // Initialize top index to -1 (empty stack)
}

// Check if the array-based stack is empty
bool isArrayStackEmpty(ArrayStack *s) {
    return (s->top == -1);
}

// Check if the array-based stack is full
bool isArrayStackFull(ArrayStack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Push an element onto the array-based stack
void pushArrayStack(ArrayStack *s, int value) {
    if (isArrayStackFull(s)) {
        printf("Stack Overflow: Cannot push element, stack is full.\n");
        return;
    }
    s->items[++s->top] = value;
}

// Pop an element from the array-based stack
int popArrayStack(ArrayStack *s) {
    if (isArrayStackEmpty(s)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1; // Return -1 or appropriate value to indicate underflow
    }
    return s->items[s->top--];
}

// Peek at the top element of the array-based stack
int peekArrayStack(ArrayStack *s) {
    if (isArrayStackEmpty(s)) {
        printf("Stack is empty.\n");
        return -1; // Return -1 or appropriate value for empty stack
    }
    return s->items[s->top];
}

// Initialize the linked list-based stack
void initializeLinkedListStack(LinkedListStack *s) {
    s->top = NULL; // Initialize top pointer to NULL (empty stack)
}

// Check if the linked list-based stack is empty
bool isLinkedListStackEmpty(LinkedListStack *s) {
    return (s->top == NULL);
}

// Push an element onto the linked list-based stack
void pushLinkedListStack(LinkedListStack *s, int value) {
    ListNode *newNode = (ListNode *)malloc(sizeof(ListNode));
    if (newNode == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = s->top;
    s->top = newNode;
}

// Pop an element from the linked list-based stack
int popLinkedListStack(LinkedListStack *s) {
    if (isLinkedListStackEmpty(s)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1; // Return -1 or appropriate value to indicate underflow
    }
    int value = s->top->data;
    ListNode *temp = s->top;
    s->top = s->top->next;
    free(temp);
    return value;
}

// Peek at the top element of the linked list-based stack
int peekLinkedListStack(LinkedListStack *s) {
    if (isLinkedListStackEmpty(s)) {
        printf("Stack is empty.\n");
        return -1; // Return -1 or appropriate value for empty stack
    }
    return s->top->data;
}

int main() {
    int choice;
    ArrayStack arrayStack;
    LinkedListStack linkedListStack;

    while (1) {
        printf("\nEnter your choice:\n");
        printf("1. Array-based Stack\n");
        printf("2. Linked List-based Stack\n");
        printf("3. Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                initializeArrayStack(&arrayStack);
                while (1) {
                    printf("\nArray-based Stack Operations:\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Peek\n");
                    printf("4. Back to Main Menu\n");

                    printf("Choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            if (isArrayStackFull(&arrayStack)) {
                                printf("Stack is full.\n");
                            } else {
                                int value;
                                printf("Enter value to push: ");
                                scanf("%d", &value);
                                pushArrayStack(&arrayStack, value);
                            }
                            break;
                        case 2:
                            if (isArrayStackEmpty(&arrayStack)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Popped element: %d\n", popArrayStack(&arrayStack));
                            }
                            break;
                        case 3:
                            if (isArrayStackEmpty(&arrayStack)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Top element: %d\n", peekArrayStack(&arrayStack));
                            }
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }

                    if (choice == 4) {
                        break;
                    }
                }
                break;
            case 2:
                initializeLinkedListStack(&linkedListStack);
                while (1) {
                    printf("\nLinked List-based Stack Operations:\n");
                    printf("1. Push\n");
                    printf("2. Pop\n");
                    printf("3. Peek\n");
                    printf("4. Back to Main Menu\n");

                    printf("Choice: ");
                    scanf("%d", &choice);

                    switch (choice) {
                        case 1:
                            int value;
                            printf("Enter value to push: ");
                            scanf("%d", &value);
                            pushLinkedListStack(&linkedListStack, value);
                            break;
                        case 2:
                            if (isLinkedListStackEmpty(&linkedListStack)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Popped element: %d\n", popLinkedListStack(&linkedListStack));
                            }
                            break;
                        case 3:
                            if (isLinkedListStackEmpty(&linkedListStack)) {
                                printf("Stack is empty.\n");
                            } else {
                                printf("Top element: %d\n", peekLinkedListStack(&linkedListStack));
                            }
                            break;
                        case 4:
                            break;
                        default:
                            printf("Invalid choice. Please try again.\n");
                    }

                    if (choice == 4) {
                        break;
                    }
                }
                break;
            case 3:
                printf("Exiting program.\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
