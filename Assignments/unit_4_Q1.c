#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

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
        printf("Duplicate ID %d not allowed.\n", value);
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

void preorder(struct Node *root) {
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

void postorder(struct Node *root) {
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

struct Node* search(struct Node *root, int value) {
    if (root == NULL || root->data == value) {
        return root;
    }
    if (value < root->data) {
        return search(root->left, value);
    }
    return search(root->right, value);
}

int main() {
    struct Node *root = NULL;
    int n, value, target;

    printf("Enter number of identification numbers (n): ");
    scanf("%d", &n);

    printf("Enter %d unique IDs:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        root = insert(root, value);
    }

    printf("\nTraversals: \n");
    printf("Inorder   (LPR): ");
    inorder(root);
    printf("\n");

    printf("Preorder  (PLR): ");
    preorder(root);
    printf("\n");

    printf("Postorder (LRP): ");
    postorder(root);
    printf("\n");

    printf("\nEnter ID to search: ");
    scanf("%d", &target);

    if (search(root, target) != NULL) {
        printf("Result: ID %d exists in the system.\n", target);
    } else {
        printf("Result: ID %d does NOT exist in the system.\n", target);
    }

    return 0;
}