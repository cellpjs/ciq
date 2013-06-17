/* two strings -> permuation? */
/* use sorting! */ 
#include <iostream>
#include <string>
#include <algorithm>

bool isPerm(std::string s, std::string t) {
    // is a permutation of b?
    if (s.size()!=t.size()) return false;
    else {
        sort(s.begin(),s.end());
        sort(t.begin(),t.end());
        if (s==t) return true;
        else return false;
    }
}

int main(){

    std::string a("abcdefg");
    std::string b("cdefgab");
    std::cout << isPerm(a,b) << std::endl;
    
}
