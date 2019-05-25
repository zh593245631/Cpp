#include"BSTree.hpp"

int main()
{
	BST<int> b;

	b.insert(6);
	//b.print();
	b.insert(1);
	//b.print();
	b.insert(2);
	//b.print();
	b.insert(5);
	//b.print();
	b.insert(3);
	//b.print();
	b.insert(4);
	b.print();

	b.Erase(2);
	b.print();
	b.Erase(3);
	b.print();
	b.Erase(6);
	b.print();
	b.Erase(1);
	b.print();




	

	return 0;
}