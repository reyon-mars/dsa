#include "linked_list.hpp"
#include <print>

int main()
{
	LinkedList<float> list{};

	list.InsertHead(43);
	list.InsertHead(76);
	list.InsertTail(15);
	list.InsertTail(44);

	list.Print();

	list.Insert(4, 100);
	list.Insert(3, 48);
	list.Insert(0, 22);

	list.Print();

	auto node = list.Get(2);

	node ? std::println("{}", node->data) : std::println("Index not found");

	auto found = list.Search(15);

	std::println("{}", found);

	list.Remove(0);
	list.Print();

	list.Remove(4);
	list.Print();

	list.RemoveHead();
	return 0;
}