/* Question: Selection Sort with Time Analysis
Write a C program to implement Selection Sort and measure
its execution time.
*/
#include <stdio.h>
#include <time.h>

int main() {
    int n, temp, min;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    start = clock();

    for (int i = 0; i < n - 1; i++) {

        min = i;

        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min])
                min = j;
        }

        temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array: ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nExecution Time = %f seconds\n", time_taken);

    return 0;
}
