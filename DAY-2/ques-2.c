#include <stdio.h>

int main() {
    int n, pos;

    // Input size of array
    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int arr[100]; // assuming max size 100 for simplicity

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input position to delete
    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > n) {
        printf("Invalid position! Must be between 1 and %d.\n", n);
        return 1;
    }

    // Shift elements to the left
    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--; // array size decreases

    // Print updated array
    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}