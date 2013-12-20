/* find pairs that sum to k in an array */
#include <iostream>
#include <algorithm>
#include <set>


void test(int a[]){
    std::cout << sizeof(a) << std::endl;
    // why we need to pass the length
}

/* following for sorted array */
void findsumpair_sorted(int a[], int length, int k){
    int i = 0;
    int j = length-1;
    while (i<j){
        if (a[i]+a[j]==k){
            std::cout << a[i] << " + " << a[j] << " = " << k << std::endl;
            i++;
        }
        else if (a[i]+a[j]>k){
            j--;
        }
        else if (a[i]+a[j]<k){
            i++;
        }
    }
}

void findsumpair(int a[], int length, int k){
    std::set<int> seen;
    for (int i=0; i<length; i++){
        if (seen.count(k-a[i])){
            std::cout << a[i] << " + " << k-a[i] << " = " << k << std::endl;
            seen.insert(a[i]);
        }
        else {
            seen.insert(a[i]);
        }
    }
}


int main(){

    const int N = 20;

    int a[N] = {5,40,35,18,1,7,30,37,8,14,17,34,27,28,38,3,22,9,11,25};

    findsumpair(a, N, 40);

    std::cout << std::endl;

    std::sort(a, a+N); // sort in place

    findsumpair_sorted(a, N, 40);

}
