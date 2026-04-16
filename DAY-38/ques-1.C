#include <stdio.h>
#define MAX 100

int deque[MAX];
int front = -1, rear = -1;

// Check empty
int isEmpty() {
    return front == -1;
}

// Check full
int isFull() {
    return (front == (rear + 1) % MAX);
}

// push_front
void push_front(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        front = (front - 1 + MAX) % MAX;
    }

    deque[front] = x;
}

// push_back
void push_back(int x) {
    if (isFull()) {
        printf("Overflow\n");
        return;
    }

    if (isEmpty()) {
        front = rear = 0;
    } else {
        rear = (rear + 1) % MAX;
    }

    deque[rear] = x;
}

// pop_front
void pop_front() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[front]);

    if (front == rear) {
        front = rear = -1;
    } else {
        front = (front + 1) % MAX;
    }
}

// pop_back
void pop_back() {
    if (isEmpty()) {
        printf("-1\n");
        return;
    }

    printf("%d\n", deque[rear]);

    if (front == rear) {
        front = rear = -1;
    } else {
        rear = (rear - 1 + MAX) % MAX;
    }
}

// front element
void getFront() {
    if (isEmpty()) {
        printf("-1\n");
    } else {
        printf("%d\n", deque[front]);
    }
}

// back element
void getBack() {
    if (isEmpty()) {
        printf("-1\n");
    } else {
        printf("%d\n", deque[rear]);
    }
}

// size
void size() {
    if (isEmpty()) {
        printf("0\n");
        return;
    }

    if (rear >= front)
        printf("%d\n", rear - front + 1);
    else
        printf("%d\n", MAX - front + rear + 1);
}

// display (extra)
void display() {
    if (isEmpty()) {
        printf("Empty\n");
        return;
    }

    int i = front;
    while (1) {
        printf("%d ", deque[i]);
        if (i == rear) break;
        i = (i + 1) % MAX;
    }
    printf("\n");
}

int main() {
    int choice, val;

    while (1) {
        printf("\n1.push_front 2.push_back 3.pop_front 4.pop_back\n");
        printf("5.front 6.back 7.size 8.display 9.exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                scanf("%d", &val);
                push_front(val);
                break;
            case 2:
                scanf("%d", &val);
                push_back(val);
                break;
            case 3:
                pop_front();
                break;
            case 4:
                pop_back();
                break;
            case 5:
                getFront();
                break;
            case 6:
                getBack();
                break;
            case 7:
                size();
                break;
            case 8:
                display();
                break;
            case 9:
                return 0;
        }
    }
}