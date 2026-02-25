#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void insertEnd(struct Node** head, int value) {
    struct Node* newNode = createNode(value);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}


struct Node* mergeLists(struct Node* l1, struct Node* l2) {
   
    struct Node dummy;
    struct Node* tail = &dummy;
    dummy.next = NULL;

    while (l1 != NULL && l2 != NULL) {
        if (l1->data <= l2->data) {
            tail->next = l1;
            l1 = l1->next;
        } else {
            tail->next = l2;
            l2 = l2->next;
        }
        tail = tail->next;
    }

   
    if (l1 != NULL) tail->next = l1;
    else tail->next = l2;

    return dummy.next;
}

void traverseList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n, m;
    scanf("%d", &n);

    struct Node* list1 = NULL;
    for (int i = 0; i < n; i++) {
        int value;
        scanf("%d", &value);
        insertEnd(&list1, value);
    }

    scanf("%d", &m);
    struct Node* list2 = NULL;
    for (int i = 0; i < m; i++) {
        int value;
        scanf("%d", &value);
        insertEnd(&list2, value);
    }

    struct Node* merged = mergeLists(list1, list2);

    traverseList(merged);

    return 0;
}