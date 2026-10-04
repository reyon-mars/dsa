#include "linked_list.hpp"

int main()
{
	LinkedList<float> list{};

	list.InsertHead(43);
	list.InsertHead(76);
	list.InsertTail(15);

	list.Print();

	list.RemoveHead();
	return 0;
}