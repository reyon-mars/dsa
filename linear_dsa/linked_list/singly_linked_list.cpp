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

  bool empty(){
    return head ? false : true;
  }

  void push_back( int val ){
    Node* temp = new Node();
    temp->data = val;
    temp->next = nullptr;
    if( !head ){
      head = tail = temp;
    } else{
      tail->next = temp;
      tail = temp;
    }
  }

  void push_front( int val ){
    Node* temp = new Node();
    temp->data = val;
    if( !head ){
      temp->next = nullptr;
      head = tail = temp;
    } else {
      
    }
  }

  int pop_front(){
    if( !head ){
      return NaN;
    }
    if( head->next ){
      Node* temp = head;
      head = head->next;
      temp->next = nullptr;
      int ret = temp->data;
      delete temp;
      return ret;
    }else{
      int ret = head->data;
      delete head;
      head = tail = nullptr;
      return ret;
    }
  }

  int front(){
    if( !head ){
      return -1;
    }
    return head->data;
  }
  int back(){
    if( !tail ){
      return -1;
    }
    return tail->data;
  }

  int pop_back(){
  }

  bool find( int target )const{
    if( !head ){
      return false;
    }
    Node* temp = head;
    while( temp ){
      if( temp->data == target ){
        return true;
      }
      temp = temp->next;
    }
    return false;
  }
};
