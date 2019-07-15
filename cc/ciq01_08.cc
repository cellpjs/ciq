/* find if a string is a rotation of another string */
/* concatenate one of the strings back to back */
/* and check if it contains the other string */
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
