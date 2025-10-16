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

public:
    bst(): root(nullptr), tree_size(0) {};

    bst( int val ){
        root = new Node( val );
        tree_size++;
    }

    ~bst(){
        clear( root );
    }
};