#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* root = NULL;

// Function prototypes
struct Node* Create(struct Node* root, int data);
void Preorder(struct Node* root);
void Inorder(struct Node* root);
void Postorder(struct Node* root);

int main() {
    int ch, data;
    while (1) {
        printf("\n1. Insert");
        printf("\n2. Inorder");
        printf("\n3. Preorder");
        printf("\n4. Postorder");
        printf("\n5. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &ch);
        switch (ch) {
            case 1:
                printf("\nEnter data to insert: ");
                scanf("%d", &data);
                root = Create(root, data);
                break;
            case 2:
                printf("\nInorder Traversal: ");
                Inorder(root);
                printf("\n");
                break;
            case 3:
                printf("\nPreorder Traversal: ");
                Preorder(root);
                printf("\n");
                break;
            case 4:
                printf("\nPostorder Traversal: ");
                Postorder(root);
                printf("\n");
                break;
            case 5:
                exit(0);
                break;
            default:
                printf("\nWrong choice");
        }
    }
    return 0;
}

// Function to create or insert a node into the BST
struct Node* Create(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = data;
        temp->left = NULL;
        temp->right = NULL;
        return temp;
    }

    if (data < root->data) {
        root->left = Create(root->left, data);
    } else if (data > root->data) {
        root->right = Create(root->right, data);
    } else {
        printf("\nDuplicate data not allowed in BST.");
    }
    return root;
}

// Preorder traversal (root -> left -> right)
void Preorder(struct Node* root) {
    if (root != NULL) {
        printf("%d ", root->data);
        Preorder(root->left);
        Preorder(root->right);
    }
}

// Inorder traversal (left -> root -> right)
void Inorder(struct Node* root) {
    if (root != NULL) {
        Inorder(root->left);
        printf("%d ", root->data);
        Inorder(root->right);
    }
}

// Postorder traversal (left -> right -> root)
void Postorder(struct Node* root) {
    if (root != NULL) {
        Postorder(root->left);
        Postorder(root->right);
        printf("%d ", root->data);
    }
}

