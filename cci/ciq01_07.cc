/* if a[i][j]=0 set row i and column j to all zero */ 
#include <iostream>
#include <string>

#define N 5
#define M 10

using namespace std;

void zeroOut(int a[][M]) {
    bool zrow[N]={false};
    bool zcol[M]={false};
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (a[i][j]==0) {
                zrow[i]=true;
                zcol[j]=true;
            }
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            if (zrow[i]||zcol[j]) {
            a[i][j]=0;
            }
        }
    }
}

int main(){

    int a[N][M];
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            a[i][j]=rand()%10;
        }
    }
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    zeroOut(a);
    for (int i=0; i<N; i++){
        for (int j=0; j<M; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}
