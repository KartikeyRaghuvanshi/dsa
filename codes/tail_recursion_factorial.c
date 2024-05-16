#include<stdio.h>

int fact(int n, int initial) {
    if (n <= 1)
        return initial;
    else
        return fact(n - 1, initial * n);
}

int main() {
    int n, initial = 1;
    printf("Enter the number for factorial: ");
    scanf("%d", &n);
    printf("Factorial of %d is: %d\n", n, fact(n, initial));
    return 0;
}
