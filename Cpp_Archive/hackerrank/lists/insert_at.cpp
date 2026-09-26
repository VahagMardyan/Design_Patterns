#include <iostream>
#include "../../DoublyLinkedList.cpp"


Node* insertAt(Node* head, int data, int pos) {
    Node* new_node = new Node(data);
    if(!head || pos <= 0) {
        new_node -> next = head;
        return new_node;
    }
    Node* current = head;
    for(size_t i=0; current->next && i < pos - 1; i++) {
        current = current -> next;
    }
    new_node -> next = current -> next;
    current -> next = new_node;
    return head;
}

void printList(Node* list) {
    Node* current = list;
    while(current) {
        std::cout<<current->value<<" ";
        current = current -> next;
    }
    std::cout<<"\n";
}

int main() {
    Node* head = nullptr;
    head = insertAt(head, 10, 0); // 10
    head = insertAt(head, 20, 1); // 10 -> 20
    head = insertAt(head, 5, 0);  // 5 -> 10 -> 20
    head = insertAt(head, 15, 2); // 5 -> 10 -> 15 -> 20
    head = insertAt(head, 25, 10); // append at end: 5 -> 10 -> 15 -> 20 -> 25

    std::cout<<"Linked list: "<<std::endl;
    printList(head);
    return 0;
}