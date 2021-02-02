#ifndef TREE_H
#define TREE_H
#include "tree_node.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include <stack>

template <typename T>
class Tree
{
private:
    TreeNode<T>* root;
    int height;

    // Recursive operations (node)
    void recursivePush(TreeNode<T>*& node, const T& value);
    void recursiveInOrder(TreeNode<T>*& node);
    void recursivePreOrder(TreeNode<T>*& node);
    void recursivePostOrder(TreeNode<T>*& node);
    void recursiveRemove(TreeNode<T>*& node, const T& value);
    bool recursiveExists(TreeNode<T>*& node, const T& value);
    TreeNode<T>*& recursiveGetNode(TreeNode<T>*&, const T& value);
    TreeNode<T>*& findLowestNode(TreeNode<T>*& node);
    TreeNode<T>*& findHighestNode(TreeNode<T>*& node);
    
    bool isLeaf(TreeNode<T>*& node);

public:
    Tree();
    ~Tree();

    void clear();
    bool empty();

    // Iterarive operations
    void push(const T& value);
    void remove(const T& value);
    bool exists(const T& value);
    void preOrder();
    void inOrder();
    void postOrder();


    // Recursive operations
    void recursivePush(const T& value);
    void recursiveInOrder();
    void recursivePreOrder();
    void recursivePostOrder();
    void recursiveRemove(const T& value);
    bool recursiveExists(const T& value);
    TreeNode<T>*& recursiveGetNode(const T& value);
};

#endif

template <typename T>
Tree<T>::Tree() : root(nullptr), height(0){}

template <typename T>
Tree<T>::~Tree()
{ delete this->root; }

template <typename T>
bool Tree<T>::empty()
{ return (this->root == nullptr); }

template <typename T>
void Tree<T>::clear()
{ delete this->root; }

template <typename T>
void Tree<T>::recursivePush(const T& value)
{ recursivePush(this->root, value); }

template <typename T>
void Tree<T>::recursivePush(TreeNode<T>*& node, const T& value)
{
    if (node == nullptr)
        node = new TreeNode<T>(value);
    else if (*node->value == value)
        std::cout << value << " has already been inserted" << std::endl;
    else if (value < *node->value)
        recursivePush(node->left, value);
    else
        recursivePush(node->right, value);
}

template <typename T>
void Tree<T>::recursiveInOrder()
{ recursiveInOrder(this->root); }

template <typename T>
void Tree<T>::recursiveInOrder(TreeNode<T> *& node)
{
    if (node != nullptr) {
        recursiveInOrder(node->left);
        std::cout << *node->value << " " << std::endl;
        recursiveInOrder(node->right);
    }
}

template <typename T>
void Tree<T>::recursivePreOrder()
{ recursivePreOrder(this->root); }

template <typename T>
void Tree<T>::recursivePreOrder(TreeNode<T> *& node)
{
    if (node != nullptr) {
        std::cout << *node->value << " " << std::endl;
        recursivePreOrder(node->left);
        recursivePreOrder(node->right);
    }
}

template <typename T>
void Tree<T>::recursivePostOrder()
{ recursivePostOrder(this->root); }

template <typename T>
void Tree<T>::recursivePostOrder(TreeNode<T> *& node)
{
    if (node != nullptr) {
        recursivePostOrder(node->left);
        recursivePostOrder(node->right);
        std::cout << *node->value << " " << std::endl;
    }
}

template <typename T>
void Tree<T>::recursiveRemove(const T& value)
{ 
    if (recursiveExists(value))
        recursiveRemove(recursiveGetNode(value), value);
    else
        std::cout << value << " doesn't exist" << std::endl;
}

template <typename T>
void Tree<T>::recursiveRemove(TreeNode<T> *& node, const T& value)
{
    if (node == nullptr)
        std::cout << "Value not found" << std::endl;
    else if (isLeaf(node)) {
        delete node;
        node = nullptr;
    }
    else {
        TreeNode<T>*& auxNode = node->left == nullptr ? findLowestNode(node->right) : findHighestNode(node->left);
        *node->value = *auxNode->value;
        delete auxNode;
        auxNode = nullptr;
    }
}

template<typename T>
TreeNode<T>*& Tree<T>::findLowestNode(TreeNode<T>*& node)
{
    if (node->left == nullptr)
        return node;
    return findLowestNode(node->left);
}

template<typename T>
TreeNode<T>*& Tree<T>::findHighestNode(TreeNode<T>*& node)
{
    if (node->right == nullptr)
        return node;
    return findHighestNode(node->right);
}

template<typename T>
bool Tree<T>::isLeaf(TreeNode<T>*& node)
{
    if (node->left == nullptr && node->right == nullptr)
        return true;
    return false;
}

template <typename T>
TreeNode<T>*& Tree<T>::recursiveGetNode(const T& value)
{ return recursiveGetNode(this->root, value); }

template <typename T>
TreeNode<T>*& Tree<T>::recursiveGetNode(TreeNode<T>*& node, const T& value)
{
    if (node != nullptr) {
        if (value < *node->value)
            return recursiveGetNode(node->left, value);
        else if (value > *node->value)
            return recursiveGetNode(node->right, value);
        else if (value == *node->value)
            return node;
    }
    throw std::range_error("Value not found");
}

template <typename T>
bool Tree<T>::recursiveExists(const T& value)
{ return recursiveExists(this->root, value); }

template <typename T>
bool Tree<T>::recursiveExists(TreeNode<T>*& node, const T& value)
{
    if (node != nullptr) {
        if (value < *node->value)
            return recursiveExists(node->left, value);
        else if (value > *node->value)
            return recursiveExists(node->right, value);
        else if (value == *node->value)
            return true;
    }
    return false;
}

template <typename T>
void Tree<T>::push(const T& value)
{
    TreeNode<T>** aux = &this->root;
    while (*aux != nullptr) {
        if (value < *(*aux)->value)
            aux = &(*aux)->left;
        else if (value > *(*aux)->value)
            aux = &(*aux)->right;
        else if (value == *(*aux)->value) {
            std::cout << "Value \"" << value << "\" has already been inserted" << std::endl;
            return;    
        }
    }
    (*aux) = new TreeNode<T>(value);
}

