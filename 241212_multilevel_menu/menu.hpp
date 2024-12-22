#pragma once

namespace Mine {
	struct MenuItem {              //структура чтобы собирать данные в кучу
		const char* const title;   //неизменяемый указатель на неизменяемые данные
		const MenuItem* (*func)(const MenuItem* current);//указатель на функцию (тип, имя (*func) и (), в () аргуметы. В аргументах текущие элементы меню
		
		const MenuItem* parent;      //объявление родителей, тоже возвратка
		
		const MenuItem* const *children;  //массив неизменяемых указателей, возвратка
		const int children_count;         //количество детей
		
	};
}