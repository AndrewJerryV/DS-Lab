#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    if (data < root->data) {
        root->left = insertNode(root->left, data);
    } 
    else if (data > root->data) {
        root->right = insertNode(root->right, data);
    }
    return root;
}

void inorderTraversal(struct Node* root) {
    if (root == NULL) 
        return;
    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}

void preorderTraversal(struct Node* root) {
    if (root == NULL) 
        return;
    printf("%d ", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

void postorderTraversal(struct Node* root) {
    if (root == NULL) 
        return;
    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf("%d ", root->data);
}

struct Node* deleteNode(struct Node* root, int data) {
    if (root == NULL) 
        return root;

    if (data < root->data) {
        root->left = deleteNode(root->left, data);
    } 
    else if (data > root->data) {
        root->right = deleteNode(root->right, data);
    } 
    else {
        if (root->left == NULL) {
            struct Node* temp = root->right;
            free(root);
            return temp;
        } 
        else if (root->right == NULL) {
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = root->right;
        while (temp && temp->left != NULL) {
            temp = temp->left;
        }
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

int main() {
    struct Node* root = NULL;
    int choice, value;
    printf("Binary Tree Operations:\n");
    printf("1. Insert a node\n");
    printf("2. Delete a node\n");
    printf("3. Inorder traversal\n");
    printf("4. Preorder traversal\n");
    printf("5. Postorder traversal\n");
    printf("0. Exit");
    while (1) {
        
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the value to insert: ");
                scanf("%d", &value);
                root = insertNode(root, value);
                break;

            case 2: if (root == NULL) {
                        printf("Tree is empty!\n");
                    }
                    else{
                        printf("Enter the value to delete: ");
                        scanf("%d", &value);
                        root = deleteNode(root, value);
                    }
                    break;

            case 3: if (root == NULL) {
                        printf("Tree is empty!\n");
                    }
                    else{
                        printf("Inorder traversal: ");
                        inorderTraversal(root);
                    }
                    break;
            case 4: if (root == NULL) {
                        printf("Tree is empty!\n");
                    }
                    else{
                        printf("Preorder traversal: ");
                        preorderTraversal(root);
                    }
                    break;
            case 5: if (root == NULL) {
                        printf("Tree is empty!\n");
                    }
                    else{
                        printf("Postorder traversal: ");
                        postorderTraversal(root);
                    }
                    break;
            default:
                exit(0);
        }
    }
    return 0;
}
