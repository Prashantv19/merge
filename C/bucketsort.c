#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10

void bucketSort(int arr[], int n) {
    int max_val = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max_val) {
            max_val = arr[i];
        }
    }

    int bucket[BUCKET_SIZE][n];
    int bucket_count[BUCKET_SIZE] = {0};

    // Scatter elements into buckets
    for (int i = 0; i < n; i++) {
        int bucket_index = (int)((double)arr[i] / max_val * (BUCKET_SIZE - 1));
        bucket[bucket_index][bucket_count[bucket_index]++] = arr[i];
    }

    // Sort individual buckets (using insertion sort here)
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 1; j < bucket_count[i]; j++) {
            int key = bucket[i][j];
            int k = j - 1;
            while (k >= 0 && bucket[i][k] > key) {
                bucket[i][k + 1] = bucket[i][k];
                k--;
            }
            bucket[i][k + 1] = key;
        }
    }

    // Gather elements from buckets
    int index = 0;
    for (int i = 0; i < BUCKET_SIZE; i++) {
        for (int j = 0; j < bucket_count[i]; j++) {
            arr[index++] = bucket[i][j];
        }
    }
}

int main() {
    int n;

    // Ask user for the number of elements in the array
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Take array elements input from the user
    printf("Enter %d elements: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the unsorted array
    printf("Unsorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform bucket sort
    bucketSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
