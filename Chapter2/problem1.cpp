#include <iostream>
#include <unordered_set>

using namespace std;

class List {
public:
	List() { head = nullptr; }
	void insert(int value) {
		if (head == nullptr) {
			head = new Node;
			head->next = nullptr;
			head->value = value;
		} else {
			Node* temp = head;
			while (temp->next != nullptr)
				temp = temp->next;
			Node* node = new Node;
			node->next = nullptr;
			temp->next = node;
			node->value = value;
		}
	}

	void removeDupes() {
		
		if (head == nullptr || head->next == nullptr)
			return;
		unordered_set<int> set;

		Node* temp = head;
		set.insert(head->value);
		while (temp->next != nullptr) {
			if (set.find(temp->next->value) == set.end()) {
				set.insert(temp->next->value);
				temp = temp->next;
			}
			else {
				Node* tempNext = temp->next;
				temp->next = tempNext->next;
				delete tempNext;
			}
		}
	}

	void display() {
		Node* temp = head;
		while (temp != nullptr) {
			cout << temp->value << endl;
			temp = temp->next;
		}
	}



private:
	struct Node	{
		int value;
		Node* next;
	};
	Node* head;
};

int main () {
	List list;
	list.insert(0);
	list.insert(0);
	list.insert(1);
	list.insert(1);
	list.insert(3);
	list.insert(3);
	list.removeDupes();
	list.display();
}