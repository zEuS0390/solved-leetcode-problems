#include <functional>
#include <iostream>
#include <stack>
#include <cmath>

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

	~BinarySearchTree() {
		this->deleteTree(this->root);
	}

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
	Node<T>* root;
private:
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
	void deleteTree(Node<T>* node) {
		if (node != nullptr) {
			deleteTree(node->left);
			deleteTree(node->right);
			delete node;
		}
	}
};

// These are not the solutions to the problem.
// NOTE: Design an algorithm that runs in less than O(n) time complexity.
/*
int countNodes(BinarySearchTree<int>* bst) {
	function<int(Node<int>*)> count;

	count = [&count](Node<int>* node) -> int {
		if (node == nullptr) return 0;
		return 1 + count(node->left) + count(node->right);
	};

	int number_of_nodes = count(bst->getRoot());

	return number_of_nodes;
}

int countNodesIterative(BinarySearchTree<int>* bst) {
	int number_of_nodes = 0;

	stack<Node<int>*> _stack;

	_stack.push(bst->getRoot());

	while (!_stack.empty()) {
		Node<int>* currentNode = _stack.top();
		_stack.pop();
		
		++number_of_nodes;

		if (currentNode->right != nullptr)
			_stack.push(currentNode->right);

		if (currentNode->left != nullptr)
			_stack.push(currentNode->left);
	}

	return number_of_nodes;
}
*/

// This is the correct solution to the problem because it's time complexity is O((log(N))^2) which is better than the solutions provided above with O(N) time complexity
int countNodes(BinarySearchTree<int>* bst) {
	
	function<int(Node<int>*)> count;

	count = [&count](Node<int>* node) {
		if (node == nullptr) return 0;

		int left_levels = 0, right_levels = 0;
		Node<int>* leftNode = node;
		Node<int>* rightNode = node;

		// Get the extreme depth of the left subtree
		while (leftNode != nullptr) {
			leftNode = leftNode->left;
			left_levels += 1;
		}

		// Get the extreme depth of the right subtree
		while (rightNode != nullptr) {
			rightNode = rightNode->right;
			right_levels += 1;
		}

		// If the two subtree have the same depth, it implies that the tree is a perfect binary tree
		if (left_levels == right_levels)
			// return static_cast<int>(pow(2, left_levels)) - 1;
			
			// '1 << left_level' does the same with 2^left_levels
			// It shifts the 1 bit to the left in 'left_levels' times.
			return (1 << left_levels) - 1;

		return 1 + count(node->left) + count(node->right);
	};

	return count(bst->getRoot());
}

int main(int argc, char* argv[]) {
	BinarySearchTree<int>* bst = new BinarySearchTree<int>;

	// Complete Binary Tree (using bst->insert will not build a complete binary tree)
	// I manually created and connected the nodes to achieve a complete binary tree
	Node<int>* node5 = new Node<int>(6, nullptr, nullptr);
	Node<int>* node4 = new Node<int>(5, nullptr, nullptr);
	Node<int>* node3 = new Node<int>(4, nullptr, nullptr);
	Node<int>* node2 = new Node<int>(3, node5, nullptr);
	Node<int>* node1 = new Node<int>(2, node3, node4);
	Node<int>* node0 = new Node<int>(1, node1, node2);

	bst->root = node0;

	/*

	Complete Binary Tree (CBT)

	          1 
	         / \
	        /   \
	       2     3 
	      / \   / 
	     4   5 6 

	*/

	cout << "Complete Binary Tree (Inorder Traversal): ";
	bst->printInOrder();

	int number_of_nodes = countNodes(bst);
	cout << "Number of Nodes in a Complete Binary Tree: " << number_of_nodes << endl;

	delete bst;
	return 0;
}
