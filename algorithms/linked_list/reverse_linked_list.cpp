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

Node* reverseList(Node* head)
{
	if (!head)
	{
		return head;
	}
	Node* prevNode{nullptr};
	Node* currNode{head};
	Node* nextNode{nullptr};

	while (currNode)
	{
		nextNode = currNode->next;
		currNode->next = prevNode;
		prevNode = currNode;
		currNode = nextNode;
	}
	return prevNode;
}