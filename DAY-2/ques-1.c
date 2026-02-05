#include <stdio.h>

int main() {
    int n, pos;
    printf("Enter number of elements (n): ");
    scanf("%d", &n);

    int arr[100]; 
    printf("Enter %d integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter position to delete (1-based index): ");
    scanf("%d", &pos);
    
    if (pos < 1 || pos > n) {
        printf("Invalid position! Must be between 1 and %d.\n", n);
        return 1;
    }

    for (int i = pos - 1; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }

    n--;
    printf("Array after deletion:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}