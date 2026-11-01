struct Node
{
	int val{};
	Node* next{nullptr};
	Node() = default;
	Node(int x) : val(x)
	{
	}
	Node(int x, Node* next) : val(x), next(next)
	{
	}
};

Node* removeNthFromEnd(Node* head, int n)
{
	if (!head || n == 0)
	{
		return head;
	}

	Node dummy(0, head);
	Node* fast{&dummy};
	Node* slow{&dummy};

	for (int i{0}; i <= n && fast; ++i)
	{
		fast = fast->next;
	}

	while (fast)
	{
		fast = fast->next;
		slow = slow->next;
	}
	Node* target{slow->next};
	slow->next = slow->next->next;
	delete target;
	return dummy.next;
}