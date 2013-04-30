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

int kfromLast(Inode* a, int k){
    Inode* b=a;
    for (int i=0; i<k; i++){
        if (b){
            b=b->next;
        }
        else{
            return -1;
        }
    }
    Inode *c=a;
    while(b){
        b=b->next;
        c=c->next;
    }
    return c->data;
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
    cout << kfromLast(head, 10) << endl;

}
