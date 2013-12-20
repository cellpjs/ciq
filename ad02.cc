/* find sum of numbers within a rectangular region of a matrix */
#include <iostream>
#include <string>
#include <iomanip>

#define height 20
#define width 20

void precompute(int a[][width], int b[][width]){
    for (int i=0;i<height;i++){
        for (int j=0; j<width; j++){
            if (i==0 && j==0) {
                b[i][j]=a[i][j];
            }
            else if (i==0 && j>0 ) {
                b[i][j]=b[i][j-1]+a[i][j];
            } 
            else if (i>0 && j==0) {
                b[i][j]=b[i-1][j]+a[i][j];
            }
            else if (i>0 && j>0) {
                b[i][j]=b[i][j-1]+b[i-1][j]-b[i-1][j-1]+a[i][j];
            }
        }
    }
} 

int findregionsum(int a[][width], std::pair<int,int> topleft, std::pair<int,int> bottomright){
    int sum = 0;
    for (int i=topleft.first; i<=bottomright.first; i++){
        for (int j=topleft.second; j<=bottomright.second; j++){
            sum=sum+a[i][j];
        }
    }    
    return sum;
}

int findregionsum2(int b[][width], std::pair<int,int> topleft, std::pair<int,int> bottomright){
    int sum = b[bottomright.first][bottomright.second];
    if (topleft.first>0) sum -= b[topleft.first-1][bottomright.second];
    if (topleft.second>0) sum -= b[bottomright.first][topleft.second-1];
    if (topleft.first>0 && topleft.second>0) sum += b[topleft.first-1][topleft.second-1];
    return sum;
}

int main(){

    int a[height][width];

    for (int i=0;i<height;i++){
        for (int j=0; j<width; j++){
            a[i][j]=rand()%100;
        }
    }

    for (int i=0;i<height;i++){
        for (int j=0; j<width; j++){
            std::cout << std::setw(3) << a[i][j];
        }
        std::cout << std::endl;
    }

    int b[height][width];
    precompute(a, b);

    for (int i=0;i<height;i++){
        for (int j=0; j<width; j++){
            std::cout << std::setw(6) << b[i][j];
        }
        std::cout << std::endl;
    }    

    std::pair<int,int> tl(0,0);
    std::pair<int,int> br(5,5);
    std::cout << " regionsum = " << findregionsum(a, tl, br) << std::endl;
    std::cout << " regionsum = " << findregionsum2(b, tl, br) << std::endl;
    
}
