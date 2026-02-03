#include <stdio.h>

int main() {
    int n, pos, x;

    // Input size of array
    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int arr[100]; // assuming max size 100 for simplicity

    // Input array elements
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Input element and position
    printf("Enter element to insert (x): ");
    scanf("%d", &x);
    printf("Enter position (1-based index): ");
    scanf("%d", &pos);

    // Validate position
    if (pos < 1 || pos > n + 1) {
        printf("Invalid position! Must be between 1 and %d.\n", n + 1);
        return 1;
    }

    // Shift elements to the right
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }

    // Insert element
    arr[pos - 1] = x;
    n++; // array size increases

    // Print updated array
    printf("Array after insertion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}