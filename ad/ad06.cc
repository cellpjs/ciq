/* two strings -> shuffle (interleave) -> third string? */
#include <iostream>
#include <string>

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

bool isShuffle(std::string s, std::string t, std::string u) {
    // is u a shuffle of s and t ?
    if (u.size()!=s.size()+t.size()) return false;
    if (!isPerm(s+t, u)) return false;
    // does not use up characters in u (allows reuse) --> false positives
    // check if u is a permutation of s+t --> prevents false positives
    size_t pos;
    int prev;
    prev = -1;
    for (std::string::iterator it=s.begin(); it!=s.end(); ++it){
        pos = u.find(*it, prev+1);
        if (pos == std::string::npos) return false;
        prev = pos;
    }
    prev = -1;
    for (std::string::iterator it=t.begin(); it!=t.end(); ++it){
        pos = u.find(*it, prev+1);
        if (pos == std::string::npos) return false;
        prev = pos;
    }
    return true;
}

bool isShuffle_re(std::string s, std::string t, std::string u) {
    // is u a shuffle of s and t ?
    std::cout << s << " " << t << " " << u << std::endl;
    if (u.size()!=s.size()+t.size()) return false;
    if (s.empty()||t.empty()){
        if (s+t==u) return true;
        else return false;
    }
    if (s[0]!=u[0] && t[0]!=u[0]) return false;
    if (s[0]==u[0] && t[0]!=u[0]) return isShuffle_re(s.substr(1), t, u.substr(1));
    if (s[0]!=u[0] && t[0]==u[0]) return isShuffle_re(s, t.substr(1), u.substr(1));
    if (s[0]==u[0] && t[0]==u[0]) {
        return (isShuffle_re(s.substr(1), t, u.substr(1)) || 
                isShuffle_re(s, t.substr(1), u.substr(1)));
    }
}


int main(){

    std::string a("interesting");
    std::string b("terrestrial");
    std::string c("iternterreesstrtiingal");
    //std::cout << isShuffle(a,b,c) << std::endl;
    std::cout << isShuffle_re(a,b,c) << std::endl;
}
