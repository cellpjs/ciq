// binary representation of a number (double) between 0 and 1 (e.g. 0.125)
// (error if cannot represent accurately with 32 bits)  
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

string df2bits(double x){
    if (x>=1 || x<0) return "ERROR";
    if (x==0) return "0";
    // 0 < x < 1
    string s("0.");
    double d = 1./2.;
    for (int i=0; i<32; i++){
        if (x>=d){
            s.push_back('1');
            x=x-d;
        }
        else {
            s.push_back('0');
        }
        d=d/2.;
        if (x==0.0) break;
    }
    
    if (x!=0.0) {
        s.append(" (with error)");
    }
    
    return s;
}

int main(){
    double x;
    x = 0.125;
    cout << x << " = (binary) " << df2bits(x) << endl;
    x = 0.0;
    cout << x << " = (binary) " << df2bits(x) << endl;
    x = 1.0;
    cout << x << " = (binary) " << df2bits(x) << endl;
    x = 0.124;
    cout << x << " = (binary) " << df2bits(x) << endl;
    x = 1./2+1./8+1./64+1./1024;
    cout << x << " = (binary) " << df2bits(x) << endl;
}
