#include <exception>
#include <iostream>
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

  linked_list(const linked_list &list)
  {
    if (list.empty())
    {
      head = nullptr;
      tail = nullptr;
      list_size = 0;
    }
    else
    {
      Node *src = list.head;
      head = new Node(src->data);
      tail = head;
      list_size++;

      src = src->next;
      while (src)
      {
        tail->next = new Node(src->data);
        tail = tail->next;
        list_size++;
        src = src->next;
      }
    }
  }

  linked_list &operator=(const linked_list &list)
  {

    if (this == &list)
    {
      return *this;
    }
    Node *temp = head;
    while (head)
    {
      temp = head->next;
      delete head;
      head = temp;
    }

    head = tail = nullptr;
    list_size = 0;
    if (list.empty())
    {
      return *this;
    }
    list_size = list.list_size;
    temp = list.head;
    head = tail = new Node(temp->data);
    temp = temp->next;

    while (temp)
    {
      tail->next = new Node(temp->data);
      tail = tail->next;
      temp = temp->next;
    }
    return *this;
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

  bool empty() const
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
        list_size--;
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
      list_size++;
    }
    else
    {
      temp->next = head;
      head = temp;
      list_size++;
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
      list_size++;
    }
    else
    {
      tail->next = temp;
      tail = temp;
      list_size++;
    }
  }

  void insert_at(size_t idx, int val)
  {
    if (idx == 0)
    {
      push_front(val);
      list_size++;
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
    list_size++;
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
      list_size--;
      return ret;
    }
    else
    {
      int ret = head->data;
      delete head;
      head = tail = nullptr;
      list_size--;
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
      list_size--;
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
    list_size--;
    return ret;
  }

  Node *find(int target) const
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

  bool contains(int target)
  {
    if (!head)
    {
      return false;
    }
    Node *temp = head;
    while (temp)
    {
      if (temp->data == target)
      {
        return true;
      }
      temp = temp->next;
    }
    return false;
  }

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

  size_t size() const
  {
    return list_size;
  }

  int at(size_t index) const
  {
    if (index >= list_size)
    {
      throw std::out_of_range("Index out of bounds.");
    }

    Node *temp = head;
    while (index)
    {
      temp = temp->next;
      index--;
    }
    return temp->data;
  }
  
  void print() const{
    Node* temp = head;
    while( temp ){
      std::cout << '[' << temp->data << ']' << "->";
      temp = temp->next;
    }
    std::cout << 'X' << '\n';
  }

  Node* mid()
  {
    if( !head || !head->next ){
      return head;
    }
    Node* fast = head;
    Node* slow = head;

    while( fast && fast->next ){
      fast = fast->next->next;
      slow = slow->next;
    }
    return slow;
  }
};
