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

void addDigits(Inode* a, Inode* b, Inode *&c){
    int carry=0;
    while (a||b){
        int aval = a? a->data : 0;
        int bval = b? b->data : 0;
        int cval = (aval + bval + carry)%10;
        carry = (aval + bval + carry)/10;
        appendNode(c, cval);
        if (a) a=a->next;
        if (b) b=b->next;
    }
    if (carry) {
        appendNode(c, 1);
    }
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

void addDigitsR(Inode* a, Inode* b, Inode *&c){
    int alen = length(a);
    int blen = length(b);
    int aval, bval, cval;
    int maxlen = (alen>blen) ? alen : blen;
    int carry = 0;
    for (int i=0; i<maxlen; i++){
        aval = (alen-1-i>=0)? getKth(a, alen-1-i) : 0;
        bval = (blen-1-i>=0)? getKth(b, blen-1-i) : 0;
        cval = (aval + bval + carry)%10;
        carry = (aval + bval + carry)/10;
        pushNode(c, cval);
    }
    if (carry) {
        pushNode(c, 1);
    }
}


int main(){

    Inode* a = NULL;
    for (int i=0; i<8; i++){
        appendNode(a, rand()%10);
    }

    Inode* b = NULL;
    for (int i=0; i<6; i++){
        appendNode(b, rand()%10);
    }

    printList(a);
    printList(b);

    Inode* c = NULL;
    addDigits(a, b, c);
    printList(c);

    Inode* d = NULL;
    addDigitsR(a, b, d);
    printList(d);


}
