#include <stdio.h>
#include <stdlib.h>


struct TreeNode {
    int data;
    struct TreeNode *left, *right;
};


struct TreeNode* createNode(int value) {
    struct TreeNode *newNode = (struct TreeNode*) malloc(sizeof(struct TreeNode));
    newNode->data = value;
    newNode->left = newNode->right = NULL;
    return newNode;
}


struct TreeNode* insert(struct TreeNode* root, int value) {
    if (root == NULL) return createNode(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else
        root->right = insert(root->right, value);

    return root;
}


void preorder(struct TreeNode *root) {
    if (root == NULL) return;
    printf("%d ", root->data);
    preorder(root->left);
    preorder(root->right);
}


void inorder(struct TreeNode *root) {
    if (root == NULL) return;
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}


void postorder(struct TreeNode *root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    printf("%d ", root->data);
}
struct TreeNode* findMin(struct TreeNode* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

struct TreeNode* search(struct TreeNode* root, int value) {
    if (root == NULL || root->data == value)
        return root;
    else if (value < root->data)
        return search(root->left, value);
    else
        return search(root->right, value);
}

struct TreeNode* delete(struct TreeNode* root, int value) {
    if (root == NULL) return NULL;

    if (value < root->data)
        root->left = delete(root->left, value);
    else if (value > root->data)
        root->right = delete(root->right, value);
    else {
        if (root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if (root->left == NULL) {
            struct TreeNode *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL) {
            struct TreeNode *temp = root->left;
            free(root);
            return temp;
        } else {
            struct TreeNode *temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}
int main() {
    struct TreeNode *root = NULL;
    int choice, val;

    while (1) {
        printf("\n1. Insert\n2. Preorder\n3. Inorder\n4. Postorder\n5. Search\n6. Delete\n7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter element: ");
                scanf("%d", &val);
                root = insert(root, val);
                break;

            case 2:
                printf("Preorder: ");
                preorder(root);
                break;

            case 3:
                printf("Inorder: ");
                inorder(root);
                break;

            case 4:
                printf("Postorder: ");
                postorder(root);
                break;

            case 5:
                printf("Enter value to search: ");
                scanf("%d", &val);
                if (search(root, val) == NULL)
                    printf("Not Found\n");
                else
                    printf("Found\n");
                break;

            case 6:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                root = delete(root, val);
                break;

            case 7:
                exit(0);

            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}
