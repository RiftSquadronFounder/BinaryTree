#ifndef BINARY_TREE
#define BINARY_TREE


template <typename T>
class BinaryTree
{
public:
	
	BinaryTree() {
		_leftNode = nullptr;
		_rightNode = nullptr;
		_parentNode = nullptr;
		_value = nullptr;
	}

	
	BinaryTree(T* value) {
		_leftNode = nullptr;
		_rightNode = nullptr;
		_parentNode = nullptr;
		_value = value;
	}

	
	BinaryTree(T value) {
		_leftNode = nullptr;
		_rightNode = nullptr;
		_parentNode = nullptr;
		_value = new T();
		*_value = value;
	}



	
	~BinaryTree() {
		delete _leftNode;
		delete _rightNode;
	}








	
	void SortWholeTree() {
		BinaryTree<T>* NodeHolder = new BinaryTree<T>();

		if (_rightNode != nullptr) {
			_rightNode->SortWholeTree();
		}
		if (_leftNode != nullptr) {
			_leftNode->SortWholeTree();
		}
	}

	
	int CountNodesInTreeBeneath(BinaryTree<T>* NodeToCountFrom) {
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

	
	int GetWeight() {
		int* counter = new int(0);
		if (_rightNode != nullptr) {
			counter++;
		}
		if (_leftNode != nullptr) {
			counter++;
		}
		return counter;
	}


	
	void NodeAssignAuto(BinaryTree<T>* Node) {
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





	
	void LeftNodeAssign(BinaryTree<T>* Node) {
		*_leftNode = Node;
	}

	
	void RightNodeAssign(BinaryTree<T>* Node) {
		*_rightNode = Node;
	}

	
	void ParentNodeAssign(BinaryTree<T>* Node) {
		*_parentNode = Node;
	}



	
	void LeftNodeDisconnect() {
		if (_leftNode != nullptr) {
			_leftNode->_parentNode = nullptr;
		}
		_leftNode = nullptr;
	}

	
	void RightNodeDisconnect() {
		if (_rightNode != nullptr) {
			_rightNode->_parentNode = nullptr;
		}
		_rightNode = nullptr;
	}

	
	void ParentNodeDisconnect() {
		_parentNode = nullptr;
	}





	
	T* GetValue() {
		if (_value != nullptr) {
			return _value;
		}
	}


	
	BinaryTree<T>* GetNodeWithValue(T* value) {
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




	
	BinaryTree<T>* GetLeftNode() {
		return _leftNode;
	}

	
	BinaryTree<T>* GetRightNode() {
		return _rightNode;

	}

	
	BinaryTree<T>* GetParentNode() {
		return _parentNode;

	}






private:
	T* _value;
	BinaryTree* _leftNode;
	BinaryTree* _rightNode;
	BinaryTree* _parentNode;
};






#endif // !BINARY_TREE