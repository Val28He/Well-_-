#include "doubly_linked_list.hpp"

#include <iostream>

using biv::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	while (begin != NULL){
		delete[] end;
		end = end -> next;
	}
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	std::size_t size;
	while (begin != NULL){
		size ++;
		begin = begin -> next;
	}
	return size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	for (auto i = begin; i < end; ++i){
		if (*i == value){
			return true;
		}
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	while (begin != NULL){
		std::cout << begin -> value << " ";
		begin = begin->next;
	}
	std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	prev = end;                                     //prev указывает на предыдущий объект
	if (end != NULL){
		end -> next = value;                                 //next ведет на добавляемый объект
	}
	if (begin == NULL){
		begin = new Node(value);
	}
	end = new Node(value);
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	// TODO
}

int main(){
	DoublyLinkedList<int> vec;
	vec.push_back(2);
	vec.push_back(5);
	vec.print();
	return 0;
}
