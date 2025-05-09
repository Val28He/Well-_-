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
	//prev указывает на предыдущий объект
	ptr->prev = end;
	//next ведет на добавляемый объект
	if (end != nullptr){
		end->next = ptr;                   
	}
	if (begin  == nullptr){
		begin = ptr;
	}
	end = ptr;
}

template<typename T>
bool DoublyLinkedList<T>::remove_first(const T& value) noexcept {
	for (Node* ptr = begin; ptr != nullptr; ptr = ptr->next){
		if (ptr->value == value){
			//если значение в начале
			if (ptr == begin){
				begin = ptr->next;
			}
			else{
				ptr->prev->next = ptr->next;
			}
			//если значение в конце
			if (ptr == end){
				end = ptr->prev;
			}
			else{
				ptr->next->prev = ptr->prev;
			}
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
 