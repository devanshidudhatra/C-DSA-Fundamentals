#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Node {
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* createNode(int x) {
    struct Node *root = (struct Node*)malloc(sizeof(struct Node));
    root->data = x;
    root->left = NULL;
    root->right = NULL;
    return root;
}

void printTree(struct Node* root, int level) {
    if (root == NULL) {
        return;
    }

    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        printf("    ");
    }

    printf("%d\n", root->data);

    printTree(root->left, level + 1);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) return;

    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) return;

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) return;

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

struct Node* search(struct Node* root, int target) {
    if (root == NULL || root->data == target) return root;

    struct Node* leftResult = search(root->left, target);
    if (leftResult != NULL) return leftResult;

    return search(root->right, target);
}

int main() {
    struct Node* root = createNode(1);
    root->left = createNode(2);
    root->right = createNode(3);
    root->right->left = createNode(4);
    root->right->right = createNode(5);
    root->right->left->left = createNode(6);
    root->right->right->right = createNode(7);
    
    char choice;
    int value;

    while (1) {
        printf("\nEnter a choice: (P)reorder, (I)norder, (O)ostorder, (V)isualize, (S)earch, (Q)uit: ");
        scanf(" %c", &choice);

        if (choice == 'Q' || choice == 'q') {
            break;
        }

        if (choice == 'S' || choice == 's') {
            printf("Enter the value to search for: ");
            scanf("%d", &value);
            struct Node* result = search(root, value);
            if (result != NULL) {
                printf("Value %d found in the tree.\n");
            } else {
                printf("Value %d not found in the tree.\n");
            }
        } else if (choice == 'V' || choice == 'v') {
            printf("Tree visualization:\n");
            printTree(root, 0);
        } else {
            printf("Traversal: ");
            if (choice == 'P' || choice == 'p') {
                preorderTraversal(root);
            } else if (choice == 'I' || choice == 'i') {
                inorderTraversal(root);
            } else if (choice == 'O' || choice == 'o') {
                postorderTraversal(root);
            }
            printf("\n");
        }
    }

    return 0;
}
