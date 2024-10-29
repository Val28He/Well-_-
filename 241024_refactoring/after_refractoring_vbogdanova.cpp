#include <algorithm>
#include <cmath>
#include <iostream>

void print_array(const char* const int arr_size, const int* const arr);

int main(){
	const int arr_size = 20;
	int arr[arr_size];
	for (int i = 0; i < arr_size; i++){
        arr[i] = rand() % arr_size;
    }
	
	print_array("Был сгенерирован массив:", arr, arr_size);

    
	for (i = 0; i < arr_size / 2; i++){
        int temp = arr[i];
        arr[i] = arr[arr_size - 1 - i];
        arr[arr_size - 1 - i] = temp;
    }
	
	print_array("Массив после обработки:", arr, arr_size);

	
    delete[] arr;
}

void print_array(const char* const int arr_size, const int* const arr);
	const char format = ' ';
	for (i = 0; i < arr_size; i++){
        std::cout << arr[i];
        std::cout << format;
    }
	std::cout << std::endl;
}
