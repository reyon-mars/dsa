#pragma once
#include <cstddef>
#include <optional>
#include <vector>

class bst
{
public:
	bst() = default;
	~bst();

	bst(const bst&) = delete;
	bst& operator=(const bst&) = delete;
	bst(bst&&) = default;
	bst& operator=(bst&&) = default;

	void insert_node(int val);
	bool search(int val) const;
	void delete_node(int val);
	size_t size() const;
	bool empty() const;

	std::vector<int> inorder() const;
	std::vector<int> preorder() const;
	std::vector<int> postorder() const;

	std::optional<int> min() const;
	std::optional<int> max() const;

private:
	struct Node
	{
		int data;
		Node* left = nullptr;
		Node* right = nullptr;
		explicit Node(int val) : data{val}
		{
		}
	};

	Node* root = nullptr;
	size_t tree_size = 0;

	void destroy(Node* node);
	Node* remove(Node* node, int val, bool& removed);
	Node* min_node(Node* node) const;
	void inorder_walk(Node* node, std::vector<int>& out) const;
	void preorder_walk(Node* node, std::vector<int>& out) const;
	void postorder_walk(Node* node, std::vector<int>& out) const;
};
