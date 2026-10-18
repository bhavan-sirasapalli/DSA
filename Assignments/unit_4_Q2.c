#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *root = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

struct Node* insert(struct Node *root, int value) {
    if (root == NULL) {
        return createNode(value);
    }
    if (value < root->data) {
        root->left = insert(root->left, value);
    } 
    else if (value > root->data) {
        root->right = insert(root->right, value);
    } 
    else {
        printf("Duplicate value %d not allowed\n", value);
    }
    return root;
}

void inorder(struct Node *root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

struct Node* findLargestInLeftSubtree(struct Node *root) {
    struct Node *temp = root->left;
    while (temp != NULL && temp->right != NULL) {
        temp = temp->right;
    }
    return temp;
}

struct Node* deleteNode(struct Node *root, int value) {
    /* Value not found */
    if (root == NULL) {
        printf("Value %d not found in the tree.\n", value);
        return root;
    }

    if (value < root->data) {
        root->left = deleteNode(root->left, value);
    }
    else if (value > root->data) {
        root->right = deleteNode(root->right, value);
    }
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }
        else {
            struct Node *largest = findLargestInLeftSubtree(root);
            root->data = largest->data;
            root->left = deleteNode(root->left, largest->data);
        }
    }
    return root;
}

int main() {
    int keys[] = {50, 30, 70, 20, 40, 60, 80};
    int n = sizeof(keys) / sizeof(keys[0]);

    for (int i = 0; i < n; i++) {
        root = insert(root, keys[i]);
    }

    printf("Initial BST\n");
    printf("Inorder: ");
    inorder(root);
    printf("\n\n");

    printf("Test Case 1: Delete Leaf Node (0 children) [Key: 20]\n");
    printf("Before deletion: ");
    inorder(root);
    root = deleteNode(root, 20);
    printf("After deletion : ");
    inorder(root);
    printf("\n\n");

    printf("Test Case 2: Delete Node with 1 Child [Key: 30]\n");
    printf("Before deletion: ");
    inorder(root);
    root = deleteNode(root, 30);
    printf("After deletion : ");
    inorder(root);
    printf("\n\n");

    printf("Test Case 3: Delete Node with 2 Children [Key: 70]\n");
    printf("Before deletion: ");
    inorder(root);
    root = deleteNode(root, 70);
    printf("After deletion : ");
    inorder(root);
    printf("\n\n");

    return 0;
}