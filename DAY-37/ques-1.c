#include <stdio.h>

#define MAX 100

int pq[MAX];
int size = 0;

// Insert
void insert(int x) {
    if (size == MAX) {
        printf("Queue Overflow\n");
        return;
    }
    pq[size++] = x;
}

// Find min index
int findMinIndex() {
    if (size == 0) return -1;

    int min = 0;
    for (int i = 1; i < size; i++) {
        if (pq[i] < pq[min]) {
            min = i;
        }
    }
    return min;
}

// Delete
void deletePQ() {
    int minIndex = findMinIndex();

    if (minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("Deleted: %d\n", pq[minIndex]);

    for (int i = minIndex; i < size - 1; i++) {
        pq[i] = pq[i + 1];
    }
    size--;
}

// Peek
void peek() {
    int minIndex = findMinIndex();

    if (minIndex == -1) {
        printf("-1\n");
        return;
    }

    printf("Top Priority: %d\n", pq[minIndex]);
}

// Display (extra for user)
void display() {
    if (size == 0) {
        printf("Queue is empty\n");
        return;
    }

    printf("Queue elements: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", pq[i]);
    }
    printf("\n");
}

int main() {
    int choice, value;

    while (1) {
        printf("\n--- Priority Queue Menu ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insert(value);
                break;

            case 2:
                deletePQ();
                break;

            case 3:
                peek();
                break;

            case 4:
                display();
                break;

            case 5:
                return 0;

            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}