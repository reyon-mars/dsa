#include "binary_search.hpp"

bst::~bst() {
    destroy(root);
}

void bst::destroy(Node* node) {
    if (!node) return;
    destroy(node->left);
    destroy(node->right);
    delete node;
}

size_t bst::size() const {
    return tree_size;
}

bool bst::empty() const {
    return tree_size == 0;
}

void bst::insert_node(int val) {
    if (!root) {
        root = new Node(val);
        ++tree_size;
        return;
    }

    Node* parent  = nullptr;
    Node* current = root;

    while (current) {
        parent = current;
        if (val < current->data) {
            current = current->left;
        } else if (val > current->data) {
            current = current->right;
        } else {
            return;
        }
    }

    if (val < parent->data) {
        parent->left  = new Node(val);
    } else {
        parent->right = new Node(val);
    }
    ++tree_size;
}

bool bst::search(int val) const {
    const Node* current = root;
    while (current) {
        if (val < current->data) {
            current = current->left;
        } else if (val > current->data) {
            current = current->right;
        } else {
            return true;
        }
    }
    return false;
}

bst::Node* bst::min_node(Node* node) const {
    while (node->left) {
        node = node->left;
    }
    return node;
}

bst::Node* bst::remove(Node* node, int val, bool& removed) {
    if (!node) return nullptr;

    if (val < node->data) {
        node->left  = remove(node->left,  val, removed);
    } else if (val > node->data) {
        node->right = remove(node->right, val, removed);
    } else {
        removed = true;
        if (!node->left) {
            Node* right_child = node->right;
            delete node;
            return right_child;
        }
        if (!node->right) {
            Node* left_child = node->left;
            delete node;
            return left_child;
        }
        Node* successor  = min_node(node->right);
        node->data       = successor->data;
        bool dummy       = false;
        node->right      = remove(node->right, successor->data, dummy);
    }
    return node;
}

void bst::delete_node(int val) {
    bool removed = false;
    root = remove(root, val, removed);
    if (removed) --tree_size;
}

std::optional<int> bst::min() const {
    if (!root) return std::nullopt;
    return min_node(root)->data;
}

std::optional<int> bst::max() const {
    if (!root) return std::nullopt;
    const Node* current = root;
    while (current->right) {
        current = current->right;
    }
    return current->data;
}

void bst::inorder_walk(Node* node, std::vector<int>& out) const {
    if (!node) return;
    inorder_walk(node->left,  out);
    out.push_back(node->data);
    inorder_walk(node->right, out);
}

void bst::preorder_walk(Node* node, std::vector<int>& out) const {
    if (!node) return;
    out.push_back(node->data);
    preorder_walk(node->left,  out);
    preorder_walk(node->right, out);
}

void bst::postorder_walk(Node* node, std::vector<int>& out) const {
    if (!node) return;
    postorder_walk(node->left,  out);
    postorder_walk(node->right, out);
    out.push_back(node->data);
}

std::vector<int> bst::inorder() const {
    std::vector<int> result;
    inorder_walk(root, result);
    return result;
}

std::vector<int> bst::preorder() const {
    std::vector<int> result;
    preorder_walk(root, result);
    return result;
}

std::vector<int> bst::postorder() const {
    std::vector<int> result;
    postorder_walk(root, result);
    return result;
}
