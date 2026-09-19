/*Question: Binary Search with Time Graph Analysis
Write a C program to implement Binary Search and measure the execution time for searching an element.
Analyze the time complexity for different input sizes and plot a graph of Input Size (N) vs Execution Time.

Time Complexity:
Best Case    : O(1)
Average Case : O(log N)
Worst Case   : O(log N)

Space Complexity: O(1)
*/ 
#include <stdio.h>
#include <time.h>

int main() {
    int n, key;
    int low, high, mid;
    int found = -1;

    clock_t start, end;
    double time_taken;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    printf("Enter elements in sorted order:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &key);

    low = 0;
    high = n - 1;

    // Start measuring time
    start = clock();

    while (low <= high) {

        mid = low + (high - low) / 2;

        if (arr[mid] == key) {
            found = mid;
            break;
        }

        else if (arr[mid] < key) {
            low = mid + 1;
        }

        else {
            high = mid - 1;
        }
    }

    // Stop measuring time
    end = clock();

    time_taken = ((double)(end - start)) / CLOCKS_PER_SEC;

    if (found != -1)
        printf("Element found at index %d\n", found);
    else
        printf("Element not found\n");

    printf("Execution Time = %f seconds\n", time_taken);

    return 0;
}
