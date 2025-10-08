#include <exception>
#include <vector>

class linked_list
{
private:
  struct Node
  {
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {};
    Node(int val) : data(val), next(nullptr) {};
  };

  Node *head;
  Node *tail;
  size_t list_size;

public:
  linked_list() : head(nullptr), tail(nullptr), list_size(0) {};

  linked_list(int val)
  {
    head = new Node();
    head->data = val;
    head->next = nullptr;
    list_size = 1;
    tail = head;
  }

  ~linked_list()
  {
    if (head)
    {
      while (head)
      {
        Node *temp = head;
        head = head->next;
        delete temp;
      }
    }
  }

  bool empty()
  {
    return head ? false : true;
  }

  void clear()
  {
    if (head)
    {
      Node *temp = nullptr;
      while (head)
      {
        temp = head;
        head = head->next;
        delete temp;
      }
    }
  }

  void push_front(int val)
  {
    Node *temp = new Node();
    temp->data = val;
    if (!head)
    {
      temp->next = nullptr;
      head = tail = temp;
    }
    else
    {
      temp->next = head;
      head = temp;
    }
  }

  void push_back(int val)
  {
    Node *temp = new Node();
    temp->data = val;
    temp->next = nullptr;
    if (!head)
    {
      head = tail = temp;
    }
    else
    {
      tail->next = temp;
      tail = temp;
    }
  }

  void insert_at(size_t idx, int val)
  {
    if (idx == 0)
    {
      push_front(val);
      return;
    }
    idx -= 1; // Zero based index.
    Node *temp = head;
    while (temp && idx)
    {
      temp = temp->next;
      idx--;
    }
    if (idx || !temp)
    {
      throw std::out_of_range("Index out of bounds.");
    }
    Node *new_node = new Node();
    if (temp == tail)
    {
      tail = new_node;
    }
    new_node->data = val;
    new_node->next = temp->next;
    temp->next = new_node;
  }

  int pop_front()
  {
    if (!head)
    {
      throw std::out_of_range("Out of bounds.");
    }
    if (head->next)
    {
      Node *temp = head;
      head = head->next;
      temp->next = nullptr;
      int ret = temp->data;
      delete temp;
      return ret;
    }
    else
    {
      int ret = head->data;
      delete head;
      head = tail = nullptr;
      return ret;
    }
  }
  int front()
  {
    if (!head)
    {
      throw std::out_of_range("Out of bounds.");
    }
    return head->data;
  }
  int back()
  {
    if (!tail)
    {
      throw std::out_of_range("Out of bounds.");
    }
    return tail->data;
  }

  int pop_back()
  {
    if (!tail)
    {
      throw std::out_of_range("Out of bounds.");
    }
    if (head == tail)
    {
      int ret = tail->data;
      delete tail;
      head = tail = nullptr;
      return ret;
    }
    Node *temp = head;
    while (temp->next->next)
    {
      temp = temp->next;
    }
    int ret = tail->data;
    temp->next = nullptr;
    delete tail;
    tail = temp;
    return ret;
  }

  Node* find(int target) const
  {
    if (!head)
    {
      return nullptr;
    }
    Node *temp = head;
    while (temp)
    {
      if (temp->data == target)
      {
        return temp;
      }
      temp = temp->next;
    }
    return nullptr;
  }

  bool contains()

  std::vector<int> to_vector()
  {
    if (!list_size)
    {
      return {};
    }
    std::vector<int> result;
    result.reserve(list_size);
    Node *temp = head;
    while (temp)
    {
      result.push_back(temp->data);
      temp = temp->next;
    }
    return result;
  }
};
