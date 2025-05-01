#include "vector.hpp"

#include <iostream>

using biv::Vector;

template<typename T>
const std::size_t Vector<T>::START_CAPACITY = 10;

template<typename T>
Vector<T>::Vector() {
	arr = new T[size];
	capacity = START_CAPACITY;
}

template<typename T>
Vector<T>::~Vector() {
	if (arr != nullptr) {
        free(arr);
    }
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	std::size_t size;
	size = sizeof(arr)/sizeof(arr[0]);
	return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (int i; i < size; ++i){
		if (arr[i] == value){
			return true;
		} 
	}
	return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (arr[position] == value){
		return true;
	}
	return false;
}

template<typename T>
void Vector<T>::print() const noexcept {
	for (int i = 0; i < size; ++i){
		std::cout << arr[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
	if (size == capacity){
        size_t new_capacity = capacity * 2;                         //создать новый массив с capacity в 2 раза больше
        T* result = new T[new_capacity];
        for (decltype(size) i = 0; i < size; ++i){                  //перенести информацию из старого вектора в новый
            result[i] = arr[i];
		}
        delete[] arr;                                               //удалить старый вектор и присвоить ему всё новое
        arr = result;
        capacity = new_capacity;
    }
	arr[size++] = value;
}

/*template<typename T>
bool Vector<T>::remove_first(const T& value) {
	// TODO
}*/

int main(){
	Vector<int> vec;
	vec.push_back(2);
	vec.push_back(5);
	vec.print(); 
	return 0;
}
