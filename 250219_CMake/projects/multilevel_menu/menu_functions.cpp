#include <cstdlib>
#include <iostream>

#include "menu_functions.hpp"

const Mine::MenuItem* Mine::exit(const MenuItem* current) {
	std::exit(0);
}

const Mine::MenuItem* Mine::read(const MenuItem* current){
	for (int i = 1; i < current->children_count; ++i){
		std::cout << current->children[i]->title << std::endl;	           //-> - доступ к методам структуры 
	}
	std::cout << current->children[0]->title << std::endl;
	
	int user_input;
	std::cin >> user_input;
	std::cout << std::endl;
	return current->children[user_input];   //возвращаем детей
}

const Mine::MenuItem* Mine::pushkin(const MenuItem* current){
	for (int i = 1; i < current->children_count; ++i){
		std::cout << current->children[i]->title << std::endl;	           //-> - доступ к методам структуры 
	}
	std::cout << current->children[0]->title << std::endl;
	
	int user_input;
	std::cin >> user_input;
	std::cout << std::endl;
	return current->children[user_input];   //возвращаем детей
}

const Mine::MenuItem* Mine::lermontov(const MenuItem* current){
	std::cout << current->title << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const Mine::MenuItem* Mine::krylov(const MenuItem* current){
	std::cout << current->title << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const Mine::MenuItem* Mine::main_menu(const MenuItem* current){
	std::cout << current->title << std::endl;
	std::cout << std::endl;
	return current->parent->parent;
}

const Mine::MenuItem* Mine::dubrovsky(const MenuItem* current){
	std::cout << current->title << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const Mine::MenuItem* Mine::evgeny_onegin(const MenuItem* current){
	std::cout << current->title << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const Mine::MenuItem* Mine::zimny_vecher(const MenuItem* current){
	std::cout << current->title << std::endl;
	std::cout << std::endl;
	return current->parent;
}

const Mine::MenuItem* Mine::previous_menu(const MenuItem* current){
	std::cout << current->title << std::endl;
	std::cout << std::endl;
	return current->parent->parent;
}
//тут уже пошли реализации функций 