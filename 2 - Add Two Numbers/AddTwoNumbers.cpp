#include <iostream>

using namespace std;

class Node {
public:
	Node(int v, Node* n, Node* p): value(v), next(n), prev(p) {}
	int value;
	Node* next;
	Node* prev;
};

class LinkedList {
public:
	Node* head;
	Node* tail;
	int length;

	LinkedList(int value): head(nullptr), tail(nullptr), length(0) {
		this->append(value);	
	}

	LinkedList(): head(nullptr), tail(nullptr), length(0) {}

	~LinkedList() {
		Node* current = this->head;
		while (current != nullptr) {
			Node* next = current->next;
			delete current;
			current = next;
		}
		this->head = nullptr;
		this->tail = nullptr;
		this->length = 0;
	}

	bool isEmpty() {
		return this->length == 0;
	}

	void append(int value) {
		Node* node = new Node(value, nullptr, nullptr);
		if (this->isEmpty()) {
			this->head = node;
		} else {
			node->prev = tail;
			this->tail->next = node;
		}
		this->tail = node;
		this->length++;
	}

	void prepend(int value) {
		Node* node = new Node(value, head, nullptr);
		if (this->isEmpty()) {
			this->append(value);
			return;
		} 
		this->head->prev = node;
		this->head = node;
		this->length++;
	}

	void insert(int index, int value) {
		if (index <= 0) {
			this->prepend(value); 
			return;
		} else if (index >= this->length) {
			this->append(value);
			return;
		}
		Node* target = this->get(index);
		Node* parent = target->prev;
		Node* node = new Node(value, target, parent);	
		parent->next = node;
		target->prev = node;
		this->length++;
	}

	Node* get(unsigned int index) {
		if (index > this->length-1)
			return nullptr;
		Node* current = this->head;
		unsigned int i = 0;
		while (current != nullptr) {
			if (i == index)
				return current;
			current = current->next;
			++i;
		}
		return nullptr;
	}

	void remove(int index) {
		if (this->isEmpty()) return;

		if (index < 0 || index >= this->length) return;
		
		Node* target = get(index);
		if (target == nullptr) return;

		if (target->prev != nullptr)
			target->prev->next = target->next;
		else
			head = target->next;
		
		if (target->next != nullptr)
			target->next->prev = target->prev;
		else 
			tail = target->prev;

		delete target;
		--this->length;
	}

	void reverse() {
		Node* current = this->head;
		Node* temp = nullptr;

		while (current != nullptr) {
			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
			current = current->prev;
		}

		if (temp != nullptr) {
			this->tail = this->head;
			this->head = temp->prev;
		}
	}

	friend ostream& operator<<(ostream& os, const LinkedList& linked_list) {
		Node* tmp = linked_list.head;
		while (tmp != nullptr) {
			os << tmp->value << " --> " << ((tmp->next != nullptr)? "": "nullptr");
			tmp = tmp->next;
		}
		return os;
	}
};

LinkedList* addTwoNumbers(LinkedList* l1, LinkedList* l2) {
	Node* current_l1 = l1->head;
	Node* current_l2 = l2->head;

	LinkedList* result = new LinkedList;

	char carry = 0;

	while (current_l1 != nullptr || current_l2 != nullptr || carry > 0) {
		char sum = 0, total = 0;

		if (current_l1 != nullptr)
			sum += current_l1->value;

		if (current_l2 != nullptr)
			sum += current_l2->value;

		sum += carry;
		carry = sum / 10;
		total = sum % 10;

		result->append(total);

		if (current_l1 != nullptr)
			current_l1 = current_l1->next;

		if (current_l2 != nullptr)
			current_l2 = current_l2->next;
	}

	return result;
}

int main(int argc, char* argv[]) {
	LinkedList* number1 = new LinkedList;
	number1->append(9);
	number1->append(9);
	number1->append(9);
	number1->append(9);
	number1->append(9);
	number1->append(9);
	number1->append(9);

	LinkedList* number2 = new LinkedList;
	number2->append(9);
	number2->append(9);
	number2->append(9);
	number2->append(9);

	LinkedList* result = addTwoNumbers(number1, number2);

	cout << "INPUT1: " << *number1 << endl;
	cout << "INPUT2: " << *number2 << endl;
	cout << "RESULT: " << *result << endl;

	delete number1;
	delete number2;
	delete result;
	return 0;
}
