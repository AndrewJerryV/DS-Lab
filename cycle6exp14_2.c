#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};
struct Node* queue[100]; 

struct Node* insertNode(struct Node* root, int data) {
    if (root == NULL) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;

    int front = 0, rear = 0;

    queue[rear++] = root; 

    while (front < rear) {
        struct Node* temp = queue[front++];

        if (temp->left == NULL) {
            temp->left = newNode;
            return root;
        } 
        else {
            queue[rear++] = temp->left; 
        }

        if (temp->right == NULL) {
            temp->right = newNode;
            return root;
        } 
        else {
            queue[rear++] = temp->right; 
        }
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

struct Node* findMin(struct Node* root) {
    while (root && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node* deleteNode(struct Node* root) {
    if (root == NULL) {
        return NULL;
    }

    int front = 0, rear = 0;
    struct Node* lastNode = NULL;
    struct Node* parent = NULL;

    queue[rear++] = root;

    while (front < rear) {
        struct Node* temp = queue[front++]; 
        lastNode = temp; 

        if (temp->left != NULL) {
            queue[rear++] = temp->left; 
            parent = temp; 
        }
        if (temp->right != NULL) {
            queue[rear++] = temp->right; 
            parent = temp; 
        }
    }

    if (lastNode == root) {
        free(root);
        return NULL;
    }

    if (parent->left == lastNode) {
        free(lastNode);
        parent->left = NULL;
    } else if (parent->right == lastNode) {
        free(lastNode);
        parent->right = NULL;
    }

    return root;
    
}

int main() {
    struct Node* root = NULL;
    int choice, value;
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
                        root = deleteNode(root);
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
