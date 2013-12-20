/* k-th largest element in an array */
#include <iostream>
#include <string>

inline void swap(int a[], int i, int j){
	int temp = a[i];
	a[i]=a[j];
	a[j]=temp;
}

int partition(int a[], int s, int t){
	int pivot_index = s+rand()%(t-s+1); // random pivot
	int pivot_element = a[pivot_index];
	swap(a, pivot_index, t); // move pivot to the end;
	int swap_index = s;
	int run_index = s;
	// invariant
	// s to swap_index-1 less than pivot
	// swap_index to run_index-1 greater than or equal to pivot
	while (run_index < t){
		if (a[run_index] < pivot_element){
			swap(a, run_index, swap_index);
			swap_index++;
		}
		run_index++;
	}
	swap(a, swap_index, t);
	return swap_index;
}

void quicksort(int a[], int s, int t){
	if (t-s<1) return;
	int p = partition(a,s,t);
	quicksort(a,s,p-1);
	quicksort(a,p+1,t);
}

// finds the k-th largest number (where 0-th is the largest)
// returned index does not correspond to the index in the original array
// since the array is modified in the process
int kthlargest(int a[], int s, int t, int k){
	int p = partition(a, s, t);
	if (p == t-k) return p;
	else if (p < t-k){
		return kthlargest(a, p+1, t, k);
	}
	else if (p > t-k){
		return kthlargest(a, s, p-1, k-t+p-1);
	}
}

int main(){

    const int N = 20;

    int a[N] = {5,40,35,18,1,7,30,25,37,8,14,17,34,27,28,38,3,22,9,11};
	/*
    int p = partition(a, 0, N-1);
    std::cout << "pivot = " << a[p] << std::endl;
    */
    //quicksort(a,0,N-1);

    for (int i=0; i<N; i++){
    	std::cout << a[i] << " ";
    }
    std::cout << std::endl;
	
    for (int k=0; k<N; k++){
    	int a[N] = {5,40,35,18,1,7,30,25,37,8,14,17,34,27,28,38,3,22,9,11};
    	int index = kthlargest(a, 0, N-1, k);
    	std::cout << k << "-th largest is " << a[index] << " at " << index << std::endl;
    }
}
