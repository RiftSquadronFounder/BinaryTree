#include "BinaryTree.hpp"





template <typename T>
BinaryTree<T>::BinaryTree() {
	_leftNode = nullptr;
	_rightNode = nullptr;
	_parentNode = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(T* value) {
	_leftNode = nullptr;
	_rightNode = nullptr;
	_parentNode = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(T value) {
	_leftNode = nullptr;
	_rightNode = nullptr;
	_parentNode = nullptr;
}



template <typename T>
BinaryTree<T>::~BinaryTree() {
	delete _leftNode;
	delete _rightNode;
}


