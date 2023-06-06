// A program to find the maximum depth of a binary tree

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

int max(int a, int b) {
    return (a > b) ? a : b;
}

int getMaxDepth(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftDepth = getMaxDepth(root->left);
    int rightDepth = getMaxDepth(root->right);
    return 1 + max(leftDepth, rightDepth);
}

int main() {
    // Create the binary tree
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = 1;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->data = 2;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->data = 3;
    root->right->left = NULL;
    root->right->right = NULL;

    int maxDepth = getMaxDepth(root);
    printf("Maximum depth of the binary tree: %d\n", maxDepth);
    printf("\n");

    // Clean up memory
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
