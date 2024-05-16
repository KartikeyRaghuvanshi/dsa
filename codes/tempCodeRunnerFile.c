#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Structure representing the stack
typedef struct {
    int items[10];
    int top; // Index of the top element
} Stack;

// Initialize the stack
void initialize(Stack *s) {
    s->top = -1; // Initialize top index to -1 (empty stack)
}

// Check if the stack is empty
bool isEmpty(Stack *s) {
    return (s->top == -1);
}

// Check if the stack is full
bool isFull(Stack *s) {
    return (s->top == MAX_SIZE - 1);
}

// Push an element onto the stack
void push(Stack *s, int value) {
    if (isFull(s)) {
        printf("Stack Overflow: Cannot push element, stack is full.\n");
        return;
    }
    s->items[++s->top] = value;
}

// Pop an element from the stack
int pop(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack Underflow: Cannot pop element, stack is empty.\n");
        return -1; // Return -1 or appropriate value to indicate underflow
    }
    return s->items[s->top--];
}

// Peek at the top element of the stack
int peek(Stack *s) {
    if (isEmpty(s)) {
        printf("Stack is empty.\n");
        return -1; // Return -1 or appropriate value for empty stack
    }
    return s->items[s->top];
}

int main() {
    // Stack myStack;
    // initialize(&myStack);

    // // Push elements onto the stack
    // push(&myStack, 10);
    // push(&myStack, 20);
    // push(&myStack, 30);

    // // Peek and pop elements from the stack
    // printf("Top element: %d\n", peek(&myStack)); // Should print 30
    // printf("Popped element: %d\n", pop(&myStack)); // Should print 30
    // printf("Top element after pop: %d\n", peek(&myStack)); // Should print 20
    
    printf("enter your choice \n");
    printf("enter 1- to initialize your stack\n");
    printf("enter 2- to push element in your stack\n");
    printf("enter 3- to pop the top element from your stack\n");
    printf("enter 4- to check if the stack is empty\n");
    printf("enter 5- to check if the full\n");
    printf("enter 6- to view the top most element of your stack\n");
          int choice;
          Stack myStack;
          printf("-----enter your choice--\n");
          scanf("%d",&choice);
          switch(choice){
              
        case 1:
              Stack myStack;
               initialize(&myStack);
               printf("your stack is initialized\n");
               break;
        case 2:
              int element;
              printf("---enter your element--that you want push into your stack\n");
              scanf("%d",&element);
              push(&myStack,element);
              break;
        case 3:
              pop(&myStack);
              break;
        case 4:
              bool result=isEmpty(&myStack);
              if(result==true){
                  printf("your stack is empty\n");
              }else{
                  printf("not empty\n");
              }
              break;
        case 5:
            bool res=isFull(&myStack);
            if(res==true){
                printf("your stack is full\n");
            }else{
                printf("no its not full\n");
            }
            break;
        case 6:
            int top=peek(&myStack);
            printf("%d",top);
            break;
        default:
          printf("ooops!  your choice is invalid please read the choices and then enter \n");
          }
    return 0;
}