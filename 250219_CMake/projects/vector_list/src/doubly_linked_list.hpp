#pragma once

#include <cstddef>

namespace biv {
	template <typename T> 
	class DoublyLinkedList {
		private:
			class Node {
				public:
					T value;                       //весь список
					Node* prev = nullptr;          //указатель на предыдущий элемент списка
					Node* next = nullptr;          //указатель на следующий элемент списка
					
					Node(const T& value) : value(value) {}
						
					Node(const Node&) = delete; 
					Node& operator = (const Node&) = delete;
			};

			Node* begin = nullptr;                 //указатель на первый элемент списка
			Node* end = nullptr;                   //указатель на последний элемент списка

		public:
			DoublyLinkedList() noexcept {};
			DoublyLinkedList(const DoublyLinkedList&) = delete;
			DoublyLinkedList& operator = (const DoublyLinkedList&) = delete;
			~DoublyLinkedList();
			
			std::size_t get_size() const noexcept;
			bool has_item(const T& value) const noexcept;
			void print() const noexcept;
			void push_back(const T& value);
			bool remove_first(const T& value) noexcept;
	};
}
