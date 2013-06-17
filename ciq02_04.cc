// partition a linked list around value x
// nodes less than x -> x -> nodes greater than x
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

void vpartition(Inode *&head, int k){
    Inode* h1 = NULL;
    Inode* t1 = NULL;
    Inode* h2 = NULL;
    Inode* t2 = NULL;
    Inode* h3 = NULL;
    Inode* t3 = NULL;
    Inode* a=head;
    while(a){
        if (a->data<k){
            if (h1==NULL){
                h1=a;
                t1=a;
            }
            else {
                t1->next=a;
                t1=a;
            }
        }
        else if (a->data>k){
            if (h3==NULL){
                h3=a;
                t3=a;
            }
            else {
                t3->next=a;
                t3=a;
            }
        }
        else {
            if (h2==NULL){
                h2=a;
                t2=a;
            }
            else {
                t2->next=a;
                t2=a;
            }
        }
        a=a->next;
    }
    head=h1;
    t1->next=h2;
    t2->next=h3;
    t3->next=NULL;
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
    vpartition(head, 5);
    printList(head);

}
