#include <iostream>
#include <string>
#include <set>

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

void appendNode(Inode *&h, int k){
    if (h==NULL){
        h = new Inode;
        h->data = k;
        h->next = NULL;
    }
    else{
        Inode* anode = new Inode;
        anode->data = k;
        anode->next = NULL;
        Inode* r = h;
        while(r->next){
            r=r->next;
        }
        r->next = anode;
    }
}

void pushNode(Inode *&h, int k){
    Inode* anode = new Inode;
    anode->data = k;
    anode->next = h;
    h=anode;
}

int length(Inode *a){
    int k=0;
    while (a) {
        a=a->next;
        k++;
    }
    return k;
}

int getKth(Inode *a, int k){
    if (k>length(a)-1||k<0) return -1; /* k should be between 0 and length(a)-1 */
    for (int i=0; i<k; i++){
        a=a->next;
    }
    return a->data;
}

Inode* findLoop(Inode *a){
    if (!a) return NULL;
    set<Inode *> visited;
    while (a->next && visited.count(a)==0){
        visited.insert(a);
        a=a->next;
    }
    return a;
}

Inode* findLoopAnother(Inode *a){
    if (!a) return NULL;
    Inode* slow = a;
    Inode* fast = a;
    while (slow->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
        if (slow==fast) break;
    }
    slow = a;
    while (slow->next && fast->next){
        slow=slow->next;
        fast=fast->next;
        if (slow==fast) break;
    }
    return slow;
}

int main(){

    Inode* a = NULL;
    for (int i=0; i<8; i++){
        appendNode(a, i);
    }
    printList(a);

    /* make loop */
    Inode* b = a;
    while (b->next) {
        b=b->next;
    }
    Inode* c = a;
    for (int i=0; i<3; i++){
        c=c->next;
    }
    b->next = c;
    cout << b->data << " to " << c->data << endl;

    Inode* s;
    s = findLoop(a);
    cout << "found " << s->data << endl;

    Inode* t;
    t = findLoopAnother(a);
    cout << "found " << t->data << endl;


}
