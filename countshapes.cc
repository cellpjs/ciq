// NxM binary image 
// count the number of shapes (connected components)
// a shape is made up of vertically or horizontally connected 1's
// diagonally touching 1's are not considered connected
#include <iostream>
#include <string>

#define N 10
#define M 15

using namespace std;

int findshape(int a[][M], int d[][M], int i, int j) {
    cout << "*";
    if (a[i][j]==1 && d[i][j]==0){
        // found a pixel in current shape
        d[i][j]=1; // mark pixel as visited
        // following recursive calls will mark all pixels within the shape
        // return values are not used for recursive calls
        if (j+1<M) findshape(a, d, i, j+1);
        if (i+1<N) findshape(a, d, i+1, j);
        if (j-1>=0) findshape(a, d, i, j-1);
        if (i-1>=0) findshape(a, d, i-1, j);
        return 1;
    }
    else return 0;
}

int countshapes(int a[][M]){
    int k = 0;
    int d[N][M]={0};
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            k = k + findshape(a, d, i, j);
        }
    }
    return k;
}

int main(){

    int a[N][M];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            a[i][j]=rand()%2;
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cout << a[i][j];
        }
        cout << endl;
    }
    cout << endl;

    int k = countshapes(a);

    cout << k << (k>1? " shapes":" shape") << " found" << endl;

}
