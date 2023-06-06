// A program to find the diameter of a binary tree (the longest path between any two nodes)

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

int getHeight(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    return 1 + max(leftHeight, rightHeight);
}

int getDiameter(struct TreeNode* root) {
    if (root == NULL)
        return 0;
    int leftHeight = getHeight(root->left);
    int rightHeight = getHeight(root->right);
    int leftDiameter = getDiameter(root->left);
    int rightDiameter = getDiameter(root->right);
    return max(leftHeight + rightHeight + 1, max(leftDiameter, rightDiameter));
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

    int diameter = getDiameter(root);
    printf("Diameter of the binary tree: %d\n", diameter);
    printf("\n");

    // Clean up memory
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}
