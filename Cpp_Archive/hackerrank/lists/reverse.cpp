#include <iostream>
#include "../../DoublyLinkedList.cpp"

Node* reverse(Node* head) {
    if(!head) {
        return nullptr;
    }
    Node* current = head;
    Node* new_head = nullptr;
    while(current) {
        Node* temp = current->next;
        current->next = current->prev;
        current->prev = temp;
        new_head = current;
        current = current -> prev;
    }
    return new_head;
}

void print_forward(Node* node) {
    Node* current = node;
    while(current) {
        std::cout<<current->value<<" ";
        current = current -> next;
    }
    std::cout<<"\n";
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->prev = head;
    head->next->next = new Node(3);
    head->next->next->prev = head->next;
    head->next->next->next = new Node(4);
    head->next->next->next->prev = head->next->next;
    print_forward(head); // normal head: 1 2 3 4
    head = reverse(head);
    print_forward(head); // reversed head: 4 3 2 1
    return 0;    
}