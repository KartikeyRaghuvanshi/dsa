#include <stdio.h>
#include <stdlib.h>
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};
void addToEmpty(struct node **head, int data);
void insertAtBeg(struct node **head, int data);
void insertAtEnd(struct node **head, int data);
void delAtBeg(struct node **head);
void delAtEnd(struct node **head);
void searchElement(struct node **head, int data);
void reverse(struct node **head);
void displayList(struct node **head);

int main()
{
    struct node *head = NULL;
    struct node *tail = NULL;
    int data, choice;

    while (1)
    {
        printf("\n*MENU*");
        printf("\n1. Create a single node in empty list");
        printf("\n2. Insert a node at beginning of the linkedlist");
        printf("\n3. Insert a node at end of doubly linkedlist");
        printf("\n4. Insert a node at any particular position of the doubly linkedlist");
        printf("\n5. Delete a node from beginning of the doubly linkedlist");
        printf("\n6. Delete a node from end of the doubly linkedlist");
        printf("\n7. Delete a node from particular position of the doubly linkedlist");
        printf("\n8. Create an entire doubly linkedlist");
        printf("\n9. Search for the element in doubly linked list");
        printf("\n10.Count the number of elements in doubly linked list");
        printf("\n11.Reverse the doubly linked list");
        printf("\n12.Display the doubly linked list");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter the data to be inserted: ");
            scanf("%d", &data);
            addToEmpty(&head, data);
            printf("DATA IN INSERTED NODE IS %d", head->data);
            break;
        case 2:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);
            insertAtBeg(&head, data);
            break;
        case 3:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 5:
            delAtBeg(&head);
            break;
        case 6: 
            delAtEnd(&head);
            break;
        case 9:
            printf("Enter the element to search: ");
            scanf("%d", &data);
            searchElement(&head,data);
            break;
        case 11:
            reverse(&head);
            break;
        case 12: 
            displayList(&head);
            break;
        }
    }

    return 0;
}

void addToEmpty(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    *head = temp;
}

void insertAtBeg(struct node **head, int data)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    temp->next = *head;
    (*head)->prev = temp; // link

    *head = temp; // head will point to the newly inserted first node now
    printf("NODE INSERTED!!");
}

void insertAtEnd(struct node **head, int data)
{
    struct node *ptr = *head;

    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->prev = NULL;
    temp->data = data;
    temp->next = NULL;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp = ptr;
}

void delAtBeg(struct node **head)
{
    struct node *ptr=*head;
    (*head)=(*head)->next;
    ptr->next=NULL;
    free(ptr);
    ptr=NULL;
}

void delAtEnd(struct node **head)
{
    struct node *ptr2=*head;
    struct node *ptr1=*head;
    while(ptr2->next!=NULL)
    {
        ptr1=ptr2;
        ptr2=ptr2->next;
    }
    ptr1->next=NULL;
    ptr2=NULL;
    free(ptr2);
}

void searchElement(struct node **head, int data)
{
    struct node *ptr=*head;
    int flag=0;
    while(ptr!=NULL)
    {
        if(ptr->data==data)
        {
            printf("Element Found!");
            flag=1;
            break;
        }
        ptr=ptr->next;
    }
    if(flag==0)
    {
        printf("Element not found \n");
    }
}
void reverse(struct node **head)
{
    struct node *current = *head;
    struct node *temp = NULL;

    while (current != NULL) {
        
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;

        current = current->prev;
    }

    if (temp != NULL) {
        *head = temp->prev;
    }
}


void displayList(struct node **head)
{
    if (*head == NULL)
        printf("EMPTY LINKEDLIST");
    struct node *ptr = *head;
    while (ptr != NULL)
    {
        printf("%d -> ", ptr->data);
        ptr = ptr->next;
    }
}

