/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

#include <stdlib.h>

int postIndex;

struct TreeNode* build(int* inorder, int* postorder,
                       int start, int end) {

    if (start > end)
        return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val = postorder[postIndex--];
    root->left = NULL;
    root->right = NULL;

    int i;

    for (i = start; i <= end; i++) {
        if (inorder[i] == root->val)
            break;
    }

    // Build right subtree first
    root->right = build(inorder, postorder, i + 1, end);

    // Then build left subtree
    root->left = build(inorder, postorder, start, i - 1);

    return root;
}

struct TreeNode* buildTree(int* inorder, int inorderSize,
                           int* postorder, int postorderSize) {

    postIndex = postorderSize - 1;

    return build(inorder, postorder, 0, inorderSize - 1);
}
