// by avinash.................................
#include <stdio.h>
#include <stdlib.h>

typedef struct nodeType
{
    struct nodeType *prev;
    int data;
    struct nodeType *next;
} node;

void createEmptyList(node **head, node **tail)
{
    *head = *tail = NULL;
}

void traverseInOrder(node *head)
{
    printf("\n");
    while (head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
}

void traverseInReverseOrder(node *tail)
{
    printf("\n");
    while (tail != NULL)
    {
        printf("%d ", tail->data);
        tail = tail->prev;
    }
}

void insertAtBeginning(node **head, node **tail, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = item;
    ptr->prev = NULL;

    if (*head == NULL)
    {
        ptr->next = NULL;
        *head = *tail = ptr;
    }
    else
    {
        ptr->next = *head;
        (*head)->prev = ptr;
        *head = ptr;
    }
}

void insertAtEnd(node **head, node **tail, int item)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = item;
    ptr->next = NULL;

    if (*tail == NULL)
    {
        ptr->prev = NULL;
        *head = *tail = ptr;
    }
    else
    {
        ptr->prev = *tail;
        (*tail)->next = ptr;
        *tail = ptr;
    }
}

node *searchInUnsortedList(node *head, int item)
{
    while (head != NULL && head->data != item)
        head = head->next;

    return head;
}

void insertAfterElement(node *head, node **tail, int item, int after)
{
    node *ptr, *loc;
    loc = searchInUnsortedList(head, after);
    if (loc != NULL)
    {
        ptr = (node *)malloc(sizeof(node));
        ptr->data = item;

        if (loc == *tail)
        {
            ptr->next = NULL;
            *tail = ptr;
        }
        else
        {
            ptr->next = loc->next;
            loc->next->prev = ptr;
        }
        ptr->prev = loc;
        loc->next = ptr;

        printf("\nInserted");
    }
    else
        printf("\nNode not found.");
}

void insertBeforeElement(node **head, node *tail, int item, int before)
{
    node *ptr, *loc;
    loc = searchInUnsortedList(*head, before);

    if (loc != NULL)
    {
        ptr = (node *)malloc(sizeof(node));
        ptr->data = item;

        if (loc == *head)
        {
            ptr->prev = NULL;
            *head = ptr;
        }
        else
        {
            ptr->prev = loc->prev;
            loc->prev->next = ptr;
        }
        ptr->next = loc;
        loc->prev = ptr;

        printf("\nInserted.");
    }
    else
        printf("\nNode not found.");
}

void deleteFromBeginning(node **head, node **tail)
{
    node *ptr = *head;
    if (ptr->next == NULL)
        *head = *tail = NULL;
    else
    {
        *head = ptr->next;
        ptr->next->prev = NULL;
    }
    free(ptr);
    ptr = NULL;
}
void deleteFromEnd(node **head, node **tail)
{
    node *ptr = *tail;
    if (ptr->prev == NULL)
        *head = *tail = NULL;
    else
    {
        *tail = ptr->prev;
        ptr->prev->next = NULL;
    }
    free(ptr);
    ptr = NULL;
}

void main()
{
    node *head, *tail;
    int choice, item, d;
    createEmptyList(&head, &tail);
    do
    {
        printf("\n1. Create Empty List.");
        printf("\n2. Insert At Beginning");
        printf("\n3. Insert At End.");
        printf("\n4. Insert After Element.");
        printf("\n5. Insert Before Element.");
        printf("\n6. Traverse In Order.");
        printf("\n7. Traverse in Reverse Order.");
        printf("\n8. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            createEmptyList(&head, &tail);
            break;
        case 2:
            printf("\nEnter data: ");
            scanf("%d", &item);
            insertAtBeginning(&head, &tail, item);
            traverseInOrder(head);
            break;
        case 3:
            printf("\nEnter data: ");
            scanf("%d", &item);
            insertAtEnd(&head, &tail, item);
            traverseInOrder(head);
            break;
        case 4:
            printf("\nEnter data: ");
            scanf("%d", &item);
            printf("\nEnter item to insert after: ");
            scanf("%d", &d);
            insertAfterElement(head, &tail, item, d);
            traverseInOrder(head);
            break;
        case 5:
            printf("\nEnter data: ");
            scanf("%d", &item);
            printf("\nEnter item to insert before: ");
            scanf("%d", &d);
            insertBeforeElement(&head, tail, item, d);
            traverseInOrder(head);
            break;
        case 6:
            traverseInOrder(head);
            break;
        case 7:
            traverseInReverseOrder(tail);
            break;
        case 8:
            printf("\nExited.");
        default:
            break;
        }

    } while (choice != 8);

    // insertAtEnd(&head, &tail, 10);
    // insertAtEnd(&head, &tail, 20);
    // insertAtEnd(&head, &tail, 30);
    // insertAtEnd(&head, &tail, 40);
    // insertAtEnd(&head, &tail, 50);
    // insertAtBeginning(&head, &tail, 60);
    // traverseInOrder(head);
    // traverseInReverseOrder(tail);
    // insertAfterElement(head, &tail, 90, 50);
    // insertBeforeElement(&head, tail, 100, 60);
    // traverseInOrder(head);
}