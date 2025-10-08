#ifndef BINARY_TREE
#define BINARY_TREE

#include <iostream>

template <typename T>
class BinaryTree
{
public:
	BinaryTree();
	BinaryTree(T* value);
	~BinaryTree();


	void NodeAssignAuto(BinaryTree<T>* Node);
	void SortWholeTree();

	int CountNodesInTreeBeneath(BinaryTree<T>* NodeToCountFrom);
	int GetWeight();

	void LeftNodeAssign(BinaryTree<T> *Node);
	void RightNodeAssign(BinaryTree<T> *Node);
	void ParentNodeAssign(BinaryTree<T> *Node);

	void LeftNodeDisconnect();
	void RightNodeDisconnect();
	void ParentNodeDisconnect();

	BinaryTree<T>* GetLeftNode();
	BinaryTree<T>* GetRightNode();
	BinaryTree<T>* GetParentNode();

	T* GetValue();

	BinaryTree<T>* GetNodeWithValue(T* value);






private:
	T** _value;
	BinaryTree** _leftNode;
	BinaryTree** _rightNode;
	BinaryTree** _parentNode;
};














#endif // !BINARY_TREE