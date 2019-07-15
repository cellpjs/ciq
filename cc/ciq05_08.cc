// monochrome bit pixel image
// array of bytes (each byte = 8 pixels)
// width w multiple of 8
// draw horizontal line from (x1,y) to (x2,y)
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <bitset>

using namespace std;

string i2bits(int k){
    string s;
    if (k<0) return NULL;
    if (k==0) return "0";
    while (k>0){
        if (k%2==1) {
            s.insert(0, "1");
        }
        else {
            s.insert(0, "0");
        }
        k = k>>1;
    }
    return s;
}

int bits2i(string s){
    int k = 0;
    int i = 0;
    for (string::reverse_iterator rit=s.rbegin(); rit!=s.rend(); ++rit){
        if (*rit == '1' && i<32) {
            k += (1<<i);
        }
        else if (*rit != '0'){
            return -1;
        }
        i++;
    }
    return k;
}

int onebits(int k){
    if (k<0) return -1;
    int count = 0;
    while (k>0){
        if (k%2==1){
            count++;
        }
        k = k>>1;
    }
    return count;
}

int bitdiff(int a, int b){
    int c = a^b;
    return onebits(c);
}

bool getbit(int k, int position){
    if (position < 0 || position >31) return false;
    return ((k & (1<<position))!=0);
}

string c2bits(char k){
    string s;
    for (int i=0; i<8; i++){
        if ((k&(1<<i))!=0) {
            s.insert(0, "1");
        }
        else {
            s.insert(0, "0");
        }
    }
    return s;
}

void printscreen(vector<char> &screen, int width){
    for (vector<char>::iterator it=screen.begin(); it!=screen.end(); ++it){
        cout << c2bits(*it);
        if ((it-screen.begin())%(width/8)==(width/8-1)) cout << endl;
    }
}

void DrawHorizontalLine(vector<char> &screen, int width, int x1, int x2, int y){
    // assume x1 < x2 and all parameters make sense
    // go to beginning of line y
    int line_head = y * width/8;
    int first_byte = line_head + x1/8;
    int last_byte = line_head + x2/8;
    // set all bytes between the first and last to 11111111
    for (int i = 1+first_byte; i<last_byte; i++){
        screen[i]=255;
    }
    char layer;
    // if line begins and ends within one byte
    if (first_byte == last_byte){
        layer = 0;
        for (int j=x1%8; j<=x2%8; j++){
            layer = layer | (128>>j);
        }
        screen[first_byte]=screen[first_byte]|layer;
    }
    else {
        // set bits in first byte
        layer = 0;
        for (int j = x1%8; j<8; j++){
            layer = layer | (128>>j);
        }
        screen[first_byte]=screen[first_byte]|layer;
        // set bits in last byte
        layer = 0;
        for (int j = 0; j<= x2%8; j++){
            layer = layer | (128>>j);
        }
        screen[last_byte]=screen[last_byte]|layer;
    }
}


int main(){
    
    int width = 128; // multiple of 8
    int height = 60;
    
    vector<char> screen(height*width/8);
    
    //printscreen(screen, width);
    
    DrawHorizontalLine(screen, width, 25, 100, 36);
    DrawHorizontalLine(screen, width, 5, 20, 0);
    
    printscreen(screen, width);

}
