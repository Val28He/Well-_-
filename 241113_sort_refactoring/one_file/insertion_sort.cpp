#include <iostream>

int main(){
	void insertion_sort(int* const arr, const int size);
	void print_array(const char* const comment, int* arr, const int size);
	
    int arr [] = {2,26,31,20,14,67,8};
	const int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	print_array("Массив до сортировки:", arr, arr_size);
    
    insertion_sort(arr, arr_size);

    print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}

void insertion_sort(int* const arr, const int size){
	for(int i=1;i<size;i++){  
		for(int j=i;j>0;j--){
			if (arr[j-1]>arr[j]){
				std::swap(arr[j-1],arr[j]);
			}
		}
	}
}
void print_array(const char* const comment, int* arr, const int size){
	const char format = ' ';
	std::cout << comment;
	for (int i = 0; i < size; i++) {
		std::cout << format << arr[i];
	}
	std::cout << std::endl;
}