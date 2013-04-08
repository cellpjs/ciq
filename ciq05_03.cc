#include <iostream>
#include <string>

using namespace std;

string i2bits(int k){
    string s;
    if (k<0) return NULL;
    if (k==0) return "0";
    while (k>0){
        if (k%2==1) {
            s.insert(0, "1");
        }
        else {
            s.insert(0, "0");
        }
        k = k>>1;
    }
    return s;
}

int bits2i(string s){
    int k = 0;
    int i = 0;
    for (string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); ++rit){
        if (*rit == '1' && i<32) {
            k += (1<<i);
        }
        else if (*rit != '0'){
            return -1;
        }
        i++;
    }
    return k;
}



void moveone(int k){
    if (k<=0) return;
    /* prints the next and the previous number with same number of 1 bits */
    
    /* strategy: to get the next/prev number,
       move one of the 1s near the lsb to the left/right */
    
    // next
    // starting from lsb, find the first 1 and set it to 0
    // from there, find the first 0 to the left and set it to 1
    int next = k;
    bool found = false;
    for (int i=0; i<32; i++){
        if (!found && (next & (1<<i))!=0){
            found = true;
            next = next & (~(1<<i));
        }
        else if (found && (next & (1<<i))==0){
            next = next | (1<<i);
            break;
        }
    }
    if (next<=k){
        cout << "next: none" << endl;
    }
    else {
        cout << "next: " << next << " (" << i2bits(next) << ")" << endl;
    }

    // prev
    // starting from lsb, find the first 0 and set it to 1
    // from there, find the first 1 to the left and set it to 0
    int prev = k;
    found = false;
    for (int i=0; i<32; i++){
        if (!found && (prev & (1<<i))==0){
            found = true;
            prev = prev | (1<<i);
        }
        else if (found && (prev & (1<<i))!=0){
            prev = prev & (~(1<<i));
            break;
        }
    }
    if (prev>=k){
        cout << "prev: none" << endl;
    }
    else {
        cout << "prev: " << prev << " (" << i2bits(prev) << ")" << endl;
    }
}

int main(){
    int k;
    k = 125;
    cout << "curr: " << k << " (" << i2bits(k) << ")" << endl;
    moveone(k);
    k = 1;
    cout << "curr: " << k << " (" << i2bits(k) << ")" << endl;
    moveone(k);
    k = 39279847;
    cout << "curr: " << k << " (" << i2bits(k) << ")" << endl;
    moveone(k);
    k = 222;
    cout << "curr: " << k << " (" << i2bits(k) << ")" << endl;
    moveone(k);
    k = 1+2+4+8+16;
    cout << "curr: " << k << " (" << i2bits(k) << ")" << endl;
    moveone(k);
    
}
