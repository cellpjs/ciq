#include <iostream>
#include <string>
#include <climits>

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

};

class Istackmin : public Istack {
    Istack minstack;

    public:
    int pop(){
        if (this->peak()==minstack.peak()){
            minstack.pop(); // return to ?
            return Istack::pop();
        }
        else{
            return Istack::pop();
        }
    }

    void push(int val){
        if (this->top==NULL || val <= minstack.peak()){
            minstack.push(val);
        }
        Istack::push(val);
    }

    int min() {
        return minstack.peak();
    }

};


int main(){

   Istackmin s;

   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);

   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;
   cout << "out: " << s.pop() << endl;
   cout << "min: " << s.min() << endl;
   cout << "top: " << s.peak() << endl;

}
