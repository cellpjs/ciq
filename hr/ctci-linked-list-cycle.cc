/*
Detect a cycle in a linked list. Note that the head pointer may be 'NULL' if the list is empty.

A Node is defined as: 
    struct Node {
        int data;
        struct Node* next;
    }
*/
#include<set>
bool has_cycle(Node* head) {
    // Complete this function
    // Do not write the main method
    std::set<Node*> seen;
    Node *p = head;
    if (p==NULL){
        return 0;
    }
    seen.insert(p);
    while (p->next != NULL) {
        p = p->next;
        if (seen.count(p) > 0) {
            return 1;
        }
        seen.insert(p);
    }
    return 0;
}
