/*Given two integer arrays preorder and inorder where preorder is the preorder traversal of a binary tree and inorder is the inorder traversal of the same tree, construct and return the binary tree.

 

Example 1:


Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
Example 2:

Input: preorder = [-1], inorder = [-1]
Output: [-1]
 

Constraints:

1 <= preorder.length <= 3000
inorder.length == preorder.length
-3000 <= preorder[i], inorder[i] <= 3000
preorder and inorder consist of unique values.
Each value of inorder also appears in preorder.
preorder is guaranteed to be the preorder traversal of the tree.
inorder is guaranteed to be the inorder traversal of the tree.*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* newNode(int val) {
    struct TreeNode* node = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Helper function
struct TreeNode* build(int preorder[], int preStart, int preEnd,
                       int inorder[], int inStart, int inEnd,
                       int* map) {
    if (preStart > preEnd || inStart > inEnd)
        return NULL;

    int rootVal = preorder[preStart];
    struct TreeNode* root = newNode(rootVal);

    int inIndex = map[rootVal + 3000]; // shift for negative values
    int leftSize = inIndex - inStart;

    root->left = build(preorder, preStart + 1, preStart + leftSize,
                       inorder, inStart, inIndex - 1, map);

    root->right = build(preorder, preStart + leftSize + 1, preEnd,
                        inorder, inIndex + 1, inEnd, map);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    // Map value → index in inorder
    int map[6001]; // range [-3000, 3000]
    for (int i = 0; i < inorderSize; i++) {
        map[inorder[i] + 3000] = i;
    }

    return build(preorder, 0, preorderSize - 1,
                 inorder, 0, inorderSize - 1,
                 map);
}