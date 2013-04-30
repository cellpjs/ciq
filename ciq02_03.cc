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

void removeNode(Inode* a){
    if (a==NULL) return;
    else if (a->next==NULL){
        a=NULL;
    }
    else{
        // copy and remove next node!!!
        a->data = a->next->data;
        a->next = a->next->next;
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
    Inode* r=head;
    for (int i=0;i<9;i++) r=r->next;
    removeNode(r);
    printList(head);

}
