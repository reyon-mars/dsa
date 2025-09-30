class linked_list {
private:
  struct Node{
    int data;
    Node* next;
  };

  Node*  head;
  Node* tail;

public:

  linked_list(): head(nullptr), tail(nullptr) {};
  linked_list( int val ){
    head = new Node();
    head->data = val;
    head->next = nullptr;
    tail = head;
  }

  
};
