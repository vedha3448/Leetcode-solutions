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

int preIndex = 0;

struct TreeNode* build(int* preorder, int* inorder,
                       int start, int end) {

    if (start > end)
        return NULL;

    struct TreeNode* root = malloc(sizeof(struct TreeNode));

    root->val = preorder[preIndex++];
    root->left = NULL;
    root->right = NULL;

    int i;
    for (i = start; i <= end; i++) {
        if (inorder[i] == root->val)
            break;
    }

    root->left = build(preorder, inorder, start, i - 1);
    root->right = build(preorder, inorder, i + 1, end);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize,
                           int* inorder, int inorderSize) {

    preIndex = 0;

    return build(preorder, inorder, 0, inorderSize - 1);
}
