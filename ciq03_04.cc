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

class Towerofhanoi {
    Istack stack[3];
    int levels;
    int counter;

    void move(Istack &s, Istack &d){
        if (!s.isempty() && (d.isempty() || s.peak()<d.peak()) ){
            //cout << s.peak();
            d.push(s.pop());
        }
        cout << ++counter << endl;
        showstacks();
    }

    void recplay(int n, Istack &src, Istack &med, Istack &dest) {
        if (n>1){
            recplay(n-1, src, dest, med);
        }
        move(src, dest); /* largest disc */
        if (n>1){
            recplay(n-1, med, src, dest);
        }
    }

    public:
    /* constructor */
    Towerofhanoi(int N){
        for (int i=N; i>=1; i--)
        stack[0].push(i);
        levels = N;
        counter = 0;
    }

    void play() {
        recplay(levels, stack[0], stack[1], stack[2]);
    }

    void showstacks() {
        stack[0].display();
        stack[1].display();
        stack[2].display();
    }

};

int main(){

    Towerofhanoi toh(10);

    toh.showstacks();

    toh.play();

}
