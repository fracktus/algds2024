#include <gtest / gtest.h>
#include <gmock/gmock.h>
#include "Functions.h"

TEST(newnodeTest, PositiveKey) {
    Node* node = newnode(10);
    EXPECT_EQ(node->key, 10);
    EXPECT_EQ(node->left, nullptr);
    EXPECT_EQ(node->right, nullptr);
    EXPECT_EQ(node->height, 1);
    free(node);
}

TEST(insertTest, SingleInsertion) {
    Node* root = nullptr;
    root = insert(root, 10);
    EXPECT_EQ(root->key, 10);
    EXPECT_EQ(root->left, nullptr);
    EXPECT_EQ(root->right, nullptr);
    EXPECT_EQ(root->height, 1);
    free(root);
}

TEST(insertTest, MultipleInsertion) {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);
    printAVL(root, 0);
}

TEST(deletenodeTest, SingleDeletion) {
    Node* root = newnode(10);
    root = deletenode(root, 10);
    EXPECT_EQ(root, nullptr);
}

TEST(deletenodeTest, MultipleDeletion) {
    Node* root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 5);
    root = insert(root, 15);
    root = insert(root, 25);

    root = deletenode(root, 5);
    root = deletenode(root, 20);
    printAVL(root, 0);
}
