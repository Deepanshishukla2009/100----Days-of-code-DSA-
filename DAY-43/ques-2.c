/*Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

Example 1:

Input: root = [1,null,2,3]

Output: [1,3,2]

Explanation:



Example 2:

Input: root = [1,2,3,4,5,null,8,null,null,6,7,9]

Output: [4,2,6,5,7,1,3,9,8]

Explanation:



Example 3:

Input: root = []

Output: []

Example 4:

Input: root = [1]

Output: [1]

 

Constraints:

The number of nodes in the tree is in the range [0, 100].
-100 <= Node.val <= 100*/

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 100);
    struct TreeNode* stack[100];
    int top = -1;

    *returnSize = 0;

    while (root != NULL || top != -1) {
        // Go left
        while (root != NULL) {
            stack[++top] = root;
            root = root->left;
        }

        // Visit node
        root = stack[top--];
        result[(*returnSize)++] = root->val;

        // Go right
        root = root->right;
    }

    return result;
}