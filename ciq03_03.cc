#include <iostream>
#include <string>
#include <climits>

using namespace std;

class Inode{
    public:
        int data;
        Inode* next;
};

class Istacksub {
    protected:
    Inode* top;
    int height;

    public:
    Istacksub* prev;

    /* constructor */
    Istacksub() {
        top=NULL;
        height=0;
    }

    int pop(){
        if (top==NULL) {
            return -1;
        }
        else {
            int k = top->data;
            top = top->next;
            /* delete node? */
            height--;
            return k;
        }
    }

    void push(int val){
        if (top==NULL){
            top = new Inode;
            top->data = val;
            top->next = NULL;
            height++;
        }
        else {
            Inode* temp = new Inode;
            temp->data = val;
            temp->next = top;
            top = temp;
            height++;
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

    int getHeight(){
        return height;
    }

};


class Setofstacks {
    Istacksub* current;
    int threshold;
    int numstacks;

    public:
    Setofstacks(int h) {
        threshold = h;
        current = new Istacksub;
        current->prev=NULL;
        numstacks=1;
    }

    void push(int val){
        if (current->getHeight()<threshold) {
            current->push(val);
        }
        else {
            Istacksub* temp = current;
            current = new Istacksub;
            current->prev = temp;
            current->push(val);
            numstacks++;
        }
    }

    int pop(){
        if (current->getHeight()>0){
            return current->pop();
        }
        else if (current->prev) {
            current = current->prev;
            numstacks--;
            return current->pop();
        }
        else {
            return -1;
        }
    }

    int peak(){
        return current->peak();
    }

    int popAt(int ind){
        if (ind<0||ind>=numstacks){
            return -1;
        }
        else{
            Istacksub* mover = current;
            int back = numstacks - ind - 1;
            for (int i=0; i<back; i++){
                mover = mover->prev;
            }
            return mover->pop();
        }
    }

};

int main(){

    Setofstacks ss(6);

    ss.push(1);
    ss.push(2);
    ss.push(3);
    ss.push(4);
    ss.push(5);
    ss.push(6);
    ss.push(7);
    ss.push(8);
    ss.push(9);
    ss.push(10);
    ss.push(11);
    ss.push(12);
    ss.push(13);
    ss.push(14);
    ss.push(15);
    ss.push(16);
    ss.push(17);
    ss.push(18);
    cout << ss.popAt(0) << endl;
    cout << ss.popAt(1) << endl;
    cout << ss.popAt(2) << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;
    cout << ss.pop() << endl;

}
