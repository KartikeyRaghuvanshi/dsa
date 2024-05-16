//program for polynomial ......................................................
#include <stdio.h>
#include <stdlib.h>

typedef struct nodetype
{
    int coeff;
    int power;
    struct nodetype *next;
} node;

void addNode(node **ptr, int coeff, int power) {
    node *temp = (node *)malloc(sizeof(node));
    temp->coeff = coeff;
    temp->power = power;
    temp->next = NULL;

    if (*ptr == NULL) {
        *ptr = temp;
    } else {
        node *last = *ptr;
        while (last->next != NULL) {
            last = last->next;
        }
        last->next = temp;
    }
}

void addPolynomial(node *ptr1, node *ptr2, node **ptr3)
{
    int power;
    float coef;
    while ((ptr1 != NULL) && (ptr2 != NULL))
    {
        if (ptr1->power > ptr2->power)
        {
            coef = ptr1->coeff;
            power = ptr1->power;
            ptr1 = ptr1->next;
        }
        else if (ptr1->power < ptr2->power)
        {
            coef = ptr2->coeff;
            power = ptr2->power;
            ptr2 = ptr2->next;
        }
        else
        {
            coef = ptr1->coeff + ptr2->coeff;
            power = ptr1->power;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        if (coef != 0)
        {
            addNode(ptr3, coef, power);
        }
    }
    if (ptr1 == NULL)
    {
        for (; ptr2 != NULL; ptr2 = ptr2->next)
        {
            addNode(ptr3, ptr2->coeff, ptr2->power);
        }
    }
    else if (ptr2 == NULL)
    {
        for (; ptr1 != NULL; ptr1 = ptr1->next)
        {
            addNode(ptr3, ptr1->coeff, ptr1->power);
        }
    }
}

int main() {
    node *poly1 = NULL;
    node *poly2 = NULL;
    int coeff, power;
    int i;

    printf("Enter the number of terms for Polynomial 1: ");
    scanf("%d", &i);
    printf("Enter the coefficient and power for each term of Polynomial 1:\n");
    for (int j = 0; j < i; j++) {
        scanf("%d %d", &coeff, &power);
        addNode(&poly1, coeff, power);
    }

    printf("Enter the number of terms for Polynomial 2: ");
    scanf("%d", &i);
    printf("Enter the coefficient and power for each term of Polynomial 2:\n");
    for (int j = 0; j < i; j++) {
        scanf("%d %d", &coeff, &power);
        addNode(&poly2, coeff, power);
    }

    node *result = NULL;
    addPolynomial(poly1, poly2, &result);
    
    // Print the result
    node *temp = result;
    printf("The sum of the polynomials is: ");
    while (temp != NULL) {
        printf("%dx^%d ", temp->coeff, temp->power);
        if (temp->next != NULL)
            printf("+ ");
        temp = temp->next;
    }

    return 0;
}
