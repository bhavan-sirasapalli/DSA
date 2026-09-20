/*Develop a C program for a Doubly Linked List representing a sequence 
of web pages visited by a user. The program should insert a new page, 
move forward and backward, delete a specified page, and display the 
pages from first-to-last and last-to-first while handling beginning 
and end conditions correctly.*/

#include <stdio.h>
#include <stdlib.h>

void displayList(void);
void displayReverse(void);

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node *head = NULL;
struct Node *current = NULL; 

struct Node* createNode(int value) {
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        current = head;
    } 
    else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    printf("Inserted %d at beginning.\n", value);
}

void insertAtEnd(int value) {
    struct Node *newNode = createNode(value);
    if (head == NULL) {
        head = newNode;
        current = head;
    } 
    else {
        struct Node *temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
        current = newNode;
    }
    printf("Inserted %d at end.\n", value);
}

void insertAfter(int key, int value) {
    struct Node *temp = head;
    while (temp != NULL && temp->data != key) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key %d not found\n", key);
        return;
    }
    struct Node *newNode = createNode(value);
    newNode->next = temp->next;
    newNode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Inserted %d after %d.\n", value, key);
}

void moveBackward(void) {
    if (current == NULL) {
        printf("History is empty.\n");
        return;
    }
    if (current->prev == NULL) {
        printf("Already at first page (%d). \n", current->data);
        return;
    }
    current = current->prev;
    printf("Moved Backward to page: %d\n", current->data);
}

void moveForward(void) {
    if (current == NULL) {
        printf("History is empty.\n");
        return;
    }
    if (current->next == NULL) {
        printf("Already at last page (%d).\n", current->data);
        return;
    }
    current = current->next;
    printf("Moved Forward to page: %d\n", current->data);
}

void deleteValue(int value) {
    struct Node *temp = head;

    while (temp != NULL && temp->data != value) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Value %d not found\n", value);
        return;
    }

    if (temp == current) {
        if (current->next != NULL)
            current = current->next;
        else
            current = current->prev;
    }

    if (temp->prev == NULL) {
        head = temp->next;
        if (head != NULL) {
            head->prev = NULL;
        }
    } 
    else { 
        temp->prev->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);
    printf("Deleted :%d\n", value);
}

void searchValue(int value) {
    struct Node *temp = head;
    int pos = 1;

    while (temp != NULL) {
        if (temp->data == value) {
            printf("Value %d found at position %d\n", value, pos);
            return;
        }
        temp = temp->next;
        pos++;
    }
    printf("Value %d not found.\n", value);
}

void displayList(void) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    printf("List elements (Forward): ");
    while (temp != NULL) {
        if (temp == current) {
            printf("[%d]* <-> ", temp->data); 
        } 
        else {
            printf("%d <-> ", temp->data);
        }
        temp = temp->next;
    }
    printf("NULL\n");
}

void displayReverse(void) {
    struct Node *temp = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    while (temp->next != NULL) {
        temp = temp->next;
    }

    printf("Reverse list (Backward): ");
    while (temp != NULL) {
        if (temp == current) {
            printf("[%d]* <-> ", temp->data);
        } 
        else {
            printf("%d <-> ", temp->data);
        }
        temp = temp->prev;
    }
    printf("NULL\n");
}

int main() {
    int choice, value, key;

    while (1) {
        printf("\nWeb Page History (Doubly Linked List)\n");
        printf("1. Visit Page (Insert at End)\n");
        printf("2. Insert at Beginning\n");
        printf("3. Insert After Page ID\n");
        printf("4. Move Backward\n");
        printf("5. Move Forward\n");
        printf("6. Delete Page\n");
        printf("7. Search Page\n");
        printf("8. Display First-to-Last\n");
        printf("9. Display Last-to-First\n");
        printf("10. Exit\n");
        printf("Enter your choice: ");
        if (scanf("%d", &choice) != 1) {
            break;
        }

        switch (choice) {
            case 1:
                printf("Enter page ID: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 2:
                printf("Enter page ID: ");
                scanf("%d", &value);
                insertAtBeginning(value);
                break;
            case 3:
                printf("Enter key page ID and new page ID: ");
                scanf("%d %d", &key, &value);
                insertAfter(key, value);
                break;
            case 4:
                moveBackward();
                break;
            case 5:
                moveForward();
                break;
            case 6:
                printf("Enter page ID to delete: ");
                scanf("%d", &value);
                deleteValue(value);
                break;
            case 7:
                printf("Enter page ID to search: ");
                scanf("%d", &value);
                searchValue(value);
                break;
            case 8:
                displayList();
                break;
            case 9:
                displayReverse();
                break;
            case 10:
                printf("Exiting program.\n");
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
