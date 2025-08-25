#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

// Function to swap two integers
void swap(int *x, int *y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

// Function to generate random numbers
void generate_random(int a[], int n) {
    int i;
    srand(time(0));
    for (i = 0; i < n; i++) {
        a[i] = rand() % 1000;
    }
}

// Partition function for quicksort
int Partition(int a[], int l, int h) {
    int i = l, j = h + 1;
    int pivot = a[l];

    while (1) {
        while (++i <= h && a[i] < pivot);
        while (--j >= l && a[j] > pivot);
        if (i >= j) break;
        swap(&a[i], &a[j]);
    }

    swap(&a[l], &a[j]);
    return j;
}

// Quicksort function
void Quicksort(int a[], int l, int h) {
    if (l < h) {
        int s = Partition(a, l, h);
        Quicksort(a, l, s - 1);
        Quicksort(a, s + 1, h);
    }
}

int main() {
    int a[100000], i, ch, n;
    struct timeval t1, t2;
    double start, end;
    FILE *fp;

    printf("Enter the type of operation\n");
    printf("1 - Randomly generate numbers and quicksort\n");
    printf("2 - Enter the number of values to generate and sort\n");
    scanf("%d", &ch);

    switch (ch) {
        case 1:
            fp = fopen("quicksort.txt", "w");
            if (fp == NULL) {
                printf("Failed to open file.\n");
                return 1;
            }

            for (i = 10000; i <= 95000; i += 5000) {
                generate_random(a, i);
                gettimeofday(&t1, NULL);
                Quicksort(a, 0, i - 1);
                gettimeofday(&t2, NULL);

                start = t1.tv_sec + t1.tv_usec / 1000000.0;
                end = t2.tv_sec + t2.tv_usec / 1000000.0;

                printf("%d\t%lf\n", i, end - start);
                fprintf(fp, "%d\t%lf\n", i, end - start);
            }

            fclose(fp);
            break;

        case 2:
            printf("Enter the number of values to be generated: ");
            scanf("%d", &n);
            generate_random(a, n);

            printf("Original numbers are:\n");
            for (i = 0; i < n; i++) {
                printf("%d\t", a[i]);
            }
            printf("\n");

            gettimeofday(&t1, NULL);
            Quicksort(a, 0, n - 1);
            gettimeofday(&t2, NULL);

            start = t1.tv_sec + t1.tv_usec / 1000000.0;
            end = t2.tv_sec + t2.tv_usec / 1000000.0;

            printf("%d\t%lf\n", n, end - start);
            printf("Sorted numbers are:\n");
            for (i = 0; i < n; i++) {
                printf("%d\t", a[i]);
            }
            printf("\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
