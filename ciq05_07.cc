// integers 0 .. n
// one missing
// find the missing number
// using fetch bit operations
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

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

int findmissing(vector<int> v){
    /* using xor */
    int n = v.size(); // range [0..n] - (one missing)
    int check = 0;
    for (int i=0; i<=n; i++){
        check = check^i;
    }
    int missing = check;
    for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it){
        missing = missing^(*it);
    }
    return missing;
}

bool getbit(int k, int position){
    if (position < 0 || position >31) return false;
    return ((k & (1<<position))!=0);
}

int findmissing_b(vector<int> v){
    /* using getbit */
    int n = v.size(); // range [0..n] - (one missing)
    int num_bits = (int)ceil(log(n)/log(2));
    
    bool *w = new bool[num_bits];
    
    for (int j=0; j<num_bits; j++){
        w[j]=false;
    }
    for (int i=0; i<=n; i++){
        for (int j=0; j<num_bits; j++){
            w[j]=w[j]^getbit(i,j);
        }
    }
    for (vector<int>::iterator it=v.begin(); it!=v.end(); ++it){
        for (int j=0; j<num_bits; j++){
            w[j]=w[j]^getbit(*it,j);
        }
    }
    int missing = 0;
    for (int j=0; j<num_bits; j++){
        missing += w[j]*(1<<j);
    }
    delete [] w;
    return missing;
}

int main(){
 
    int n=100;
    int missing = 68;
    
    cout << "range = 0.." << n << endl;
    cout << "missing = " << missing << endl;
    
    vector<int> a(n);
    int j=0;
    for (int i=0; i<n; i++){
        if (j==missing) j++;
        a[i]=j;
        j++;
    }
    
    random_shuffle(a.begin(), a.end());
    
    for (vector<int>::iterator it=a.begin(); it!=a.end(); ++it){
        cout << *it << " ";
    }
    cout << endl;
    
    
    int answer = findmissing_b(a);
    
    cout << "The missing number is " << answer << endl;
    
}
