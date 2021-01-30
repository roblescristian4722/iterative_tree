#ifndef TREE_NODE_H
#define TREE_NODE_H
#include <iostream>

template <typename T>
struct TreeNode
{
    T* value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& value);
    ~TreeNode();
};
#endif // TREE_NODE_H

template<typename T>
TreeNode<T>::TreeNode(const T& value)
{
    this->value = new T(value);
}

template<typename T>
TreeNode<T>::~TreeNode()
{
    std::cout << "~Erasing: " << *value << "..." << std::endl;
    if (left) {
        delete left;
        left = nullptr;
    }
    if (right) {
        delete right;
        right = nullptr;
    }
    delete this->value;
    this->value = nullptr;
}
