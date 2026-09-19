#include <stdio.h>

int binarySearch(const int arr[], int n, int target, int *comparisons) {
    int low = 0;
    int high = n - 1;
    *comparisons = 0;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        (*comparisons)++;
        if (arr[mid] == target) {
            return mid;
        }

        (*comparisons)++;
        if (arr[mid] < target) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n, target, comparisons = 0;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    int emp_ids[n];
    printf("Enter %d employee IDs in ascending order:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &emp_ids[i]);
    }

    printf("Enter employee ID to search: ");
    scanf("%d", &target);

    int index = binarySearch(emp_ids, n, target, &comparisons);

    if (index != -1) {
        printf("\nResult: Employee ID %d found.\n", target);
        printf("Index (0-based): %d\n", index);
        printf("Position (1-based): %d\n", index + 1);
    } else {
        printf("\nResult: Employee ID %d is NOT present in the database.\n", target);
    }

    printf("Total comparisons : %d\n", comparisons);

    return 0;
}