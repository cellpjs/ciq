/* determine if string has all unique characters */
#include <iostream>
#include <string>
#include <bitset>

class MyString {
    std::string s;

    public:
    MyString(std::string a): s(a) {}

    bool isUnique() {
        // assuming 8-bit char
        if (s.size()>256) return false;
        else{
            std::bitset<256> cflag;
            for (int i=0; i<s.size(); i++){
                int cval=(int)s[i];
                if (cflag[cval]) return false;
                else cflag.set(cval);
            }
        }
        return true;
    }
};

int main(){

    MyString s("abcdefghijklmnopqrstuvwxyz");

    std::cout << s.isUnique();

}
