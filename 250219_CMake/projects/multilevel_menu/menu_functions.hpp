#pragma once 
#include "menu.hpp"

namespace Mine {
	const MenuItem* exit(const MenuItem* current);          //объявление функций. Именно эти функции будут переданы в menu.cpp
	const MenuItem* read(const MenuItem* current);
	
	const MenuItem* pushkin(const MenuItem* current);
	const MenuItem* lermontov(const MenuItem* current);
	const MenuItem* krylov(const MenuItem* current);
	const MenuItem* main_menu(const MenuItem* current);
	
	const MenuItem* dubrovsky(const MenuItem* current);
	const MenuItem* evgeny_onegin(const MenuItem* current);
	const MenuItem* zimny_vecher(const MenuItem* current);
	const MenuItem* previous_menu(const MenuItem* current);
}
//здесь только объявление функции