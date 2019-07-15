/* reverse a null-terminated string (c-string) */
#include <iostream>
#include <cstring>

void reverse(char* str){
    char* end=str;
    while(*end) end++;
    end--;
    char temp;
    while(str<end){
        temp=*str;
        *str++=*end;
        *end--=temp;
    }
}

int main(){

    char s[]="supercalifragilisticexpialidocious";
    std::cout << strlen(s) << std::endl;
    std::cout << s << std::endl;
    reverse(s);
    std::cout << s << std::endl;

}
