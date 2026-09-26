#include <iostream>
#include "../../DoublyLinkedList.cpp"

Node* sortedInsert(Node* head, int data) {
    Node* new_node = new Node(data);
    if(!head) {
        return new_node;
    }
    if(data <= head->value) {
        new_node -> next = head;
        head -> prev = new_node;
        return new_node;
    }
    Node* current = head;
    while(current -> next && current -> next -> value < data) {
        current = current -> next;
    }
    new_node -> next = current -> next;
    new_node -> prev = current;
    if(current -> next) {
        current -> next -> prev = new_node;
    }
    current -> next = new_node;
    return head;
}

int main() {
    Node *head = nullptr;
    head = sortedInsert(head, 10);
    head = sortedInsert(head, 3);
    head = sortedInsert(head, 9999);
    head = sortedInsert(head, 1);
    head = sortedInsert(head, -2);
    head = sortedInsert(head, 0);
    
    Node* current = head;
    while(current) {
        std::cout<<current->value<<" ";
        current = current->next;
    }
    std::cout<<"\n";
    return 0;
}