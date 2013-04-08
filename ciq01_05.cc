#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string countpress(string s) {

    string cs = "";
    int count=1;
    for (string::iterator it=s.begin()+1; it!=s.end(); ++it){
        if (*it==*(it-1)) count++;
        else {
            cs = cs.append(*(it-1)+to_string(count));
            count=1;
        }
        if (it==s.end()-1) cs = cs.append(*it+to_string(count));
    }
    if (cs.size()<s.size()) return cs;
    else return cs;
}

int main(){

    string s("rrrrrr aaaaah eeeeeeek");
    cout << countpress(s) << endl;

}
