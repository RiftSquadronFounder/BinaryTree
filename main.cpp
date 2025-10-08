#include <iostream>
#include "BinaryTree.hpp"

int main() {
	try {
		BinaryTree<int>* var1 = new BinaryTree<int>();
	}
	catch (std::exception& ex){
		std::cout << ex.what();
	}

	





	return 0;
}