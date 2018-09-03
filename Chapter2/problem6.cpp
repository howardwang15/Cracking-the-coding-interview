#include <iostream>
#include <stack>
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

	bool isPalindrome() {
		stack<int> s;
		Node* slow = head;
		Node* fast = head;
		while (fast != nullptr && fast->next != nullptr) {
			s.push(slow->value);
			fast = fast->next->next;
			slow = slow->next;
		}

		if (fast != nullptr)
			slow = slow->next;
		while (slow != nullptr) {
			if (s.top() != slow->value) {
				return false;
			}
			s.pop(); 
			slow = slow->next;
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
	list.insert(1);
	list.insert(2);
	list.insert(1);
	list.insert(0);
	list.insert(-5);
	if (list.isPalindrome())
		cout << "the list is a palindrome\n";
	else 
		cout << "the list isn't a palindrome\n";
}	