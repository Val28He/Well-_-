#include<sort.hpp>

void biv::sortings::insertion_sort(int* const arr, const int size){
	for(int i=1;i<size;i++){  
		for(int j=i;j>0;j--){
			if (arr[j-1]>arr[j]){
				std::swap(arr[j-1],arr[j]);
			}
		}
	}
}