
#include <cstddef>
template <typename T>
class Deque
{
private:
	struct Node
	{
		T data{};
		Node* previous{nullptr};
		Node* next{nullptr};
		Node(T val) : data(val)
		{
		}
	};

	std::size_t m_count{0};
	Node* m_front{nullptr};
	Node* m_back{nullptr};

public:
	Deque() = default;
	bool IsEmpty() const
	{
		return m_count == 0;
	}
	T& front();
	T& back();

	void EnqueueFront(T val);
	void EnqueueBack(T val);
	void DequeueFront();
	void DequeueBack();
};