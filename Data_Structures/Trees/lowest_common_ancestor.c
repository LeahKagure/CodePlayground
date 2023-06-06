// A program to find the lowest common ancestor (LCA) of two nodes in a binary tree

#include <stdio.h>
#include <stdlib.h>

struct TreeNode {
    int data;
    struct TreeNode* left;
    struct TreeNode* right;
};

struct TreeNode* findLCA(struct TreeNode* root, int val1, int val2) {
    if (root == NULL)
        return NULL;
    if (root->data == val1 || root->data == val2)
        return root;

    struct TreeNode* leftLCA = findLCA(root->left, val1, val2);
    struct TreeNode* rightLCA = findLCA(root->right, val1, val2);

    if (leftLCA != NULL && rightLCA != NULL)
        return root;
    if (leftLCA != NULL)
        return leftLCA;
    return rightLCA;
}

int main() {
    // Create the binary tree
    struct TreeNode* root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->data = 3;
    root->left = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->left->data = 5;
    root->left->left = NULL;
    root->left->right = NULL;
    root->right = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->right->data = 1;
    root->right->left = NULL;
    root->right->right = NULL;

    struct TreeNode* lca = findLCA(root, 5, 1);
    printf("Lowest Common Ancestor: %d\n", lca->data);
    printf("\n");

    // Clean up memory
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
