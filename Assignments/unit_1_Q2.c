#include <stdio.h>

void printArray(const int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int insertionSort(int arr[], int n) {
    int total_shifts = 0;

    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            total_shifts++;
            j--;
        }
        arr[j + 1] = key;

        printf("Pass %d (inserted %d): ", i, key);
        printArray(arr, n);
    }

    return total_shifts;
}

int main() {
    int n;

    printf("Enter number of students (n): ");
    scanf("%d", &n);

    int marks[n];
    printf("Enter %d student marks:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &marks[i]);
    }

    printf("\nInitial Marks List: ");
    printArray(marks, n);
    printf("\n\n\n");

    int shifts = insertionSort(marks, n);

    printf("\n\n\n");
    printf("Final Sorted Marks: ");
    printArray(marks, n);
    printf("Total element shifts required: %d\n", shifts);

    return 0;
}