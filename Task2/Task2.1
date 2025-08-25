#include <stdio.h>

void merge(int a[], int p, int q, int r);

// Merge Sort function
void mergeSort(int a[], int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        mergeSort(a, p, q);
        mergeSort(a, q + 1, r);
        merge(a, p, q, r);
    }
}

// Function to merge the subarrays
void merge(int a[], int p, int q, int r) {
    int b[100];  // Adjusted to a larger safe size
    int i = p, j = q + 1, k = 0;

    while (i <= q && j <= r) {
        if (a[i] < a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    while (i <= q) {
        b[k++] = a[i++];
    }

    while (j <= r) {
        b[k++] = a[j++];
    }

    // Copy sorted elements back to original array
    for (i = 0; i < k; i++) {
        a[p + i] = b[i];
    }
}

// Function to print the array
void printArray(int a[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() {
    int arr[] = {32, 45, 67, 2, 7};
    int len = sizeof(arr) / sizeof(arr[0]);

    printf("Given array:\n");
    printArray(arr, len);

    mergeSort(arr, 0, len - 1);

    printf("\nSorted array:\n");
    printArray(arr, len);

    return 0;
}
