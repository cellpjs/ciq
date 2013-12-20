/* find missing element in array2 which is a shuffled version of array1 with one element missing */
#include <iostream>
#include <string>

int findmissing(int array1[], int length, int array2[]){
	int missing;
	for (int i=0; i<length; i++){
		missing = missing ^ array1[i];
	}
	for (int i=0; i<length-1; i++){
		missing = missing ^ array2[i];
	}
	return missing;
}


int main(){

    const int N = 20;

    int array1[N] = {5,-40,35,-18,-1,7,30,25,-37,8,-14,17,34,-27,28,38,-3,22,-9,-11};

    int array2[N-1] = {-14,17,-18,-1,25,5,-40,35,7,30,8,38,-3,22,-9,-11,-37,34,-27};

    std::cout << "missing " << findmissing(array1, N, array2) << std::endl;

}
