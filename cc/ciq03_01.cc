// implement three stacks using a single array
#include <iostream>
#include <string>
#define STACKLEN 10

using namespace std;

class Tristack {
    int A[3*STACKLEN];
    int* tops[3];
    int* lbound[3];
    int* ubound[3];

    public:
    /* constructor */
    Tristack() {
        tops[0]=NULL;
        tops[1]=NULL;
        tops[2]=NULL;
        lbound[0]= &A[0];
        ubound[0]= &A[STACKLEN-1];
        lbound[1]= &A[STACKLEN];
        ubound[1]= &A[2*STACKLEN-1];
        lbound[2]= &A[2*STACKLEN];
        ubound[2]= &A[3*STACKLEN-1];
    }

    int pop(int ind){
        int* p;
        if (tops[ind]==NULL) {
            return -1;
        }
        else if (tops[ind]==lbound[ind]){
            p=tops[ind];
            tops[ind]=NULL;
            return *p;
        }
        else {
            p=tops[ind];
            tops[ind]--;
            return *p;
        }
    }

    void push(int val, int ind){
        if (tops[ind]==NULL){
            tops[ind]=lbound[ind];
            *tops[ind]=val;
        }
        else if (tops[ind]!=ubound[ind]){
            tops[ind]++;
            *tops[ind]=val;
        }
    }

    int peak(int ind){
        if (tops[ind]==NULL) {
            return -1;
        }
        else {
            return *tops[ind];
        }

    }

};


int main(){

   Tristack ts;

   ts.push(0,0);
   ts.push(1,1);
   ts.push(2,2);
   ts.push(3,0);
   ts.push(4,1);
   ts.push(5,2);
   ts.push(6,0);
   ts.push(7,1);
   ts.push(8,2);

   cout << ts.peak(2) << endl;
   cout << ts.peak(1) << endl;
   cout << ts.peak(0) << endl;

   cout << ts.pop(2) << endl;
   cout << ts.pop(1) << endl;
   cout << ts.pop(0) << endl;

   cout << ts.pop(2) << endl;
   cout << ts.pop(1) << endl;
   cout << ts.pop(0) << endl;

   cout << ts.pop(2) << endl;
   cout << ts.pop(1) << endl;
   cout << ts.pop(0) << endl;

}
