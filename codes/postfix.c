#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct nodeType
{
    char data;
    struct nodeType *next;
} node;

void push(node **head, char info)
{
    node *ptr;
    ptr = (node *)malloc(sizeof(node));
    ptr->data = info;

    ptr->next = *head;
    *head = ptr;
}

char pop(node **head)
{
    node *curr = *head;
    char item = curr->data;
    *head = curr->next;
    free(curr);
    curr = NULL;
    return item;
}

void traverse(node *head)
{
    while (head != NULL)
    {
        printf("%c ", head->data);
        head = head->next;
    }
}

int isOperator(char ch)
{
    if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')
        return 1;
    else
        return 0;
}

int isHigher(char check, char ch)
{
    if ((ch == '-' || ch == '+') && isOperator(check))
        return 1;

    if ((check == '*' || check == '/') && (ch == '-' || ch == '+'))
        return 1;

    if (ch == '^' && check == '^')
        return 1;

    return 0;
}

void polish(char Q[], char P[], node **stack)
{
    char ch;
    int j = 0;
    Q = strupr(strcat(Q, ")"));
    push(stack, '(');

    for (int i = 0; Q[i] != '\0'; i++)
    {
        ch = Q[i];
        // printf("%c\n", ch);
        if ((ch >= 65 && ch <= 90))
        {
            P[j++] = ch;
            // printf("ch\n");
        }
        else if (isOperator(ch))
        {
            // printf("operator\n");
            while (isHigher((*stack)->data, ch))
            {
                // printf("ok\n");
                P[j++] = pop(stack);
            }

            push(stack, ch);
        }
        else if (ch == ')')
        {
            // printf("bracket\n");

            while ((*stack)->data != '(')
            {
                P[j++] = pop(stack);
                // printf("%c \n", P[j]);
            }
            pop(stack);
        }
        else if (ch == '(')
            push(stack, ch);
        // printf("P = %s\nStack = ", P);
        // traverse(*stack);
        // printf("\n\n");
    }
}

void main()
{
    node *stack;
    char Q[100];
    char P[100];
    gets(Q);
    polish(Q, P, &stack);

    printf("Postfix -> %s", P);
    // traverse(stack);
}