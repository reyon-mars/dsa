#pragma once
#include <stack>
#include <queue>
#include <functional>

class bst
{
private:
    struct Node
    {
        int data;
        Node *left;
        Node *right;
        explicit Node(int val) : data(val), left(nullptr), right(nullptr){};
    };

    Node *root;
    size_t tree_size;

    void insert_node( int val );
    void clear();

public:
    
    bst();
    bst( int val );

    ~bst();
};