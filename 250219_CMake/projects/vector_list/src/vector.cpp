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
		//создать новый массив
		T* temp = new T[capacity];
		//заполнить массив 
		for (std::size_t i = 0; i < position; ++i) {
			temp[i] = arr[i];
		}
		temp[position] = value;
		for (std::size_t i = position; i < size; ++i) {
			temp[i + 1] = arr[i];
		}
		++size;
		//удалить старый массив и присвоить ему всё новое 
		delete[] arr;
		arr = temp;
		return true;
	}
	else {
		++size;
		for (std::size_t i = size - 1; i >= position; --i){
			arr[i + 1] = arr[i];
		}
		arr[position] = value;
		return true;
	}
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
		//создать новый массив с capacity в два раза больше
        size_t new_capacity = capacity * 2;                 
        T* result = new T[new_capacity];
		//перенести информацию из старого массива в новый
        for (std::size_t i = 0; i < size; ++i){
            result[i] = arr[i];
		}
		//удалить старый массив и присвоить ему всё новое 
        delete[] arr; 
        arr = result;
        capacity = new_capacity;
    }
	arr[size++] = value;
}

template<typename T>
bool Vector<T>::remove_first(const T& value) {
	for (std::size_t i = 0; i < size; ++i){
		if (arr[i] == value){
			for (std::size_t j = i; j < size - 1; ++j){
				arr[j] = arr[j + 1];
			}
			--size;
			return true;
			break;
		}
	}
	return false;
}

/*int main(){
	Vector<int> vec;
	std::cout << "Remove first 2: " << vec.remove_first(2) << std::endl;
	std::cout << "Size: " << vec.get_size() << std::endl;
	vec.push_back(2);
	vec.print(); 
	std::cout << "Size: " << vec.get_size() << std::endl;
	vec.push_back(5);
	vec.print(); 
	std::cout << "Size: " << vec.get_size() << std::endl;
	vec.push_back(4);
	vec.print(); 
	std::cout << "Size: " << vec.get_size() << std::endl;
	vec.push_back(1);
	vec.print(); 
	std::cout << "Size: " << vec.get_size() << std::endl;
	std::cout << "Has item 4: " << vec.has_item(4) << std::endl;
	std::cout << "Has item 8: " << vec.has_item(8) << std::endl;
	std::cout << "Position 6 value 7: " << vec.insert(6, 7) << std::endl;
	std::cout << "Position 3 value 10: " << vec.insert(3, 10) << std::endl;;
	vec.print();
	std::cout << "Size: " << vec.get_size() << std::endl;
	std::cout << "Remove first 9: " << vec.remove_first(9) << std::endl;
	std::cout << "Remove first 5: " << vec.remove_first(5) << std::endl;
	vec.print();
	std::cout << "Size: " << vec.get_size() << std::endl;
	return 0;
}*/