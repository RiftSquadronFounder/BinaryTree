#include "BinaryTree.hpp"





template <typename T>
BinaryTree<T>::BinaryTree() {
	_leftNode = nullptr;
	_rightNode = nullptr;
	_parentNode = nullptr;
	_value = nullptr;
}

template <typename T>
BinaryTree<T>::BinaryTree(T* value) {
	_leftNode = nullptr;
	_rightNode = nullptr;
	_parentNode = nullptr;
	_value = value;
}

template <typename T>
BinaryTree<T>::BinaryTree(T value) {
	_leftNode = nullptr;
	_rightNode = nullptr;
	_parentNode = nullptr;
	_value = new T();
	*_value = value;
}



template <typename T>
BinaryTree<T>::~BinaryTree() {
	delete _leftNode;
	delete _rightNode;
}








template <typename T>
void BinaryTree<T>::SortWholeTree() {
	BinaryTree<T>** NodeHolder = new BinaryTree<T>();

	if (_rightNode != nullptr) {
        _rightNode->SortWholeTree();
    }
    if (_leftNode != nullptr) {
        _leftNode->SortWholeTree();
    }
}

template <typename T>
int BinaryTree<T>::CountNodesInTreeBeneath(BinaryTree<T>* NodeToCountFrom) {
	if (NodeToCountFrom == nullptr) return 0;

	int counter = 0;
	if (NodeToCountFrom->GetLeftNode() != nullptr) {
		counter += 1 + CountNodesInTreeBeneath(NodeToCountFrom->GetLeftNode());
	}
	if (NodeToCountFrom->GetRightNode() != nullptr) {
		counter += 1 + CountNodesInTreeBeneath(NodeToCountFrom->GetRightNode());
	}
	return counter;
}

template <typename T>
int BinaryTree<T>::GetWeight() {
	int* counter = new int(0);
	if (_rightNode != nullptr) {
		counter++;
	}
	if (_leftNode != nullptr) {
		counter++;
	}
	return counter;
}


template <typename T>
void BinaryTree<T>::NodeAssignAuto(BinaryTree<T>* Node) {
	if (_leftNode == nullptr) {
		_leftNode = Node;
		Node->_parentNode = this;
	}
	else if (_rightNode == nullptr) {
		_rightNode = Node;
		Node->_parentNode = this;
	}
	else {
		if (Node->GetWeight() == 0 || Node->GetWeight() == 1) {
			_rightNode->NodeAssignAuto(Node);
		}
		else {
			_leftNode->NodeAssignAuto(Node);
		}
	}
}





template <typename T>
void BinaryTree<T>::LeftNodeAssign(BinaryTree<T>* Node) {
	*_leftNode = Node;
}

template <typename T>
void BinaryTree<T>::RightNodeAssign(BinaryTree<T>* Node) {
	*_rightNode = Node;
}

template <typename T>
void BinaryTree<T>::ParentNodeAssign(BinaryTree<T>* Node) {
	*_parentNode = Node;
}



template <typename T>
void BinaryTree<T>::LeftNodeDisconnect() {
	if (_leftNode != nullptr) {
		_leftNode->_parentNode = nullptr;
	}
	_leftNode = nullptr;
}

template <typename T>
void BinaryTree<T>::RightNodeDisconnect() {
	if (_rightNode != nullptr) {
		_rightNode->_parentNode = nullptr;
	}
	_rightNode = nullptr;
}

template <typename T>
void BinaryTree<T>::ParentNodeDisconnect() {
	_parentNode = nullptr;
}





template <typename T>
T* BinaryTree<T>::GetValue() {
	if (_value != nullptr) {
		return _value;
	}
}


template <typename T>
BinaryTree<T>* BinaryTree<T>::GetNodeWithValue(T* value) {
	if (_value != nullptr && *_value == *value) {
		return this;
	}

	BinaryTree<T>* found = nullptr;
	if (_leftNode != nullptr) {
		found = _leftNode->GetNodeWithValue(value);
		if (found != nullptr) return found;
	}
	if (_rightNode != nullptr) {
		found = _rightNode->GetNodeWithValue(value);
		if (found != nullptr) return found;
	}
	return nullptr;
}




template <typename T>
BinaryTree<T>* BinaryTree<T>::GetLeftNode() {
	return _leftNode;
}

template <typename T>
BinaryTree<T>* BinaryTree<T>::GetRightNode() {
	return _rightNode;

}

template <typename T>
BinaryTree<T>* BinaryTree<T>::GetParentNode() {
	return _parentNode;

}
