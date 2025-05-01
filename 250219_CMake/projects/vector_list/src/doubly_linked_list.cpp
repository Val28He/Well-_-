#include "doubly_linked_list.hpp"

#include <iostream>

using biv::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	while (begin != NULL){
		delete[] end;
		end = end->next;
	}
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	std::size_t size = 0;
	for (Node* ptr = begin; ptr != NULL; ptr = ptr->next){
		size++;
	}
	return size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	for (Node* ptr = begin; ptr != NULL; ptr = ptr->next){
		if (ptr->value == value){
			return true;
		}
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	for (Node* ptr = begin; ptr != NULL; ptr = ptr->next){
		std::cout << ptr->value << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* ptr = new Node(value);
	ptr->prev = end;                                //prev указывает на предыдущий объект
	if (end != NULL){
		end->next = ptr;                           //next ведет на добавляемый объект
	}
	if (begin  == NULL){
		begin = ptr;
	}
	end = ptr;
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	if (begin != NULL){
		delete[] begin;
		begin = begin->next;
		return true;
	}
	return false;
}

/*int main(){
	DoublyLinkedList<int> vec;
	std::cout << "Remove first: " << vec.remove_first(2) << std::endl;
	std::cout << "Size: " << vec.get_size() << std::endl;
	vec.push_back(2);
	vec.push_back(5);
	vec.push_back(4);
	vec.push_back(7);
	vec.print(); 
	std::cout << "Size: " << vec.get_size() << std::endl;
	std::cout << "Has item 4: " << vec.has_item(4) << std::endl;
	std::cout << "Has item 8: " << vec.has_item(8) << std::endl;
	std::cout << "Remove first: " << vec.remove_first(2) << std::endl;
	vec.print();
	std::cout << "Size: " << vec.get_size() << std::endl;
	return 0;
}*/
 