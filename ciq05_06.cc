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


int eobitswap(int k){
    // 30-bit even mask 715827882 (101010101010101010101010101010)
    // 30-bit odd mask  357913941 (010101010101010101010101010101)
    
    return ((k & 715827882)>>1)|((k & 357913941)<<1);
    // using hexadecimal notation (a=1010, 5=0101)
    // return ((k & 0xaaaaaaaa)>>1)|((k & 0x55555555)<<1);
}

int main(){
    
    int a, b;
    
    a = 14692;
    cout << a << " (" << i2bits(a) << ")" << endl;
    
    b = eobitswap(a);
    cout << b << " (" << i2bits(b) << ")" << endl;

    a = bits2i("0110110010110100");
    cout << a << " (" << i2bits(a) << ")" << endl;
    
    b = eobitswap(a);
    cout << b << " (" << i2bits(b) << ")" << endl;
    
}
