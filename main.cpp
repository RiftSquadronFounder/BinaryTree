#include <iostream>
#include "BinaryTree.hpp"

int main() {
	try {
		BinaryTree<int>* var1 = new BinaryTree<int>(1);
		var1->NodeAssignAuto(new BinaryTree<int>(2));
		std::cout << *var1->GetValue() << std::endl;
		std::cout << "Left Node" << std::endl;
		std::cout << *var1->GetLeftNode()->GetValue() << std::endl;
	}
	catch (std::exception& ex){
		std::cout << ex.what();
	}

	





	return 0;
}