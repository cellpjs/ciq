#include <iostream>
#include <string>

std::string respace(std::string s) {

    while(1){
        std::string::size_type pos = s.find(' ');
        if (pos==std::string::npos) break;
        s.replace(pos,1,"%20");
    }
    return s;
}

int main(){

    std::string s("abcd efg hijk lmnop");
    std::cout << respace(s) << std::endl;

}
