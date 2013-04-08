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

bool isPalindrome(Inode *a){
    int len = length(a);
    for (int i=0; i<len/2; i++){
        if (getKth(a,i)!=getKth(a,len-1-i)) return false;
    }
    return true;
}

Inode* copyList(Inode *a){
    Inode* b = NULL;
    while(a) {
        appendNode(b, a->data);
        a=a->next;
    }
    return b;
}

void reverseListR(Inode *&a){
    if (a==NULL || a->next==NULL) return;
    Inode* t = a->next;
    Inode* h = a->next;
    reverseListR(h);
    t->next = a;
    a->next = NULL;
    a = h;
}

bool isEqual(Inode *a, Inode *b){
    if (length(a)!=length(b)) return false;
    while (a && b){
        if (a->data != b->data) return false;
        a=a->next;
        b=b->next;
    }
    return true;
}


int main(){

    Inode* a = NULL;
    for (int i=0; i<5; i++){
        appendNode(a, i);
    }
    appendNode(a,5);
    for (int i=0; i<5; i++){
        appendNode(a, 4-i);
    }
    printList(a);

    cout << "palindrome? " << isPalindrome(a) << endl;

    Inode* b = copyList(a);

    reverseListR(b);

    cout << "reverse same as forward? " << isEqual(a,b) << endl;

}
