/* generate all permuations of a string */ 
#include <iostream>
#include <string>
#include <vector>

using std::string;
using std::vector;
using std::cout;
using std::endl;

vector<string> allPerm(string s) {
    vector<string> perms;
    if (s.empty()) return perms;
    if (s.size()==1) {
        perms.push_back(s);
        return perms;
    }
    vector<string> subperms = allPerm(s.substr(1));
    for (vector<string>::iterator it=subperms.begin(); it!=subperms.end(); ++it){
        string sub = *it;
        for (int p = 0; p<sub.size()+1; p++){
            string fub(sub.size()+1, ' ');
            for (int i=0; i<sub.size()+1; i++){
                if (i<p) fub[i]=sub[i];
                if (i==p) fub[i]=s[0];
                if (i>p) fub[i]=sub[i-1];
            }
            perms.push_back(fub);
        }
    }
    return perms;
}

int main(){

    string a("kind");
    vector<string> perms = allPerm(a);
    cout << perms.size() << " permutations" << endl;
    for (vector<string>::iterator it=perms.begin(); it!=perms.end(); ++it){
        cout << *it << endl;
    }
}
