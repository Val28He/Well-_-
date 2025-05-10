#include "doubly_linked_list.hpp"

#include <iostream>

using biv::DoublyLinkedList;

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
	Node* ptr = begin;
	while (ptr != nullptr){
		Node* next = ptr->next;
		delete ptr;
		ptr = next; 
	}
}

template<typename T>
std::size_t DoublyLinkedList<T>::get_size() const noexcept {
	std::size_t size = 0;
	for (Node* ptr = begin; ptr != nullptr; ptr = ptr->next){
		++size;
	}
	return size;
}

template<typename T>
bool DoublyLinkedList<T>::has_item(const T& value) const noexcept {
	for (Node* ptr = begin; ptr != nullptr; ptr = ptr->next){
		if (ptr->value == value){
			return true;
		}
	}
	return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const noexcept {
	for (Node* ptr = begin; ptr != nullptr; ptr = ptr->next){
		std::cout << ptr->value << " ";
	}
	std::cout << std::endl;
}

template<typename T>
void DoublyLinkedList<T>::push_back(const T& value) {
	Node* ptr = new Node(value);

	if (begin == nullptr) {
		begin = end = ptr;
	} else {
		ptr->prev = end;
		end->next = ptr;
		end = ptr;
	}
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	Node *found = nullptr;
	for (Node* ptr = begin; ptr != nullptr; ptr = ptr->next) {
		if (ptr->value == value) {
			if (ptr == begin) {
				if (begin->next == nullptr){
					begin = nullptr;
					end = nullptr;
				} 
				else {
					begin = ptr->next;
					ptr->next->prev = nullptr;
				}
			} else if (ptr == end) {
				end = ptr->prev;
				ptr->prev->next = nullptr;
			} else {
				ptr->prev->next = ptr->next;
				ptr->next->prev = ptr->prev;
			}
			delete ptr;
			return true;
			break;
		}
	}
	return false;
}


/*int main(){
	DoublyLinkedList<int> vec;
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
	vec.push_back(7);
	vec.print(); 
	std::cout << "Size: " << vec.get_size() << std::endl;
	std::cout << "Has item 4: " << vec.has_item(4) << std::endl;
	std::cout << "Has item 8: " << vec.has_item(8) << std::endl;
	vec.print(); 
	std::cout << "Remove first 10: " << vec.remove_first(10) << std::endl;
	std::cout << "Remove first 5: " << vec.remove_first(5) << std::endl;
	vec.print();
	std::cout << "Size: " << vec.get_size() << std::endl;
	return 0;
}*/
 