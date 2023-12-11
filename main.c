#include <stdio.h>

// Sorts an array using selection sort
void sortArray(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // Swap the current element with the minimum element
        if (minIndex != i) {
            int temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

// Gets the minimum, median, and maximum values from an array
void getMinMedMax(int arr[], int size, int *min, float *med, int *max) {
    sortArray(arr, size);

    *min = arr[0];
    *max = arr[size - 1];

    if (size % 2 == 0) {
        int midIndex = size / 2;
        *med = (arr[midIndex - 1] + arr[midIndex]) / 2.0;
    } else {
        *med = arr[size / 2];
    }
}

int main() {
    int array1[] = {0, 9, 2, 5, 3};
    int size1 = sizeof(array1) / sizeof(array1[0]);

    int min1, max1;
    float med1;

    getMinMedMax(array1, size1, &min1, &med1, &max1);
    printf("(Min, Med, Max) = (%d, %.1f, %d)\n", min1, med1, max1);

    int array2[] = {9, 9, 2, 2, 4, 3};
    int size2 = sizeof(array2) / sizeof(array2[0]);

    int min2, max2;
    float med2;

    getMinMedMax(array2, size2, &min2, &med2, &max2);
    printf("(Min, Med, Max) = (%d, %.1f, %d)\n", min2, med2, max2);

    return 0;
}
