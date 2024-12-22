#include "menu_items.hpp"
#include "menu_functions.hpp"

//третий уровень
const Mine::MenuItem Mine::DUBROVSKY = {
	"1 - Дубровский", Mine::dubrovsky, &Mine::PUSHKIN
};

const Mine::MenuItem Mine::EVGENY_ONEGIN = {
	"2 - Евгений Онегин", Mine::evgeny_onegin, &Mine::PUSHKIN
};

const Mine::MenuItem Mine::ZIMNY_VECHER = {
	"3 - Зимний вечер", Mine::zimny_vecher, &Mine::PUSHKIN
};

const Mine::MenuItem Mine::PREVIOUS_MENU = {
	"0 - Выйти в главное меню", Mine::previous_menu, &Mine::PUSHKIN
};

namespace {
	const Mine::MenuItem* const pushkin_children[] = {&Mine::PREVIOUS_MENU, &Mine::DUBROVSKY, &Mine::EVGENY_ONEGIN, &Mine::ZIMNY_VECHER};
	const int pushkin_size = sizeof(pushkin_children) / sizeof(pushkin_children[0]);
}

//второй уровень
const Mine::MenuItem Mine::PUSHKIN = {
	"1 - Читать Пушкина", Mine::pushkin, &Mine::READ, pushkin_children, pushkin_size
};

const Mine::MenuItem Mine::LERMONTOV = {
	"2 - Читать Лермонтова", Mine::lermontov, &Mine::READ
};

const Mine::MenuItem Mine::KRYLOV = {
	"3 - Читать Крылова", Mine::krylov, &Mine::READ
};

const Mine::MenuItem Mine::MAIN_MENU = {
	"0 - Выйти в главное меню", Mine::main_menu, &Mine::READ
};

namespace {                                                                            //анонимное пространство имён
	const Mine::MenuItem* const read_children[] = {&Mine::MAIN_MENU, &Mine::PUSHKIN, &Mine::LERMONTOV, &Mine::KRYLOV};
	const int read_size = sizeof(read_children) / sizeof(read_children[0]);
}

//первый уровень 
const Mine::MenuItem Mine::READ = {
	"1 - Русские писатели", Mine::read, &Mine::MAIN, read_children, read_size
};

const Mine::MenuItem Mine::EXIT = {
	"0 - Завершить чтение", Mine::exit, &Mine::MAIN
};

namespace {
	const Mine::MenuItem* const main_children[] = {&Mine::EXIT, &Mine::READ};  						  //кладём элементы в массив указателей
	const int main_size = sizeof(main_children) / sizeof(main_children[0]);   			  //вычисление размера массива 
}

//начало
const Mine::MenuItem Mine::MAIN = {
	nullptr, Mine::read, nullptr, main_children, main_size
};