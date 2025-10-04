class linked_list {
  private:
    struct Node{
      int data;
      Node* next;
      Node( int val ): data(val), next(nullptr) {};
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
  
    void push_front( int val ){
      Node* temp = new Node();
      temp->data = val;
      if( !head ){
        temp->next = nullptr;
        head = tail = temp;
      } else {
        temp->next = head;
        head = temp;
      }
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
  
    void insert_at( size_t idx, int val ){
      if( idx == 0 ){
        push_front( val );
        return;
      }
      idx -= 1; // Zero based index.
      Node* temp = head;
      while( temp && idx ){
        temp = temp->next;
        idx--;
      }
      if( idx || !temp ){
        throw std::out_of_range("Index out of bounds.");
      }
      Node* new_node = new Node();
      if( temp == tail ){
        tail = new_node;
      }
      new_node->data = val;
      new_node->next = temp->next;
      temp->next = new_node;
    }
  
    int pop_front(){
      if( !head ){
        throw std::out_of_range("Out of bounds.");
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
        throw std::out_of_range("Out of bounds.");
      }
      return head->data;
    }
    int back(){
      if( !tail ){
        throw std::out_of_range("Out of bounds.");
      }
      return tail->data;
    }
  
    int pop_back(){
      if( !tail ){
        throw std::out_of_range("Out of bounds.");
      }
      if( head == tail ){
        int ret = tail->data;
        delete tail;
        head = tail = nullptr;
        return ret;
      }
      Node* temp = head;
      while( temp->next->next ){
        temp = temp->next;
      }
      int ret = tail->data;
      temp->next = nullptr;
      delete tail;
      tail = temp;
      return ret;
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

    std::vector<int> to_vector(){
      return result;
    }
};
