// Q7. Write a C program to rotate an array to the right by K positions without using another array. Array: 1 2 3 4 5 6 K = 2 Output: 5 6 1 2 3 4
#include <stdio.h>

void reverse(int a[], int start, int end) {
    int temp;

    while(start < end) {

        temp = a[start];
        a[start] = a[end];
        a[end] = temp;

        start++;
        end--;
    }
}

int main() {
    int n, k, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter K: ");
    scanf("%d", &k);

    k = k % n;

    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);

    printf("Array after right rotation:\n");

    for(i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}
