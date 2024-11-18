#include<io.hpp>
#include<sort.hpp>

int main(){
	void biv::sortings::insertion_sort(int* const arr, const int size);
	void biv::print_array(const char* const comment, int* arr, const int size);
	
    int arr [] = {2,26,31,20,14,67,8};
	const int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	print_array("Массив до сортировки:", arr, arr_size);
    
    insertion_sort(arr, arr_size);

    print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}
