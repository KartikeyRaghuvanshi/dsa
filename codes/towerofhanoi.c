#include <stdio.h>

void towerofhanoi(char from, char to, char other, int n)
{
    static int step = 1;
    if (n == 1)
        printf("Step %d: Move disk from %c to %c\n", step++, from, to);
    else
    {
        towerofhanoi(from, other, to, n - 1);
        towerofhanoi(from, to, other, 1);
        towerofhanoi(other, to, from, n - 1);
    }
}

int main()
{
    int n;
    printf("\nEnter number of disks: ");
    scanf("%d", &n);
    towerofhanoi('A', 'C', 'B', n);
    return 0;
}