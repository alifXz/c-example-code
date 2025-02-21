#include <stdio.h>
#include <stdlib.h>

struct tnode {
    int x;
    struct tnode *next;
    struct tnode *prev;
} *head, *tail;

// Function to push a new node at the front
void push_front(int value) {
    struct tnode *node = (struct tnode *)malloc(sizeof(struct tnode));
    node->x = value;

    if (head == NULL) {
        head = tail = node;
        node->next = NULL;
        node->prev = NULL;
    } else {
        node->next = head;
        node->prev = NULL;
        head->prev = node;
        head = node;
    }
}

// Function to push a new node at the back
void push_back(int value) {
    struct tnode *node = (struct tnode *)malloc(sizeof(struct tnode));
    node->x = value;

    if (head == NULL) {
        head = tail = node;
        node->next = NULL;
        node->prev = NULL;
    } else {
        tail->next = node;
        node->prev = tail;
        node->next = NULL;
        tail = node;
    }
}

// Function to push a new node after a specific value
void push_mid(int value, int searchKey) {
    struct tnode *node = (struct tnode *)malloc(sizeof(struct tnode));
    node->x = value;

    if (head == NULL) {
        head = tail = node;
        node->next = NULL;
        node->prev = NULL;
        return;
    }

    struct tnode *curr = head;
    while (curr != NULL) {
        if (curr->x == searchKey) {
            if (curr == tail) {
                push_back(value);
            } else {
                node->next = curr->next;
                node->prev = curr;
                curr->next->prev = node;
                curr->next = node;
            }
            return;
        }
        curr = curr->next;
    }

    printf("Data %d not found\n", searchKey);
    free(node);
}

// Function to delete the first node
void delete_front() {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct tnode *temp = head;
    head = head->next;

    if (head != NULL) {
        head->prev = NULL;
    } else {
        tail = NULL;
    }

    free(temp);
}

// Function to delete the last node
void delete_back() {
    if (tail == NULL) {
        printf("List is empty\n");
        return;
    }

    struct tnode *temp = tail;
    tail = tail->prev;

    if (tail != NULL) {
        tail->next = NULL;
    } else {
        head = NULL;
    }

    free(temp);
}

// Function to delete a node by value
void delete_mid(int value) {
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    struct tnode *curr = head;

    while (curr != NULL) {
        if (curr->x == value) {
            if (curr == head) {
                delete_front();
            } else if (curr == tail) {
                delete_back();
            } else {
                curr->prev->next = curr->next;
                curr->next->prev = curr->prev;
                free(curr);
            }
            return;
        }
        curr = curr->next;
    }

    printf("Data %d not found\n", value);
}

// Function to clear the entire list
void clearData() {
    while (head != NULL) {
        struct tnode *temp = head;
        head = head->next;
        free(temp);
    }
    tail = NULL;
}

// Function to print the list
void printList() {
    if (head == NULL) {
        printf("There is no data\n");
        return;
    }

    struct tnode *curr = head;
    while (curr != NULL) {
        printf("%d ", curr->x);
        curr = curr->next;
    }
    printf("\n");
}

// Main function to test the linked list
int main() {
    printf("PUSH DATA\n");

    push_front(11);
    push_back(90);
    push_front(78);
    push_back(50);
    // List: 78 11 90 50

    push_mid(22, 90);
    push_mid(18, 78);
    // List: 78 18 11 90 22 50

    printf("List after insertions: ");
    printList();

    delete_front();
    printf("List after delete_front: ");
    printList();

    delete_back();
    printf("List after delete_back: ");
    printList();

    delete_mid(90);
    printf("List after delete_mid(90): ");
    printList();

    clearData();
    printf("List after clearing: ");
    printList();

    return 0;
}
