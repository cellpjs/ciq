#include <iostream>
#include <string>
#include <algorithm>

bool isPerm(std::string s, std::string t) {
    // is a permutation of b?
    if (s.size()!=t.size()) return false;
    else {
        std::string sorted_s=s;
        sort(sorted_s.begin(),sorted_s.end());
        std::string sorted_t=t;
        sort(sorted_t.begin(),sorted_t.end());
        if (sorted_s==sorted_t) return true;
        else return false;
    }
}

int main(){

    std::string a("abcdefg");
    std::string b("cdefgab");
    std::cout << isPerm(a,b) << std::endl;

}
