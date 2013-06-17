// given two 32-bit numbers
// insert M into N at bit positions i through j  
// N = 10000000000
// M =     10011
// R = 10001001100
// pos     6   2  (i=2, j=6)
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

int insertbits(int m, int n, int i, int j){
    if (i>j) return 0;
    // if m has more than j-i+1 bits?
    if (m>(1<<j-i+1)) {
        m = m & (1<<j-i+1)-1;
    }
    // shift m i bits to the left
    m = m << i;
    //cout << m << endl;
    //cout << i2bits(m) << endl;
    // m is ready now prepare n
    // clear bits i through j on n
    n = n & ~(((1<<(j-i+1))-1)<<i);
    //cout << n << endl;
    //cout << i2bits(n) << endl;
    // insert m into n
    n = n | m;
    return n;
}

int main(){
    
    int n = 1634573975;
    int m = 237463;
    int r = insertbits(m,n,5,22);
    cout << "n = " << n << " (" << i2bits(n) << ")" << endl;
    cout << "m = " << m << " (" << i2bits(m) << ")" << endl;
    cout << "r = " << r << " (" << i2bits(r) << ")" << endl;
    
    // "string literal must be in double quotes"
    n = bits2i("100100100100100100100100");
    m = bits2i("110110110110");
    r = insertbits(m,n,6,17);
    cout << "n = " << n << " (" << i2bits(n) << ")" << endl;
    cout << "m = " << m << " (" << i2bits(m) << ")" << endl;
    cout << "r = " << r << " (" << i2bits(r) << ")" << endl;
    
}
