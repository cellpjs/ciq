/* largest contiguous sum in an array (max subarray) */
#include <iostream>
#include <string>

int maxsubarray(int a[], int length, int* start, int* finish){
	/* allow zero length subarray? yes --> max >= 0 */
	int max_end = 0;
	int max_all = 0;
	int newstart;
	for (int i=0; i<length; i++){
		if (max_end + a[i] > 0) {
			max_end = max_end + a[i];
		}
		else {
			max_end = 0;
			newstart = i+1;
		}
		if (max_end > max_all){
			max_all = max_end;
			*start = newstart;
			*finish = i+1;
		}
	}
	return max_all;
}


int main(){

    const int N = 20;

    int a[N] = {5,-40,35,-18,-1,7,30,25,-37,8,-14,17,34,-27,28,38,-3,22,-9,-11};
	//int a[N] = {5,40,35,18,1,7,30,25,37,8,14,17,34,27,28,38,3,22,9,11};
	//int a[N] = {-5,-40,-35,-18,-1,-7,-30,-25,-37,-8,-14,-17,-34,-27,-28,-38,-3,-22,-9,-11};

    int start_index = 0;
    int finish_index = 0;
    int sum = maxsubarray(a, N, &start_index, &finish_index);
    // std::cout << start_index << ", " << finish_index << std::endl;
    for (int i=start_index; i<finish_index; i++){
    	std::cout << (a[i]>0? "+":"") << a[i];
    }
    std::cout << " = " << sum << std::endl;
}
