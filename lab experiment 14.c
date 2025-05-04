#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int tree[MAX];


void insert(int value, int root) {
    if (tree[root] == -1) {
        tree[root] = value;
    } else if (value < tree[root]) {
        insert(value, 2 * root + 1);
    } else {
        insert(value, 2 * root + 2);
    }
}


void preorder(int root) {
    if (tree[root] != -1) {
        printf("%d ", tree[root]);
        preorder(2 * root + 1);
        preorder(2 * root + 2);
    }
}

void inorder(int root) {
    if (tree[root] != -1) {
        inorder(2 * root + 1);
        printf("%d ", tree[root]);
        inorder(2 * root + 2);
    }
}

void postorder(int root) {
    if (tree[root] != -1) {
        postorder(2 * root + 1);
        postorder(2 * root + 2);
        printf("%d ", tree[root]);
    }
}


int search(int i, int target) {
    if (i >= MAX || tree[i] == -1)
        return -1;
    else if (tree[i] == target)
        return i;
    else if (target < tree[i])
        return search(2 * i + 1, target);
    else
        return search(2 * i + 2, target);
}


int find_min(int i) {
    while (2 * i + 1 < MAX && tree[2 * i + 1] != -1)
        i = 2 * i + 1;
    return i;
}


void delete(int i, int value) {
    i = search(i, value);
    if (i == -1) {
        printf("Not found\n");
        return;
    }

    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if ((left >= MAX || tree[left] == -1) && (right >= MAX || tree[right] == -1)) {
        tree[i] = -1;
    } else if (tree[left] == -1) {
        int min = find_min(right);
        tree[i] = tree[min];
        delete(min, tree[min]);
    } else if (tree[right] == -1) {
        int min = find_min(left);
        tree[i] = tree[min];
        delete(min, tree[min]);
    } else {
        int min = find_min(right);
        tree[i] = tree[min];
        delete(min, tree[min]);
    }
}

int main() {
    int choice, m;
    for (int i = 0; i < MAX; i++) tree[i] = -1;

    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Delete\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &m);
                insert(m, 0);
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
                printf("Enter value: ");
                scanf("%d", &m);
                if (search(0, m) != -1)
                    printf("Found\n");
                else
                    printf("Not found\n");
                break;
            case 6:
                printf("Enter value: ");
                scanf("%d", &m);
                delete(0, m);
                break;
            case 7:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
