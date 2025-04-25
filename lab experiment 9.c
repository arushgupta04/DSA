// Circular Singly Linked List Implementation in C`
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} Node;

Node* head = NULL;

Node* CreateNode(int ele) {
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode->data = ele;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeg(int ele) {
    Node* newNode = CreateNode(ele);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        newNode->next = head;
        temp->next = newNode;
        head = newNode;
    }
    printf("Inserted at beginning.\n");
}

void insertAtEnd(int ele) {
    Node* newNode = CreateNode(ele);
    if (head == NULL) {
        head = newNode;
        head->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = head;
    }
    printf("Inserted at end.\n");
}

void insertAtpos(int ele, int pos) {
    if (pos == 1) {
        insertAtBeg(ele);
        return;
    }
    Node* newNode = CreateNode(ele);
    Node* temp = head;
    int i = 1;
    while (i < pos - 1 && temp->next != head) {
        temp = temp->next;
        i++;
    }
    if (i == pos - 1) {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Inserted at position %d.\n", pos);
    } else {
        printf("Invalid position!\n");
        free(newNode);
    }
}

void deleteFrombeg() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("Deleted from beginning.\n");
    } else {
        Node* temp = head;
        Node* last = head;
        while (last->next != head) {
            last = last->next;
        }
        head = head->next;
        last->next = head;
        free(temp);
        printf("Deleted from beginning.\n");
    }
}

void deleteFromEnd() {
    if (head == NULL) {
        printf("List is empty!\n");
    } else if (head->next == head) {
        free(head);
        head = NULL;
        printf("Deleted from End.\n");
    } else {
        Node* temp = head;
        Node* prev = NULL;
        while (temp->next != head) {
            prev = temp;
            temp = temp->next;
        }
        prev->next = head;
        free(temp);
        printf("Deleted from end.\n");
    }
}

void deleteAtanypos(int pos) {
    if (head == NULL) {
        printf("List is empty!\n");
    } else if (pos == 1) {
        deleteFrombeg();
    } else {
        Node* temp = head;
        int i = 1;
        while (i < pos - 1 && temp->next != head) {
            temp = temp->next;
            i++;
        }
        if (temp->next != head && i == pos - 1) {
            Node* del = temp->next;
            temp->next = del->next;
            free(del);
            printf("Deleted from position %d.\n", pos);
        } else {
            printf("Invalid position!\n");
        }
    }
}

void search(int ele) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    Node *temp = head;
    int pos = 1;
    do {
        if (temp->data == ele) {
            printf("Element %d found at position %d.\n", ele, pos);
            return;
        }
        temp = temp->next;
        pos++;
    } while (temp != head);
    printf("Element not found!\n");
}

void display() {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    Node* temp = head;
    printf("List elements: ");
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

int main() {
    int value, pos, choice;
    printf("\n---------Circular Linked List---------\n");
    printf("1. Insert at beginning\n2. Insert at end\n3. Insert at any position\n4. Delete from beginning\n5. Delete from end\n6. Delete at any position\n7. Search\n8. Display\n9. Exit\n");  
    while (1) {
        
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtBeg(value);
                break;
            case 2:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertAtEnd(value);
                break;
            case 3:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter position to insert: ");
                scanf("%d", &pos);
                insertAtpos(value, pos);
                break;
            case 4:
                deleteFrombeg();
                break;
            case 5:
                deleteFromEnd();
                break;
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &pos);
                deleteAtanypos(pos);
                break;
            case 7:
                printf("Enter value to search: ");
                scanf("%d", &value);
                search(value);
                break;
            case 8:
                display();
                break;
            case 9:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}
