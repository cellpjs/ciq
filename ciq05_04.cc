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

int main(){
    
    for (int n=1; n<=16; n++){
        int k = n & (n-1);
        cout << i2bits(n) << " & " << i2bits(n-1) << " = " << i2bits(k) << endl;
    }
    
    for (int n=0; n<1000; n++){
        int k = n & (n-1);
        if (k==0) {
            cout << n << " " << k << endl;
        }
    }
    
    
}
