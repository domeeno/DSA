#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *right_child;
    struct Node *left_child;
};

struct Node* insert(int value, struct Node *root);
struct Node* newNode(int value);
void inorder(struct Node *root);
int searchNodeValue(int value, struct Node *root);
struct Node* searchNode(int value, struct Node *root);
struct Node* searchParentNode(int value, struct Node *root);
struct Node* deleteNode(struct Node* root, int key);

int main()
{
    struct Node *root = NULL;
    
    root = insert(10, root);
    
    insert(2, root);
    insert(18, root);
    insert(13, root);
    insert(4, root);
    insert(1, root);
    insert(3, root);
    insert(23, root);
    
    // inorder(root);
    
    struct Node *someNode = deleteNode(root, 2);
    printf("%d", someNode->data);
    
    
    return 0;
}

struct Node* insert(int value, struct Node *root) {
    if (root == NULL) {
        root = newNode(value);
    } else if (root->data < value) {
        root->right_child = insert(value, root->right_child);
    } else {
        root->left_child = insert(value, root->left_child);
    }
    return root;
}

struct Node* newNode(int value) {
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

int searchNodeValue(int value, struct Node *root) {
    if(&root->data == NULL) {
        return -1;
    } else if (value > root->data) {
        searchNode(value, root->right_child);
    } else if (value < root->data) {
        searchNode(value, root->left_child);
    } else if (value == root->data) {
        return value;
    }
}

struct Node* searchNode(int value, struct Node *root) {
    if(&root->data == NULL) {
        return root;
    } else if (value > root->data) {
        searchNode(value, root->right_child);
    } else if (value < root->data) {
        searchNode(value, root->left_child);
    } else if (value == root->data) {
        return root;
    }
}

struct Node* searchParentNode(int value, struct Node *root) {
    if (value == root->left_child->data || value == root->right_child->data) {
        return root;
    } else if (value > root->data) {
        searchParentNode(value, root->right_child);
    } else if (value < root->data) {
        searchParentNode(value, root->left_child);
    }
}

struct Node* deleteNode(struct Node* root, int key){
    struct Node *parentNode = searchParentNode(key, root);
    
    struct Node *nodeToBeDeleted = searchNode(key, parentNode);
    
    // TODO make the logic for deletion
    
    return nodeToBeDeleted;
}

void inorder(struct Node *root) {
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->left_child); 
        printf(" %d ", root->data); 
        inorder(root->right_child);
    }
}


