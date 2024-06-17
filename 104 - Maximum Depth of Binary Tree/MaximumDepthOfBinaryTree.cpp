#include <functional>
#include <iostream>
#include <stack>
#include <utility>

using namespace std;

template <typename T>
class Node {
public:
	Node(T value, Node<T>* left, Node<T>* right): value(value), left(left), right(right) {}
	T value;
	Node<T>* left;
	Node<T>* right;
};

template <typename T>
class BinarySearchTree {
public:
	BinarySearchTree() {}

	void insert(T value) {
		Node<T>* node = new Node<T>(value, nullptr, nullptr);
		if (this->root == nullptr) {
			this->root = node;
		} else {
			Node<T>* currentNode = this->root;
			while (true) {
				if (value <= currentNode->value) {
					if (currentNode->left == nullptr) {
						currentNode->left = node;
						break;
					} 
					currentNode = currentNode->left;
				} else if (value > currentNode->value) {
					if (currentNode->right == nullptr) {
						currentNode->right = node;	
						break;
					}
					currentNode = currentNode->right;
				}
			}
		}
	}

	Node<T>* lookup(T value) {
		if (this->root == nullptr)
			return nullptr;
		Node<T>* currentNode = this->root;
		while (currentNode) {
			if (value < currentNode->value)
				currentNode = currentNode->left;
			else if (value > currentNode->value)
				currentNode = currentNode->right;
			else
				break;
		}
		return currentNode;
	}

	void remove(T value) {

		auto findMin = [](Node<T>* node) -> Node<T>* {
			if (node == nullptr) return nullptr;
			Node<T>* current = node;
			while (current->left != nullptr)
				current = current->left;
			return current;
		};

		std::function<Node<T>*(Node<T>*, T)> removeNode;
		removeNode = [&removeNode, findMin](Node<T>* node, T target) -> Node<T>* {
			if (node == nullptr) return nullptr;
			else if (target < node->value) {
				cout << "traversing to right node" << endl;
				node->left = removeNode(node->left, target);
			} else if (target > node->value) {
				cout << "traversing to right node" << endl;
				node->right = removeNode(node->right, target);
			} else {
				cout << "found: " << node->value << endl;
				// Case 1: No child
				if (node->left == nullptr && node->right == nullptr) {
					cout << "replacing with leaf node" << endl;
					delete node;
					node = nullptr;
				}
				// Case 2: One child
				else if (node->left == nullptr) {
					cout << "replacing with right node" << endl;
					Node<T>* tmp = node;
					node = node->right;
					delete tmp;
				}
				else if (node->right == nullptr) {
					cout << "replacing with left node" << endl;
					Node<T>* tmp = node;
					node = node->left;
					delete tmp;
				}
				// Case 3: Two Children
				else {
					cout << "replacing with the minimum value in the subtree" << endl;
					Node<T>* minimum_value = findMin(node->right);
					node->value = minimum_value->value;
					node->right = removeNode(node->right, minimum_value->value);
				}
			}
			return node;
		};

		// Remove the node
		this->root = removeNode(this->root, value);
	}
	void printInOrder() {
		inOrderTraversal(this->root);
		cout << endl;
	}
	Node<T>* getRoot() {
		return this->root;
	}
private:
	Node<T>* root;
	// Recursive function for in-order traversal
	void inOrderTraversal(Node<T>* node) {
		if (node != nullptr) {
		    // Traverse left subtree
		    inOrderTraversal(node->left);

		    // Print current node's value
		    cout << node->value << " ";

		    // Traverse right subtree
		    inOrderTraversal(node->right);
		}
	}
};

int maxDepth(BinarySearchTree<int>* bst) {
	if (bst->getRoot() == nullptr) return 0;

	int max_depth = 0;

	stack<pair<Node<int>*, int>> _stack;

	_stack.push({bst->getRoot(), 1});

	while (!_stack.empty()) {
		auto [currentNode, depth] = _stack.top();
		_stack.pop();

		max_depth = max(max_depth, depth);

		if (currentNode->right != nullptr)
			_stack.push({currentNode->right, depth+1});

		if (currentNode->left != nullptr)
			_stack.push({currentNode->left, depth+1});
	}

	return max_depth;
}

int main(int argc, char* argv[]) {
	BinarySearchTree<int>* bst = new BinarySearchTree<int>;

	bst->insert(12);
	bst->insert(5);
	bst->insert(15);
	bst->insert(3);
	bst->insert(7);
	bst->insert(1);
	bst->insert(9);
	bst->insert(13);
	bst->insert(17);

	/*

	Binary Search Tree (BST)

	          12
	         /  \
	        /    \
	       5      15
	      / \    /  \
	     3   7  13  17
	    /     \
	   1       9

	*/

	int max_depth = maxDepth(bst);
	cout << "Max Depth: " << max_depth << endl;
	return 0;
}
