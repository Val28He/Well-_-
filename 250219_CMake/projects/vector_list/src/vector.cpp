#include "vector.hpp"

#include <iostream>

using biv::Vector;

template<typename T>
const std::size_t Vector<T>::START_CAPACITY = 1;

template<typename T>
Vector<T>::Vector() {
	arr = new T[START_CAPACITY]; 
    capacity = START_CAPACITY;
    size = 0; 
}

template<typename T>
Vector<T>::~Vector() {
	if (arr != nullptr) {
        delete[] arr;
    }
}

template<typename T>
std::size_t Vector<T>::get_size() const noexcept {
	return size;
}

template<typename T>
bool Vector<T>::has_item(const T& value) const noexcept {
	for (int i = 0; i < size; ++i){
		if (arr[i] == value){
			return true;
		} 
	}
	return false;
}

template<typename T>
bool Vector<T>::insert(const std::size_t position, const T& value) {
	if (position > size){
		return false;
	}
	if (size >= capacity){
		capacity = capacity * 2;
	}
	for (std::size_t i = size; i > position - 1; --i) {
		arr[i] = arr[i - 1];
	}
	arr[position - 1] = value;
	++size;
	return true;
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

template<typename T>
bool Vector<T>::remove_first(const T& value) {
	if (size != 0){
        size_t new_size = size - 1;                         
        T* result = new T[new_size];
        for (decltype(size) i = 1; i < size; ++i){                  
        	result[i-1] = arr[i];
		}
        delete[] arr;      
        arr = result;
		size = new_size;
		if (capacity > START_CAPACITY){
			capacity = capacity - 1;
		}
		return true;
	}
	return false;
}

/*int main(){
	Vector<int> vec;
	std::cout << "Remove first: " << vec.remove_first(2) << std::endl;
	std::cout << "Size: " << vec.get_size() << std::endl;
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(1);
	vec.print(); 
	std::cout << "Size: " << vec.get_size() << std::endl;
	std::cout << "Has item 4: " << vec.has_item(4) << std::endl;
	std::cout << "Has item 8: " << vec.has_item(8) << std::endl;
	std::cout << "Position 5 value 7: " << vec.insert(6, 7) << std::endl;
	std::cout << "Position 3 value 10: " << vec.insert(3, 10) << std::endl;
	vec.print();
	std::cout << "Remove first: " << vec.remove_first(2) << std::endl;
	vec.print();
	std::cout << "Size: " << vec.get_size() << std::endl;
	return 0;
}*/
