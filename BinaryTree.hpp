#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

template <typename T>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(T* value);
	BinaryTree(T value);
	~BinaryTree();
private:
	T* _value;
	BinaryTree* _leftNode;
	BinaryTree* _rightNode;
	BinaryTree* _parentNode;
};














#endif // !BINARY_TREE