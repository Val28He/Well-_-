#include "io.hpp"
#include "sort.hpp"

int main() {
    int arr [] = {2,26,31,20,14,67,8};
	const int arr_size = sizeof(arr)/sizeof(arr[0]);
	
	biv::print_array("Массив до сортировки:", arr, arr_size);
    
    biv::sortings::insertion_sort(arr, arr_size);

    biv::print_array("Массив после сортировки:", arr, arr_size);

    return 0;
}
