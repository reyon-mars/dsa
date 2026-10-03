#include "linked_list.hpp"
#include <print>

int main()
{
	LinkedList<float> list{};

	list.InsertHead(43);
	list.InsertHead(76);
	list.InsertTail(15);

	list.Print();
	const float key{15};
	std::print("The List does {} have the element {} ", list.Search(key) ? "" : "not", key);

	list.RemoveHead();
	return 0;
}