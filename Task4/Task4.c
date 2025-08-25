#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

// Function to merge two sorted subarrays
void simple_merge(int a[], int low, int mid, int high) {
    int i = low, j = mid + 1, k = low;
    int c[10000];  // Temporary array

    while (i <= mid && j <= high) {
        if (a[i] < a[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = a[j++];
        }
    }

    while (i <= mid)
        c[k++] = a[i++];

    while (j <= high)
        c[k++] = a[j++];

    for (i = low; i <= high; i++)
        a[i] = c[i];
}

// Parallel merge sort function
void merge_sort_parallel(int a[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        #pragma omp parallel sections
        {
            #pragma omp section
            merge_sort_parallel(a, low, mid);

            #pragma omp section
            merge_sort_parallel(a, mid + 1, high);
        }

        simple_merge(a, low, mid, high);
    }
}

int main() {
    int a[10000], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    // Set number of OpenMP threads
    omp_set_num_threads(4);

    // Perform parallel merge sort
    merge_sort_parallel(a, 0, n - 1);

    // Display sorted array
    printf("\nSorted array:\n");
    for (i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");

    return 0;
}
