
#include <cstddef>
#include <stdexcept>
#include <utility>
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
	std::size_t m_count{0};

	void Clear()
	{
		Node* currNode{m_top};
		Node* nextNode{nullptr};

		while (currNode)
		{
			nextNode = currNode->next;
			delete currNode;
			currNode = nextNode;
		}
		m_top = nullptr;
		m_count = 0;
	}

public:
	Stack() = default;
	~Stack()
	{
		Clear();
	}

	Stack(const Stack&) = delete;
	Stack& operator=(const Stack&) = delete;

	bool IsEmpty() const
	{
		return m_count == 0;
	};

	std::size_t Size() const
	{
		return m_count;
	}
	T Top() const;
	void Push(T val);
	void Pop();
};

template <typename T>
T Stack<T>::Top() const
{
	if (IsEmpty())
		throw std::underflow_error("Invalid operation Top in an empty stack.");

	return m_top->data;
}

template <typename T>
void Stack<T>::Push(T val)
{
	Node* newNode{new Node(std::move(val))};
	newNode->next = m_top;
	m_top = newNode;
	m_count++;
}

template <typename T>
void Stack<T>::Pop()
{
	if (IsEmpty())
		throw std::underflow_error("Invalid operation: Pop is not defined on an empty stack.");

	Node* top{m_top};
	m_top = m_top->next;
	delete top;
	m_count--;
}