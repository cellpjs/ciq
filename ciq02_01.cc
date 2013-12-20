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
    while (a && a->next){
        // check all node after a
        Inode* b=a;
        while (b && b->next){
            if (b->next->data==a->data){
                delete b->next;
                b->next=b->next->next;
            }
            b=b->next;
        }
        a=a->next;
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
