#include <clocale>
#include <iostream>

#include "menu.hpp"
#include "menu_items.hpp"
#include "menu_functions.hpp"

int main(){
	std::setlocale(LC_ALL, "");

	const Mine::MenuItem* current = &Mine::MAIN;
	do{
		current = current->func(current); 
	} while (true);
	return 0;
}
