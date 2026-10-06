#include "doubly_linked_list.hpp"
#include <print>

int main()
{
	DoublyLinkedList<int> list{};
	list.InsertHead(43);
	list.InsertHead(76);
	list.InsertHead(15);
	list.InsertTail(44);

	std::println("The current list is: ");
	list.Print();

	list.Insert(4, 100);
	list.Insert(3, 48);
	list.Insert(0, 22);

	std::println("The list now is: ");
	list.Print();

    list

	return 0;
}