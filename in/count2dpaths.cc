// NxM grid (chess board)
// count the number of paths from top-left to bottom-right
// can only move right or down
// some cells are blocked (traps or mines)

/* example

S000000000
0000000000
0000000000
0000100000
0000000000
0000000000
0000000000
0010000000
0000000000
000000000F

from S to F */

#include <iostream>
#include <string>

#define N 10
#define M 10

using namespace std;

int recpaths(int a[][M], int i, int j) {
    if (i==N-1 && j==M-1) return 1;
    int k = 0;
    if (j+1<M && a[i][j+1]!=1) k+=recpaths(a, i, j+1);
    if (i+1<N && a[i+1][j]!=1) k+=recpaths(a, i+1, j);
    return k;
}

int count2dpaths(int a[][M]){
    int k = recpaths(a, 0, 0);
    return k;
}

int main(){

    int a[N][M];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            a[i][j]=0;
        }
    }
    // lay traps
    a[3][4]=1;
    a[7][2]=1;
    // display board
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;

    int k = count2dpaths(a);
    
    cout << k << " paths" << endl;

}
