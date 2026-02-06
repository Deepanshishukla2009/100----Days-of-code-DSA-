#include <stdio.h>

int main() {
    int n;
    printf("enter no of elements:");
    scanf("%d", &n);
    int arr[n];
    printf("enter elements:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%d", arr[0]);

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf(" %d", arr[i]);
        }
    }
    return 0;
}