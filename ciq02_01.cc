/* remove duplicates from linked list */
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

void removeDuplicate(Inode *a){
    Inode* b=a;
    while (b && b->next){
        // check all node after b
        Inode* c=b;
        while (c && c->next){
            if (c->next->data==b->data){
                delete c->next;
                c->next=c->next->next;
            }
            c=c->next;
        }
        b=b->next;
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
    removeDuplicate(head);
    printList(head);
}
