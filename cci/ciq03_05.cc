// implement a queue using two stacks
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

class Qstack {
    Istack sa;
    Istack sb;
    
    public:
    
    void push(int val){
        sa.push(val);
        if (sb.isempty()) {
            a2b();
        }
    }
    
    int pop(){
        int k = sb.pop();
        if (sb.isempty()) {
            a2b();
        }
        return k;
    }
    
    void a2b(){
        while (!sa.isempty()){
            sb.push(sa.pop());
        }
    }
    
    
};

int main(){

    Qstack qs;

    qs.push(1);
    cout << qs.pop() << endl;
    qs.push(2);
    qs.push(3);
    cout << qs.pop() << endl;
    qs.push(4);
    cout << qs.pop() << endl;
    qs.push(5);
    qs.push(6);
    cout << qs.pop() << endl;
    cout << qs.pop() << endl;
    qs.push(7);
    qs.push(8);
    qs.push(9);
    cout << qs.pop() << endl;
        
    
}
