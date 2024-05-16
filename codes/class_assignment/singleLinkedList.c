#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *link;
};
void insertatbeg(struct node **, int);
void insertatend(struct node **head, int data);
void delatbeg(struct node **head);
void delatend(struct node **head);
void delafter(struct node **head,int);
void display(struct node **head);
void insertafter(struct node **head, int x, int data);
void main()
{
    int choice, data, x;
    struct node *head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;

    while (1)
    {
        printf("\n*MENU");
        printf("\n1.Insert at beginning");
        printf("\n2.Insert at end");
        printf("\n3.Insert at particular position");
        printf("\n4.Delete at beginning");
        printf("\n5.Delete at end");
        printf("\n6.Delete a particular node");
        printf("\n7.Display the data(traverse)");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insertatbeg(&head, data);
            break;
        case 2:
            printf("Enter the data you want to insert: ");
            scanf("%d", &data);
            insertatend(&head, data);
            break;
        case 3:
            printf("Enter the data after which you want to insert the node: ");
            scanf("%d", &x);
            printf("Enter the data to insert: ");
            scanf("%d", &data);
            insertafter(&head, x, data);
            break;
        case 4:
            delatbeg(&head);
            break;
        case 5:
            delatend(&head);
            break;
        case 6:
            delafter(&head,x);
        case 7:
            display(&head);
            break;
        }
    }
}

void insertatbeg(struct node **head, int data)
{
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    temp->link = *head;
    *head = temp;
}

void insertatend(struct node **head, int data)
{
    struct node *ptr = *head;
    struct node *temp = malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    if (*head == NULL)
    {
        *head = temp;
    }

    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}

void insertafter(struct node **head, int x, int data)
{
    struct node *ptr = *head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;

    while (ptr->data != x && ptr != NULL)
    {
        ptr = ptr->link;
    }
    if (ptr->data == x)
    {
        temp->link = ptr->link;
        ptr->link = temp;
        printf("Node inserted!");
    }

}

void display(struct node **head)
{
    struct node *temp = *head;
    if (*head == NULL)
        printf("Linkedlist is empty!");
    else
    {
        while (temp != NULL)
        {
            printf("%d->", temp->data);
            temp = temp->link;
        }
    }
}

void delatbeg(struct node **head)
{
    if (*head == NULL)
    {
        printf("Linkedlist is empty");
        return;
    }
    else if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct node *temp;
        temp = *head;
        *head = (*head)->link;
        free(temp);
    }
}

void delatend(struct node **head)
{
    struct node *temp = *head;
    struct node *temp0 = *head;
    if (*head == NULL)
    {
        printf("Linkedlist is empty!");
    }
    else if ((*head)->link == NULL)
    {
        free(*head);
        *head = NULL;
    }
    while (temp->link != NULL)
    {
        temp0 = temp;
        temp = temp->link;
    }
    temp0->link = NULL;
    free(temp);
}

void delafter(struct node **head, int x)
{
    printf("Enter the data of the node to be deleted: ");
    scanf("%d", &x);
    struct node *temp = *head;
    struct node *temp0 = *head;

    while(temp->data!=x)
    {
        temp0=temp;
        temp=temp->link;
    }
    temp0->link=temp->link;
    temp->link=NULL;
    free(temp);
}