#include <stdio.h>
#include <stdlib.h>

typedef struct columnNodeType
{
    int col;
    int element;
    struct columnNodeType *link;
} columnNode;

typedef struct rowNodeType
{
    int row;
    struct rowNodeType *next;
    struct columnNodeType *first;
} rowNode;

typedef struct headNodeType
{
    int nRow;
    int nCol;
    int num;
    struct rowNodeType *head;
} headerNode;

// Function to create a new column node
columnNode *createColumnNode(int col, int element)
{
    columnNode *newNode = (columnNode *)malloc(sizeof(columnNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->col = col;
    newNode->element = element;
    newNode->link = NULL;
    return newNode;
}

// Function to create a new row node
rowNode *createRowNode(int row)
{
    rowNode *newNode = (rowNode *)malloc(sizeof(rowNode));
    if (newNode == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->row = row;
    newNode->next = NULL;
    newNode->first = NULL;
    return newNode;
}

// Function to create a new sparse matrix
headerNode *createSparseMatrix(int nRow, int nCol)
{
    headerNode *matrix = (headerNode *)malloc(sizeof(headerNode));
    if (matrix == NULL)
    {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    matrix->nRow = nRow;
    matrix->nCol = nCol;
    matrix->num = 0;
    matrix->head = NULL;
    return matrix;
}

// Function to insert an element into the sparse matrix
void insertElement(headerNode *matrix, int row, int col, int element)
{
    if (row >= matrix->nRow || col >= matrix->nCol)
    {
        printf("Invalid row or column index.\n");
        return;
    }
    rowNode *currentRow = matrix->head;
    rowNode *prevRow = NULL;
    while (currentRow != NULL && currentRow->row < row)
    {
        prevRow = currentRow;
        currentRow = currentRow->next;
    }
    if (currentRow == NULL || currentRow->row > row)
    {
        rowNode *newRow = createRowNode(row);
        newRow->next = currentRow;
        if (prevRow == NULL)
            matrix->head = newRow;
        else
            prevRow->next = newRow;
        currentRow = newRow;
    }
    columnNode *currentColumn = currentRow->first;
    columnNode *prevColumn = NULL;
    while (currentColumn != NULL && currentColumn->col < col)
    {
        prevColumn = currentColumn;
        currentColumn = currentColumn->link;
    }
    if (currentColumn == NULL || currentColumn->col > col)
    {
        columnNode *newColumn = createColumnNode(col, element);
        newColumn->link = currentColumn;
        if (prevColumn == NULL)
            currentRow->first = newColumn;
        else
            prevColumn->link = newColumn;
        matrix->num++;
    }
    else
    {
        currentColumn->element = element;
    }
}

// Function to print the sparse matrix
void printSparseMatrix(headerNode *matrix)
{
    printf("Sparse Matrix:\n");
    rowNode *currentRow = matrix->head;
    while (currentRow != NULL)
    {
        columnNode *currentColumn = currentRow->first;
        while (currentColumn != NULL)
        {
            printf("(%d, %d, %d) ", currentRow->row, currentColumn->col, currentColumn->element);
            currentColumn = currentColumn->link;
        }
        currentRow = currentRow->next;
    }
    printf("\n");
}

int main()
{
    int nRow, nCol;
    printf("Enter the number of rows and columns: ");
    scanf("%d %d", &nRow, &nCol);

    headerNode *sparseMatrix = createSparseMatrix(nRow, nCol);

    int numElements;
    printf("Enter the number of non-zero elements: ");
    scanf("%d", &numElements);

    for (int i = 0; i < numElements; i++)
    {
        int row, col, element;
        printf("Enter element %d (row, column, value): ", i + 1);
        scanf("%d %d %d", &row, &col, &element);
        insertElement(sparseMatrix, row, col, element);
    }

    printSparseMatrix(sparseMatrix);

    return 0;
}
