#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
    Node(int val) : value(val), next(nullptr) { }
};

class List {
    public:
        List() : m_head(nullptr) { }
        void insert(int val) {
            Node* node = new Node(val);
            if (m_head == nullptr) {
                m_head = node;
            }
            else {
                Node* temp = m_head;
                while (temp->next != nullptr) {
                    temp = temp->next;
                }
                temp->next = node;
            }
        }
        void display() {
            Node* temp = m_head;
            while (temp != nullptr) {
                cout << temp->value << endl;
                temp = temp->next;
            }
        }

        int getKthFromLast(int k) {
            if (m_head == nullptr) {
                cout << "list is empty\n";
                return 0;
            }
            Node* slow = m_head;
            Node* fast = m_head;
            for (int i = 0; i < k; i++) {
                if (fast == nullptr) {
                    cout << "k is bigger than length of list\n";
                    return 0;
                }
                fast = fast->next;
            }
            while (fast != nullptr) {
                slow = slow->next;
                fast = fast->next;
            }
            return slow->value;
        }

    private:
        Node* m_head;
};

int main() {
    List list;
    list.insert(5);
    list.insert(6);
    list.insert(4);
    cout << list.getKthFromLast(4) << endl;
}