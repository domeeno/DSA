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

int main()
{
    struct Node root = {10, NULL, NULL};
    
    insert(2, &root);
    insert(18, &root);
    insert(13, &root);
    insert(4, &root);
    insert(1, &root);
    
    inorder(&root);
    
    return 0;
}

struct Node* insert(int value, struct Node *root) {
    if (root == NULL) {
        root = newNode(value);
    } else if (root->data > value) {
        root->right_child = insert(value, root->right_child);
    } else {
        root->left_child = insert(value, root->left_child);
    }
    
    return root;
}

struct Node* newNode(int value)
{
    struct Node *new_node;
    new_node = malloc(sizeof(struct Node));
    new_node->data = value;
    new_node->left_child = NULL;
    new_node->right_child = NULL;

    return new_node;
}

void inorder(struct Node *root) {
    if(root!=NULL) // checking if the root is not null
    {
        inorder(root->right_child); 
        printf(" %d ", root->data); 
        inorder(root->left_child);
    }
}

