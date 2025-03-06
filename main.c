#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PATHS 100
#define MAX_LENGTH 100

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} TreeNode;

TreeNode* newNode(int val) {
    TreeNode* node = (TreeNode*)malloc(sizeof(TreeNode));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

void findPaths(TreeNode* root, char paths[MAX_PATHS][MAX_LENGTH], int* pathCount, char* currentPath) {
    if (root == NULL) return;

    char newPath[MAX_LENGTH];
    if (strlen(currentPath) == 0) {
        sprintf(newPath, "%d", root->val);
    } else {
        sprintf(newPath, "%s->%d", currentPath, root->val);
    }

    if (root->left == NULL && root->right == NULL) {
        strcpy(paths[*pathCount], newPath);
        (*pathCount)++;
    } else {
        findPaths(root->left, paths, pathCount, newPath);
        findPaths(root->right, paths, pathCount, newPath);
    }
}

void binaryTreePaths(TreeNode* root) {
    char paths[MAX_PATHS][MAX_LENGTH];
    int pathCount = 0;

    findPaths(root, paths, &pathCount, "");
    printf("[");
    for (int i = 0; i < pathCount; i++) {
        printf("\"%s\"", paths[i]);
        if (i < pathCount - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    TreeNode* root = newNode(1);
    root->left = newNode(2);
    root->right = newNode(3);
    root->left->right = newNode(5);

    printf("Output para a árvore 1: ");
    binaryTreePaths(root);
    TreeNode* root2 = newNode(1);
    printf("Output para a árvore 2: ");
    binaryTreePaths(root2);
    
    return 0;
}
