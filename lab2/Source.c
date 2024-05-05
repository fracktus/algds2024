#include <stdio.h>
#include <stdlib.h>
#include "Functions.h"

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int maxs(int a, int b) {
    return (a > b) ? a : b;
}

int height(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return node->height;
}

int balance(Node* node) {
    if (node == NULL) {
        return 0;
    }
    return height(node->left) - height(node->right);
}

Node* newnode(int key) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return node;
}

Node* rightrotate(Node* y) {
    Node* x = y->left;
    Node* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = maxs(height(y->left), height(y->right)) + 1;
    x->height = maxs(height(x->left), height(x->right)) + 1;

    return x;
}

Node* leftrotate(Node* x) {
    Node* y = x->right;
    Node* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = maxs(height(x->left), height(x->right)) + 1;
    y->height = maxs(height(y->left), height(y->right)) + 1;

    return y;
}

Node* insert(Node* node, int key) {
    if (node == NULL) {
        return newnode(key);
    }

    if (key < node->key) {
        node->left = insert(node->left, key);
    }
    else if (key > node->key) {
        node->right = insert(node->right, key);
    }
    else {
        return node;
    }

    node->height = 1 + maxs(height(node->left), height(node->right));

    int balance0 = balance(node);

    if (balance0 > 1 && key < node->left->key) {
        return rightrotate(node);
    }

    if (balance0 < -1 && key > node->right->key) {
        return leftrotate(node);
    }

    if (balance0 > 1 && key > node->left->key) {
        node->left = leftrotate(node->left);
        return rightrotate(node);
    }

    if (balance0 < -1 && key < node->right->key) {
        node->right = rightrotate(node->right);
        return leftrotate(node);
    }

    return node;
}

Node* minvalue(Node* node) {
    Node* current = node;

    while (current->left != NULL) {
        current = current->left;
    }

    return current;
}

Node* deletenode(Node* root, int key) {
    if (root == NULL) {
        return root;
    }

    if (key < root->key) {
        root->left = deletenode(root->left, key);
    }
    else if (key > root->key) {
        root->right = deletenode(root->right, key);
    }
    else {
        if (root->left == NULL || root->right == NULL) {
            Node* temp = root->left ? root->left : root->right;

            if (temp == NULL) {
                temp = root;
                root = NULL;
            }
            else {
                *root = *temp;
            }

            free(temp);
        }
        else {
            Node* temp = minvalue(root->right);

            root->key = temp->key;

            root->right = deletenode(root->right, temp->key);
        }
    }

    if (root == NULL) {
        return root;
    }

    root->height = 1 + maxs(height(root->left), height(root->right));

    int balance0 = balance(root);

    if (balance0 > 1 && balance(root->left) >= 0) {
        return rightrotate(root);
    }

    if (balance0 > 1 && balance(root->left) < 0) {
        root->left = leftrotate(root->left);
        return rightrotate(root);
    }

    if (balance0 < -1 && balance(root->right) <= 0) {
        return leftrotate(root);
    }

    if (balance < -1 && balance(root->right) > 0) {
        root->right = rightrotate(root->right);
        return leftrotate(root);
    }

    return root;
}

void printAVL(Node* root, int level) {
    if (root == NULL)
        return;
    printAVL(root->right, level + 1);

    for (int i = 0; i < level; i++) printf("   ");
    printf("%d\n", root->key);
    printAVL(root->left, level + 1);
}

