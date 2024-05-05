#ifndef SOURCE_H
#define SOURCE_H

typedef struct Node {
    int key;
    struct Node* left;
    struct Node* right;
    int height;
} Node;

int maxs(int a, int b);

int height(Node* node);

int balance(Node* node);

Node* newnode(int key);

Node* rightrotate(Node* y);

Node* leftrotate(Node* x);

Node* insert(Node* node, int key);

Node* minvalue(Node* node);

Node* deletenode(Node* root, int key);

void printAVL(Node* root, int level);

#endif
