#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int coeff;
    int power;
    struct nodetype *next;
} node;

// Function to search for a node with a given power
void search(node *ptr, int power, node **location)
{
    *location = NULL; // Initialize the location pointer to NULL
    while (ptr != NULL)
    {
        if (ptr->power == power)
        {
            *location = ptr; // Update the location pointer if the node is found
            return;
        }
        ptr = ptr->next;
    }
}

// Function to insert a node into a polynomial linked list
void insertNode(node **ptr, int coeff, int power)
{
    node *temp = (node *)malloc(sizeof(node));
    temp->coeff = coeff;
    temp->power = power;
    temp->next = NULL;

    if (*ptr == NULL)
    {
        *ptr = temp;
    }
    else
    {
        node *last = *ptr;
        while (last->next != NULL)
        {
            last = last->next;
        }
        last->next = temp;
    }
}

// Function to multiply two polynomials
void multiplyPolynomial(node *ptr1, node *ptr2, node **ptr3)
{
    int powe, coef;
    node *temp, *loc, *tt;
    while (ptr1 != NULL)
    {
        temp = ptr2;
        while (temp != NULL)
        {
            coef = ptr1->coeff * temp->coeff;
            powe = ptr1->power + temp->power;
            tt = *ptr3;
            search(tt, powe, &loc); // Use the search function to locate the node
            if (loc == NULL)
                insertNode(ptr3, coef, powe);
            else
                loc->coeff += coef;

            temp = temp->next;
        }
        ptr1 = ptr1->next;
    }
}

// Function to print a polynomial
void printPolynomial(node *ptr)
{
    while (ptr != NULL)
    {
        printf("%dx^%d", ptr->coeff, ptr->power);
        ptr = ptr->next;
        if (ptr != NULL)
            printf(" + ");
    }
    printf("\n");
}

int main()
{
    node *poly1 = NULL;
    node *poly2 = NULL;
    int coeff, power;
    int num_terms;

    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &num_terms);
    printf("Enter the coefficient and power for each term of Polynomial 1:\n");
    for (int i = 0; i < num_terms; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertNode(&poly1, coeff, power);
    }

    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &num_terms);
    printf("Enter the coefficient and power for each term of Polynomial 2:\n");
    for (int i = 0; i < num_terms; i++)
    {
        printf("Term %d: ", i + 1);
        scanf("%d %d", &coeff, &power);
        insertNode(&poly2, coeff, power);
    }

    node *result = NULL;
    multiplyPolynomial(poly1, poly2, &result);

    printf("Result of multiplication: ");
    printPolynomial(result);

    return 0;
}
