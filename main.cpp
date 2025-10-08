#include <iostream>
#include "BinaryTree.hpp"

int main() {
	try {
		BinaryTree<int>* var1 = new BinaryTree<int>(1);
		var1->NodeAssignAuto(new BinaryTree<int>(2));
		std::cout << *var1->GetValue() << std::endl;

		std::cout << "Left Node" << std::endl;
		std::cout << *var1->GetLeftNode()->GetValue() << std::endl;

		std::cout << "Let's try finding something" << std::endl;
		BinaryTree<int>* var2Find = new BinaryTree<int>(-1);
		var2Find = var1->GetNodeWithValue(new int(2));
		std::cout << *var2Find->GetValue() << std::endl;


		std::cout << "Now let's try finding something that does NOT exist, five, for example" << std::endl;

		var2Find = var1->GetNodeWithValue(new int(5));
		std::cout << *var2Find->GetValue() << std::endl;
		std::cout << "Welp. It didn't found anything as i can see from 'ere" << std::endl;
	}
	catch (std::exception& ex){
		std::cout << ex.what();
	}

	





	return 0;
}