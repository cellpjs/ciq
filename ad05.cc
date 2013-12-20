/* remove elements with given value from linked list (harder than it sounds) */
#include <iostream>
#include <string>

using namespace std;

class Inode{
    public:
        int data;
        Inode* next;
};

void printList(Inode* a){
    while (a){
        cout << a->data << " ";
        a = a->next;
    }
    cout << endl;
}

void removeValue(Inode *&head, int k){
    // make changes before you get to the node (next)
    Inode* a = head;
    Inode* temp;

    while (a && a->data==k){
        // change head to next node (head passed by reference)
        head = a->next;
        delete a;
        a = a->next;
    }
    // done with leading k's
    while (a){
        while (a->next && a->next->data==k){
            temp = a->next->next;
            delete a->next;
            a->next = temp;
        }
        a = a->next; // advance only when done with consecutive k's
    }
}

int main(){

    Inode* head = new Inode;
    head->data = rand()%10;
    head->next = NULL;

    Inode* tail = head;

    for (int i=0;i<29;i++){
        Inode* anode = new Inode;
        anode->data = rand()%10;
        anode->next = NULL;
        tail->next = anode;
        tail = anode;
    }

    printList(head);
    removeValue(head, 5);
    printList(head);
}
