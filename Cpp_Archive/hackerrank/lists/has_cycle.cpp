#include <iostream>
#include "../../DoublyLinkedList.cpp"

bool has_cycle(Node *head) {
    if(!head) return false;
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next) {
        slow = slow -> next; // move 1 step
        fast = fast -> next -> next; // move 2 steps
        if(slow == fast) return true; // they meet -> cycle detected
    }
    return false;
}

int main() {
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);
    // // create a cycle: node 5 -> node 3
    head->next->next->next->next->next = head->next->next;
    std::cout<<has_cycle(head)<<"\n";
    return 0;
}