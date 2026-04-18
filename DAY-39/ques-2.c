/*Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2

Output: [1,2]

Example 2:

Input: nums = [1], k = 1

Output: [1]

Example 3:

Input: nums = [1,2,1,2,1,2,3,1,3,2], k = 2

Output: [1,2]

 

Constraints:

1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.*/


#include <stdio.h>
#include <stdlib.h>

#define RANGE 20001

typedef struct {
    int value;
    int freq;
} Node;

// Swap
void swap(Node *a, Node *b) {
    Node t = *a;
    *a = *b;
    *b = t;
}

// Heapify Up
void heapifyUp(Node heap[], int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent].freq > heap[index].freq) {
            swap(&heap[parent], &heap[index]);
            index = parent;
        } else break;
    }
}

// Heapify Down
void heapifyDown(Node heap[], int size, int index) {
    while (1) {
        int smallest = index;
        int left = 2 * index + 1;
        int right = 2 * index + 2;

        if (left < size && heap[left].freq < heap[smallest].freq)
            smallest = left;
        if (right < size && heap[right].freq < heap[smallest].freq)
            smallest = right;

        if (smallest != index) {
            swap(&heap[index], &heap[smallest]);
            index = smallest;
        } else break;
    }
}

int* topKFrequent(int* nums, int n, int k, int* returnSize) {
    int freq[RANGE] = {0};

    // Count frequency
    for (int i = 0; i < n; i++) {
        freq[nums[i] + 10000]++;
    }

    Node heap[100001];
    int size = 0;   // ✅ now local

    // Build heap
    for (int i = 0; i < RANGE; i++) {
        if (freq[i] > 0) {
            Node node = {i - 10000, freq[i]};

            heap[size] = node;
            heapifyUp(heap, size);
            size++;

            if (size > k) {
                heap[0] = heap[size - 1];
                size--;
                heapifyDown(heap, size, 0);
            }
        }
    }

    int* result = (int*)malloc(k * sizeof(int));
    *returnSize = k;

    // Extract elements
    for (int i = 0; i < k; i++) {
        result[i] = heap[0].value;
        heap[0] = heap[size - 1];
        size--;
        heapifyDown(heap, size, 0);
    }

    return result;
}