

template <typename T>
class Stack
{
private:
	struct Node
	{
		T data{};
		Node* next{nullptr};
	};
	int m_count{0};

public:
	Stack();
	bool IsEmpty() const
	{
		return m_count == 0;
	};
	T Top();
	void Push(T val);
	void Pop();
};