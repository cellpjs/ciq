// number of bits required to convert integer a to b
// bit diff
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

int onebits(int k){
    if (k<0) return -1;
    int count = 0;
    while (k>0){
        if (k%2==1){
            count++;
        }
        k = k>>1;
    }
    return count;
}

int bitdiff(int a, int b){
    int c = a^b;
    return onebits(c);
}

int main(){
    
    int a = 31;
    int b = 14;
    cout << a << " (" << i2bits(a) << ")" << endl;
    cout << b << " (" << i2bits(b) << ")" << endl;
    cout << "bitdiff = " << bitdiff(a, b) << endl;
    
    a = 2679;
    b = 2371;
    cout << a << " (" << i2bits(a) << ")" << endl;
    cout << b << " (" << i2bits(b) << ")" << endl;
    cout << "bitdiff = " << bitdiff(a, b) << endl;
    
}
