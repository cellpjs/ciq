#include <iostream>
#include <string>

using namespace std;

class Inode{
    public:
        int data;
        Inode* next;
};

class Istack {
    protected:
    Inode* top;

    public:
    /* constructor */
    Istack() {
        top=NULL;
    }

    int pop(){
        if (top==NULL) {
            return -1;
        }
        else {
            int k = top->data;
            top = top->next;
            /* delete node? */
            return k;
        }
    }

    void push(int val){
        if (top==NULL){
            top = new Inode;
            top->data = val;
            top->next = NULL;
        }
        else {
            Inode* temp = new Inode;
            temp->data = val;
            temp->next = top;
            top = temp;
        }
    }

    int peak(){
        if (top==NULL) {
            return -1;
        }
        else{
            return top->data;
        }
    }

    bool isempty(){
        return (top==NULL);
    }

    void probe(Inode* p){
        if (p==NULL) return;
        if (p->next!=NULL){
            probe(p->next);
        }
        cout << p->data << " ";
    }

    void display(){
        cout << "[";
        probe(top);
        cout << endl;
    }

};

void sortdis(Istack &s){
    Istack a1, a2;
    int k;

    if (!s.isempty()) {
        k=s.peak();
        a1.push(s.pop());
        /* recursive */
        if (!s.isempty()) {
            sortdis(s);
        }
    }

    while(!s.isempty()){
        if (s.peak()<=k){
            a1.push(s.pop());
        }
        else {
            a2.push(s.pop());
        }
    }

    while(!a1.isempty()){
        s.push(a1.pop());
    }
    while(!a2.isempty()){
        s.push(a2.pop());
    }
};

/* another approach */
Istack sortdis2(Istack s){
    Istack a; // keep a sorted
    int k;

    while (!s.isempty()){
        k = s.pop();

        while (!a.isempty() && a.peak()>k) {
            s.push(a.pop());
        }
        a.push(k);
    }

    return a;

}

int main(){

    Istack s;

    s.push(10);
    s.push(8);
    s.push(3);
    s.push(9);
    s.push(12);
    s.push(4);
    s.push(5);
    s.push(7);
    s.push(2);
    s.push(11);
    s.push(6);
    s.push(1);


    s.display();

    sortdis(s);

    s.display();

    Istack t = sortdis2(s);

    t.display();

}
