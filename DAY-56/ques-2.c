/*Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).

 

Example 1:


Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:


Input: root = [1,2,2,null,3,null,3]
Output: false
 

Constraints:

The number of nodes in the tree is in the range [1, 1000].
-100 <= Node.val <= 100*/

#include <stdbool.h>

bool isSymmetric(struct TreeNode* root) {
    if (root == NULL) return true;

    struct TreeNode* queue[2000];
    int front = 0, rear = 0;

    queue[rear++] = root->left;
    queue[rear++] = root->right;

    while (front < rear) {
        struct TreeNode* t1 = queue[front++];
        struct TreeNode* t2 = queue[front++];

        if (t1 == NULL && t2 == NULL) continue;
        if (t1 == NULL || t2 == NULL) return false;

        if (t1->val != t2->val) return false;

        queue[rear++] = t1->left;
        queue[rear++] = t2->right;

        queue[rear++] = t1->right;
        queue[rear++] = t2->left;
    }

    return true;
}