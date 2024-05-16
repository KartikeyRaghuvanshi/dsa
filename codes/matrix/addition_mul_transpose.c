#include <stdio.h>

int linearSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return 0;
}

int main()
{
    int num;
       printf("Please enter the appropriate number........\n");
       printf("Enter 1 for Linear search........\n");
       printf("Enter 2 for Matrix addition........\n");
       printf("Enter 3 for Matrix multiplication........\n");
       printf("Enter 4 for Transpose of matrix........\n");
       printf("Enter 5 for Exit........\n");
       
       printf("Enter the value:\n");
       scanf("%d",&num);
       
       switch(num)
       {
           case 1:
           {
                printf("You selected for Linear search........\n");
                
                int arr[5];
                int target,i;
                printf("Enter the elemets of array:\n");
    
                // taking input in array
                for(i=0;i<5;i++)
                {
                    printf("enter %d element:",i+1);
                    scanf("%d",&arr[i]);
                }
                //printing an array    
                printf("\nthe array you entered is");
                for(i=0;i<5;i++)
                {
                    printf("\n%d",arr[i]);
                }
                printf("\nenter the value you want to search in array:");
                scanf("%d",&target);
                int n = sizeof(arr) / sizeof(arr[0]);
                int result = linearSearch(arr, n, target);
                if (result == 0) {
                    printf("\nElement is not present in the array\n");
                } else {
                    printf("\nElement is present at index %d\n", result+1);
                }
               
               break;
           }
           case 2:
           {
                printf("You selected for Matrix addition........\n");
                int arr1[50][50], brr1[50][50], crr1[50][50], i, j, n;

                // Enter input
                printf("\nAddition of two Matrices :\n");
                printf("------------------------------\n");
                printf("Input the size of the square matrix (less than 5): ");
                scanf("%d", &n);
            
                // Input elements for the first matrix
                printf("Input elements in the first matrix :\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("element - [%d],[%d] : ", i, j);
                        scanf("%d", &arr1[i][j]);
                    }
                }
            
                // Input elements for the second matrix
                printf("Input elements in the second matrix :\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < n; j++) {
                        printf("element - [%d],[%d] : ", i, j);
                        scanf("%d", &brr1[i][j]);
                    }
                }
            
                // Display the first matrix
                printf("\nThe First matrix is :\n");
                for (i = 0; i < n; i++) {
                    printf("\n");
                    for (j = 0; j < n; j++)
                        printf("%d\t", arr1[i][j]);
                }
            
                // Display the second matrix
                printf("\nThe Second matrix is :\n");
                for (i = 0; i < n; i++) {
                    printf("\n");
                    for (j = 0; j < n; j++)
                        printf("%d\t", brr1[i][j]);
                }
            
                // Calculate the sum of the matrices
                for (i = 0; i < n; i++)
                    for (j = 0; j < n; j++)
                        crr1[i][j] = arr1[i][j] + brr1[i][j];
            
                // Display the addition of two matrices
                printf("\nThe Addition of two matrix is : \n");
                for (i = 0; i < n; i++) {
                    printf("\n");
                    for (j = 0; j < n; j++)
                        printf("%d\t", crr1[i][j]);
                }
                printf("\n\n");
               
               break;
           }
           case 3:
           {
               printf("You selected for Matrix multiplication........\n");
               
                int arr1[50][50], brr1[50][50], crr1[50][50], i, j, k, n, m;

                // Prompt user for input
                printf("\n\nMultiplication of two Matrices :\n");
                printf("------------------------------\n");
                printf("Input the size of the first matrix (less than 5): ");
                scanf("%d", &n);
                printf("Input the size of the second matrix (less than 5): ");
                scanf("%d", &m);
            
                // Input elements for the first matrix
                printf("Input elements in the first matrix :\n");
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        printf("element - [%d],[%d] : ", i, j);
                        scanf("%d", &arr1[i][j]);
                    }
                }
            
                // Input elements for the second matrix
                printf("Input elements in the second matrix :\n");
                for (i = 0; i < m; i++) {
                    for (j = 0; j < m; j++) {
                        printf("element - [%d],[%d] : ", i, j);
                        scanf("%d", &brr1[i][j]);
                    }
                }
            
                // Calculate the product of the matrices
                for (i = 0; i < n; i++) {
                    for (j = 0; j < m; j++) {
                        crr1[i][j] = 0;
                        for (k = 0; k < m; k++)
                            crr1[i][j] += arr1[i][k] * brr1[k][j];
                    }
                }
            
                // Display the product of two matrices
                printf("\nThe Product of two matrix is : \n");
                for (i = 0; i < n; i++) {
                    printf("\n");
                    for (j = 0; j < m; j++)
                        printf("%d\t", crr1[i][j]);
                }
                printf("\n\n");
               break;
           }
           case 4:
           {
               printf("You selected for Transpose of matrix........\n");
                  int a[10][10], transpose[10][10], r, c;
                  printf("Enter rows and columns: ");
                  scanf("%d %d", &r, &c);
                
                  // asssigning elements to the matrix
                  printf("\nEnter matrix elements:\n");
                  for (int i = 0; i < r; ++i)
                  for (int j = 0; j < c; ++j) {
                    printf("Enter element a%d%d: ", i + 1, j + 1);
                    scanf("%d", &a[i][j]);
                  }
                
                  // printing the matrix a[][]
                  printf("\nEntered matrix: \n");
                  for (int i = 0; i < r; ++i)
                  for (int j = 0; j < c; ++j) {
                    printf("%d  ", a[i][j]);
                    if (j == c - 1)
                    printf("\n");
                  }
                
                  // computing the transpose
                  for (int i = 0; i < r; ++i)
                  for (int j = 0; j < c; ++j) {
                    transpose[j][i] = a[i][j];
                  }
                
                  // printing the transpose
                  printf("\nTranspose of the matrix:\n");
                  for (int i = 0; i < c; ++i)
                  for (int j = 0; j < r; ++j) {
                    printf("%d  ", transpose[i][j]);
                    if (j == r - 1)
                    printf("\n");
                  }
               break;
           }
           case 5:
           {
               printf("You selected for Exit........\n");
               break;
           }
       }
   

    return 0;
}