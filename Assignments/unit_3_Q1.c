/*A department maintains student roll numbers dynamically.
 Write a C program using a Singly Linked List to create the list, 
 insert at the beginning and end, search for a specified roll number,
 delete a specified roll number, and display the updated list after 
 each operation. Handle the case when a requested roll number 
 is not available.*/
 
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void displayList() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements: ");
    struct Node *temp = head;
    while (temp) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    newNode->next = head;
    head = newNode;
    displayList();
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
    } else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    displayList();
}

void insertAfter(int key, int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Value %d not found in the list to insert after\n", key);
        return;
    }
    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    temp->next = newNode;
    displayList();
}

void deleteValue(int value) {
    struct Node *temp = head, *prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found in the list\n", value);
        return;
    }

    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }

    free(temp);
    printf("Deleted %d from list\n", value);
    displayList();
}

void searchValue(int value) {
    struct Node *temp = head;
    int pos = 1;

    while (temp) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }

    printf("Value %d not found in the list\n", value);
}

int main() {
    printf("Insertion at Beginning:\n");
    insertAtBeginning(102);
    insertAtBeginning(101);

    printf("\nInsertion at End:\n");
    insertAtEnd(104);
    insertAtEnd(105);

    printf("\nInsertion After Key-(Insert 103 after 102):\n");
    insertAfter(102, 103);

    printf("\nSearch Operations:\n");
    searchValue(103);
    searchValue(999);

    printf("\nDelete Operations:\n");
    deleteValue(101); 
    deleteValue(103); 
    deleteValue(999);

    return 0;
}