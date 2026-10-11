
template <typename T>
class Stack
{
private:
	struct Node
	{
		T data{};
		Node* next{nullptr};
	};
	Node* m_top{nullptr};
	int m_count{0};

public:
	Stack();
	bool IsEmpty() const
	{
		return m_count == 0;
	};
	T Top() const;
	void Push(T val);
	void Pop();
};

template <typename T>
T Stack<T>::Top() const
{
	return m_top->data;
}

template <typename T>
void Stack<T>::Pop()
{
    
}