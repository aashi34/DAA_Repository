// Q2. Write a program to count the frequency of each distinct element in an array.
#include <stdio.h>

int main() {
    int n, i, j, count;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    int visited[n];

    printf("Enter elements:\n");
    for(i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        visited[i] = 0;
    }

    printf("\nFrequency of elements:\n");

    for(i = 0; i < n; i++) {

        if(visited[i] == 1)
            continue;

        count = 1;

        for(j = i + 1; j < n; j++) {
            if(a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d occurs %d time(s)\n", a[i], count);
    }

    return 0;
}
