#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

// Queue implementation using array
int queue[MAX];
int front = 0, rear = -1;

// Stack implementation using array
int stack[MAX];
int top = -1;

// Enqueue
void enqueue(int x) {
    queue[++rear] = x;
}

// Dequeue
int dequeue() {
    return queue[front++];
}

// Stack push
void push(int x) {
    stack[++top] = x;
}

// Stack pop
int pop() {
    return stack[top--];
}

int main() {
    int N;

    printf("Enter number of elements: ");
    scanf("%d", &N);

    printf("Enter %d elements:\n", N);
    for (int i = 0; i < N; i++) {
        int x;
        scanf("%d", &x);
        enqueue(x);
    }

    // Step 1: Push queue elements into stack
    while (front <= rear) {
        push(dequeue());
    }

    // Reset queue
    front = 0;
    rear = -1;

    // Step 2: Pop from stack and enqueue back
    while (top != -1) {
        enqueue(pop());
    }

    // Print reversed queue
    printf("Reversed queue:\n");
    for (int i = front; i <= rear; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}