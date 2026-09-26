#include <iostream>
#include "../../DoublyLinkedList.cpp"


int findMergedNode(Node* head1, Node* head2) {
    Node* p1 = head1;
    Node* p2 = head2;
    while(p1 != p2) {
        p1 = p1 -> next;
        p2 = p2 -> next;
        if(p1 == nullptr) p1 = head2;
        if(p2 == nullptr) p2 = head1;
        
    }
    return p1 -> value;
}

int main() {
    // Create first list: 1 -> 2 -> 3
    Node* head1 = new Node(1);
    head1->next = new Node(2);
    head1->next->next = new Node(3);

    // Create second list: 4 -> 5
    Node* head2 = new Node(4);
    head2->next = new Node(5);

    // Create merge point: 6 -> 7
    Node* merge = new Node(6);
    merge->next = new Node(7);

    // Attach merge point to both lists
    head1->next->next->next = merge; // list1: 1->2->3->6->7
    head2->next->next = merge;       // list2: 4->5->6->7

    std::cout << "Merge node data: " << findMergedNode(head1, head2) << '\n';
    return 0;
}