#include <iostream>

class Node {
    public:
        int value;
        Node* next;
        Node* prev;
        Node(int val) : value(val), next(nullptr), prev(nullptr) {};
        Node() {}
        Node* get_next() {
            return next;
        }

        Node* get_prev() {
            return prev;
        }
};

class DoublyLinkedList {
    private:
        Node* head;
        Node* tail;
    public:
        DoublyLinkedList() : head(nullptr), tail(nullptr) {}

        ~DoublyLinkedList() {
            Node* current = head;
            while(current) {
                Node* next = current->next;
                delete current;
                current = next;
            }
        }

        Node* begin() {
            return head;
        }
        Node* end() {
            return tail;
        }

        void insert(Node* node, int data) {
            if(!node) return;
            Node* new_node = new Node(data);
            new_node->next = node->next;
            new_node->prev = node;

            if(node->next) {
                node->next->prev = new_node;
            } else {
                tail = new_node;
            }
            node->next = new_node;
        }

        void push_back(int data) {
            Node* new_node = new Node(data);
            if(!head) {
                head = new_node;
                tail = new_node;
            } else {
                tail->next = new_node;
                new_node->prev = tail;
                tail = new_node;
            }
        }

        void erase(Node* node) {
            if(!node) return;
            if(node == head) {
                pop_front();
                return;
            }
            if(node == tail) {
                pop_back();
                return;
            }
            node->prev->next = node->next;
            node->next->prev = node->prev;
            delete node;
        }

        void push_front(int data) {
            Node* new_node = new Node(data);
            if(!head) {
                head = new_node;
                tail = new_node;
            } else {
                new_node -> next = head;
                head -> prev = new_node;
                head = new_node;
            }
        }

        void pop_front() {
            if(!head) return;
            Node* temp = head;
            head = head -> next;
            if(head) {
                head->prev = nullptr;
            } else {
                tail = nullptr;
            }
            delete temp;
        }

        void pop_back() {
            if(!tail) return;
            Node* temp = tail;
            tail = tail -> prev;
            if(tail) {
                tail -> next = nullptr;
            } else {
                head = nullptr;
            }
            delete temp;
        }

        void print_forward() {
            Node* current = head;
            while(current) {
                std::cout<<current->value<<" ";
                current = current -> next;
            }
            std::cout<<"\n";
        }

        void print_backward() {
            Node* current = tail;
            while(current) {
                std::cout<<current->value<<" ";
                current = current -> prev;
            }
            std::cout<<"\n";
        }

        int get_size() {
            int size = 0;
            Node *current = head;
            while(current != nullptr) {
                size++;
                current = current->next;
            }
            return size;
        }
};

int main() {
    DoublyLinkedList list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.insert(list.begin()->next->next,999);
    list.print_forward(); // 1 2 3 999 4

    list.erase(list.end()->prev->prev);
    list.print_forward(); // 1 2 999 4

    Node* b = list.begin();
    Node* e = list.end();
    std::cout<<b->value<<"\n"; // 1
    std::cout<<e->value<<"\n"; // 4
    return 0;
}