#include "binary_search.hpp"

size_t bst::size(){
    return tree_size;
}

void bst::insert_node( int val ){
    if( !root ){
        root = new Node( val );
        tree_size++;
        return ;
    }
    Node* parent = nullptr;
    Node* current = root;

    while( current ){
        
        parent = current;

        if( val < current.data ){
            current = current->right;
        } else if( val > current.data ) {
            current = current->left;
        }else {
            return;
        }
    }
    if( value < parent.data ){
        parent->right = new Node( value );
    } else {
        parent->left = new Node( value );
    }
}
