#include <stdio.h>
#define MAX 100

int tree[MAX], size = 0;

void insert(int ele) {
    if (size < MAX) {
        tree[size++] = ele;
    } else {
        printf("Tree is full\n");
    }
}

void preorder(int root) {
    if (root >= size || tree[root] == -1) return;
    printf("%d ", tree[root]);
    preorder(2 * root + 1);
    preorder(2 * root + 2);
}

void inorder(int root) {
    if (root >= size || tree[root] == -1) return;
    inorder(2 * root + 1);
    printf("%d ", tree[root]);
    inorder(2 * root + 2);
}

void postorder(int root) {
    if (root >= size || tree[root] == -1) return;
    postorder(2 * root + 1);
    postorder(2 * root + 2);
    printf("%d ", tree[root]);
}

int search(int ele) {
    for (int i = 0; i < size; i++) {
        if (tree[i] == ele) return i;
    }
    return -1;
}

void delete_ele(int ele) {
    int res = search(ele);
    if (res == -1) {
        printf("Not Found\n");
    } else {
        tree[res] = tree[size - 1];  // Replace with last element
        tree[size - 1] = -1;
        size--;
        printf("Deleted Successfully\n");
    }
}

void init() {
    for (int i = 0; i < MAX; i++) {
        tree[i] = -1;
    }
}

int main() {
    int choice, ele;
    init();

    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Delete\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &ele);
                insert(ele);
                break;
            case 2:
                printf("Preorder: ");
                preorder(0);
                break;
            case 3:
                printf("Inorder: ");
                inorder(0);
                break;
            case 4:
                printf("Postorder: ");
                postorder(0);
                break;
            case 5:
                printf("Enter element: ");
                scanf("%d", &ele);
                int res = search(ele);
                if (res == -1)
                    printf("Not Found\n");
                else
                    printf("Found at %d\n", res);
                break;
            case 6:
                printf("Enter element: ");
                scanf("%d", &ele);
                delete_ele(ele);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
