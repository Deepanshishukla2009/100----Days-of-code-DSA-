#include <stdio.h>

int main() {
    int n, k;

    printf("enter size of array:");
    scanf("%d", &n);

    int arr[100000]; 
  
    printf("enter elements of array:");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("enter the value of key:");
    scanf("%d", &k);

    int comparisons = 0;
    int foundIndex = -1;

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (arr[i] == k) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        printf("Found at index %d\n", foundIndex);
    } else {
        printf("Not Found\n");
    }
    printf("Comparisons = %d\n", comparisons);

    return 0;
}