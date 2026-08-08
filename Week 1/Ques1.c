// Write a C program to find the second-largest distinct element in an array without sorting it.
#include <stdio.h>
#include <limits.h>

int main() {
    int n, i;
    int largest = INT_MIN;
    int second = INT_MIN;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(i = 0; i < n; i++) {
        if(a[i] > largest) {
            second = largest;
            largest = a[i];
        }
        else if(a[i] > second && a[i] != largest) {
            second = a[i];
        }
    }

    if(second == INT_MIN)
        printf("Second largest distinct element does not exist.");
    else
        printf("Second largest distinct element = %d", second);

    return 0;
}
