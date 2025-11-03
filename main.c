#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
    struct node *prev;
};

struct node *head = NULL, *temp;

// Create new node
struct node* create_node() {
    struct node* newnode = (struct node*)malloc(sizeof(struct node));
    printf("Enter data: ");
    scanf("%d", &newnode->data);
    newnode->next = newnode->prev = NULL;
    return newnode;
}

// Count nodes
int count() {
    int c = 0;
    temp = head;
    while (temp != NULL) {
        c++;
        temp = temp->next;
    }
    return c;
}

// Insert at beginning
void ins_beg() {
    struct node *newnode = create_node();
    if (head == NULL) {
        head = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("\nInserted at beginning\n");
}

// Insert at position
void ins_pos() {
    int pos;
    printf("\nEnter the position where the node should be inserted: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count() + 1) {
        printf("\nInvalid position!\n");
        return;
    }

    if (pos == 1) {
        ins_beg();
        return;
    }

    struct node *newnode = create_node();
    temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }
printf("\n%d is inserted successfully at position %d\n", newnode->data, pos);


    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
    printf("\n%d is inserted at position %d\n", newnode->data, pos);
}

// Display list
void display() {
    temp = head;
    printf("\nList: ");
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}
void ins_pos() {
    int pos;
    printf("\nEnter the position where the node should be inserted: ");
    scanf("%d", &pos);

    if (pos < 1 || pos > count() + 1) {
        printf("\nInvalid position!\n");
        return;
    }

    if (pos == 1) {
        ins_beg();
        return;
    }

    struct node *newnode = create_node();
    temp = head;
    for (int i = 1; i < pos - 1; i++) {
        temp = temp->next;
    }

    newnode->next = temp->next;
    newnode->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = newnode;
    }

    temp->next = newnode;
    printf("\n%d is inserted at position %d\n", newnode->data, pos);
}

// Main menu
int main() {
    int ch;
    while (1) {
        printf("\n1. Insert at beginning");
        printf("\n2. Insert at position");
        printf("\n3. Display");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1: ins_beg(); break;
            case 2: ins_pos(); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice!\n");
        }
    }
    return 0;
}
