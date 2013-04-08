#include <iostream>
#include <string>

using namespace std;

bool isRotation(string a, string b){

    if (a.size()==b.size() && (b+b).find(a)!=string::npos) return true;
    else return false;

}


int main(){

    string s1="waterbottle";
    string s2="bottlewater";
    cout << isRotation(s1,s2) << endl;

}
