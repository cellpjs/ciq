/* find next higher number with same digits */ 
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

string i2digits(int k){
    if (k<0) return NULL;
    if (k==0) return "0";
    string s;
    while (k>0){
        std::stringstream ss;
        ss << k%10;
        s.insert(0,ss.str());
        k = k/10;
    }
    return s;
}

int digits2i(string s){
    if (s.empty()) return 0;
    int k = 0;
    int p = 1;
    int length = s.size();
    for (int i=0; i<length; i++){
        k = k + (s[length-1-i]-'0')*p;
        p = p*10;
    }
    return k;
}

int digitsnext(int k){
    string s = i2digits(k);
    int i = s.size()-1;
    while (i>0 && s[i-1]>=s[i]) i--;
    if (i==0) return k; // k is maximum possible
    // first i such that s[i-1]<s[i]
    // replace s[i-1] with something bigger
    // make s[i:] smallest possible (sort ascend)
    int j = i;
    while (s[i-1]<s[j]) j++;
    j--;
    // s[j] just bigger than s[i-1] 
    char temp = s[i-1];
    s[i-1]=s[j]; // this is where the number gets bumped up
    s[j] = temp;
    std::sort(s.begin()+i, s.end()); // or reverse
    return digits2i(s);
}


int main(){

    //cout << i2digits(1234) << endl;
    //cout << digits2i("1234") << endl;
    
    cout << digitsnext(346754321) << endl;
    
}
