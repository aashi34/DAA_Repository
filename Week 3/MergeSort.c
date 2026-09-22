/* Question: Merge Sort with Time Analysis
Write a C program to implement Merge Sort and measure
its execution time.
*/
#include <stdio.h>
#include <time.h>

void merge(int arr[], int low, int mid, int high) {

    int temp[high - low + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high) {

        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= high)
        temp[k++] = arr[j++];

    for (i = low, k = 0; i <= high; i++, k++)
        arr[i] = temp[k];
}

void mergeSort(int arr[], int low, int high) {

    if (low < high) {

        int mid = low + (high - low) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
    }
}

int main() {

    int n;
    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter array elements:\n");

    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    start = clock();

    mergeSort(arr, 0, n - 1);

    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    printf("Sorted Array: ");

    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nExecution Time = %f seconds\n", time_taken);

    return 0;
}
