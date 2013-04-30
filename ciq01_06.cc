#include <iostream>
#include <string>

#define N 11

using namespace std;

void rotate(int a[][N]) {
    int qi, qj;
    if (N%2==0) {
        qi=N/2;
        qj=N/2;
    }
    else {
        qi=N/2+1;
        qj=N/2;
    }
    for (int i=0; i<qi; i++){
        for (int j=0; j<qj; j++){
            int temp=a[i][j];
            a[i][j]=a[N-1-j][i];
            a[N-1-j][i]=a[N-1-i][N-1-j];
            a[N-1-i][N-1-j]=a[j][N-1-i];
            a[j][N-1-i]=temp;
        }
    }
}

int main(){

    int image[N][N];
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            image[i][j]=rand()%10;
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    rotate(image);
    for (int i=0; i<N; i++){
        for (int j=0; j<N; j++){
            cout << image[i][j] << " ";
        }
        cout << endl;
    }
}
