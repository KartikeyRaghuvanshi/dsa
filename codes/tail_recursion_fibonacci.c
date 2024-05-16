#include<stdio.h>

int fibo(int n, int res, int acc) {
    if (n == 0)
        return res;
    else
        return fibo(n - 1, acc, res + acc);
}

int main() {
    int n;
    printf("Enter the number of terms for Fibonacci series: ");
    scanf("%d", &n);
    printf("Fibonacci series up to %d terms: ", n);
    for (int i = 0; i < n; i++) {
        printf("%d ", fibo(i, 0, 1));
    }
    printf("\n");
    return 0;
}
// #include<stdio.h>

// void fibo(int n, int res, int acc) {
//     if (n > 0)
//     {
//         printf("%d",res);
//         fibo(n-1,acc,res+acc);
//     }
// }

// int main() {
//     int n;
//     printf("Enter the number of terms for Fibonacci series: ");
//     scanf("%d", &n);
//     fibo(n,0,1);
//     return 0;
// }
