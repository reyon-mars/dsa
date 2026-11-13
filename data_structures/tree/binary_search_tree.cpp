#pragma once

#include <cstddef>
#include <initializer_list>
#include <memory>
#include <optional>
#include <vector>

class bst
{
public:
	bst() = default;
	bst(std::initializer_list<int> values);
	bst(const bst& other);
	bst(bst&& other) noexcept;
	bst& operator=(const bst& other);
	bst& operator=(bst&& other) noexcept;
	~bst() = default;

	bool insert_node(int val);
	bool delete_node(int val);
	void clear() noexcept;
	void swap(bst& other) noexcept;

	[[nodiscard]] bool search(int val) const;
	[[nodiscard]] std::size_t size() const noexcept;
	[[nodiscard]] bool empty() const noexcept;
	[[nodiscard]] std::size_t height() const noexcept;
	[[nodiscard]] std::optional<int> min() const;
	[[nodiscard]] std::optional<int> max() const;

	[[nodiscard]] std::vector<int> inorder() const;
	[[nodiscard]] std::vector<int> preorder() const;
	[[nodiscard]] std::vector<int> postorder() const;
	[[nodiscard]] std::vector<int> level_order() const;

	friend void swap(bst& a, bst& b) noexcept { a.swap(b); }

private:
	struct Node
	{
		int data;
		std::unique_ptr<Node> left;
		std::unique_ptr<Node> right;

		explicit Node(int value) noexcept : data(value) {}
	};

	using NodePtr = std::unique_ptr<Node>;

	[[nodiscard]] static const Node* min_node(const Node* node) noexcept;
	[[nodiscard]] static std::size_t height_of(const Node* node) noexcept;
	[[nodiscard]] static NodePtr clone(const Node* node);
	[[nodiscard]] static NodePtr remove(NodePtr node, int val, bool& removed);

	static void inorder_walk(const Node* node, std::vector<int>& out);
	static void preorder_walk(const Node* node, std::vector<int>& out);
	static void postorder_walk(const Node* node, std::vector<int>& out);

	NodePtr root;
	std::size_t tree_size = 0;
};
