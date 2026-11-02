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

Node* addTwoNumbers(Node* l1, Node* l2)
{
	if (!l1 || !l2)
	{
		return l1 ? l1 : l2;
	}

	Node dummy(0, nullptr);
	Node* tail{&dummy};
	auto sum{0};
	auto carry{0};

	while (l1 && l2)
	{
		sum = (l1->val + l2->val + carry);
		tail->next = new Node((sum % 10), nullptr);
		carry = (sum / 10);
		l1 = l1->next;
		l2 = l2->next;
		tail = tail->next;
	}
	while (l1)
	{
		sum = (l1->val + carry);
		tail->next = new Node((sum % 10), nullptr);
		carry = (sum / 10);
		l1 = l1->next;
		tail = tail->next;
	}
	while (l2)
	{
		sum = (l2->val + carry);
		tail->next = new Node((sum % 10), nullptr);
		carry = (sum / 10);
		l2 = l2->next;
		tail = tail->next;
	}
	if (carry)
	{
		tail->next = new Node(carry, nullptr);
	}
	return dummy.next;
}