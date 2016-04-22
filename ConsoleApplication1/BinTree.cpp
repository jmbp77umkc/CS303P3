#include "BinTree.h"

CharBinTree::CharBinTree() {
    root = cursor = NULL;
}

CharBinTree::CharBinTree(int height) {
    root = cursor = NULL;
    initTreeHeight(height);
}

CharBinTree::CharBinTree(const CharBinTree& orig) {
    root = cursor = NULL;
    if (orig.root != NULL) {
        root = new CBTNode();
        copyTree(orig.root,root);
    }
}

CharBinTree::~CharBinTree() {
    wipeTree();
}

void CharBinTree::growTree(CBTNode* n, int h) {
    if (n == NULL || h <= 0) return;
    n->left = new CBTNode();
    n->right = new CBTNode();
    growTree(n->left, h-1);
    growTree(n->right,h-1);
}

void CharBinTree::copyTree(CBTNode* orig, CBTNode* copy) {
    if (orig == NULL || copy == NULL || 
            copy->left != NULL || copy->right != NULL) return; //expects new tree
    copy->data = orig->data;
    if (orig->left != NULL) {
        copy->left = new CBTNode();
        copyTree(orig->left,copy->left);
    }
    if (orig->right != NULL) {
        copy->right = new CBTNode();
        copyTree(orig->right,copy->right);
    }
}

void CharBinTree::delTree(CBTNode* n) {
    if (n == NULL) return;
    delTree(n->left);
    delTree(n->right);
    delete n;
}

void CharBinTree::initTreeHeight(int height) {
    if (root != NULL) wipeTree();
    if (height < 0) return; //invalid tree
    root = new CBTNode();
    growTree(root,height);
}

void CharBinTree::wipeTree() {
    if (root != NULL) {
        delTree(root);
        root = cursor = NULL;
    } 
}

CBTNode* CharBinTree::getRoot() {
    return root;
}

char CharBinTree::getRootData() {
    if (root == NULL) return 0;
    return root->data;
}

CBTNode* CharBinTree::getCursor() {
    return cursor;
}

char CharBinTree::getCursorData() {
    if (cursor == NULL) return 0;
    return cursor->data;
}

void CharBinTree::setCursor(CBTNode* c) {
    cursor = c;
}

void CharBinTree::setCursorToRoot() {
    cursor = root;
}

bool CharBinTree::goLeft() {
    if (cursor == NULL || cursor->left == NULL) return false;
    cursor = cursor->left;
    return true;
}

bool CharBinTree::goRight() {
    if (cursor == NULL || cursor->right == NULL) return false;
    cursor = cursor->right;
    return true;
}
