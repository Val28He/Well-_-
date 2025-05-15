#include <cmath>
#include <cstring>
#include <iostream>
#include "long_number.hpp"

using biv::LongNumber;

//КПоУ
LongNumber::LongNumber() : length(1), sign(1) {
	numbers = new int[length];
	numbers[0] = 0;
}

//К с параметрами
LongNumber::LongNumber(const char* const str) {
	int str_length = std::strlen(str);
	if (str[0] == '-'){
		sign = -1;
		length = str_length - 1;
	}
	else {
		sign = 1;
		length = str_length;
	}
	numbers = new int[length];
	for (int i = 0; i < length; ++i){
		numbers[i] = str[str_length - i - 1] - '0';
	}
}

//КК
LongNumber::LongNumber(const LongNumber& x) {
	length = x.length;
	sign = x.sign;
	numbers = new int[length];
	for (int i = 0; i < length; ++i){
		numbers[i] = x.numbers[i];
	}
}

//КП
LongNumber::LongNumber(LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	numbers = x.numbers;
	x.numbers = nullptr;
}

//Деструктор
LongNumber::~LongNumber() {
	if (numbers != nullptr) {
        free(numbers);
    }
}

//Оператор присваивания
//Делает массив из строки
LongNumber& LongNumber::operator = (const char* const str) {
	int str_length = std::strlen(str);
	if (str[0] == '-'){
		sign = -1;
		length = str_length - 1;
	}
	else {
		sign = 1;
		length = str_length;
	}
	delete [] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; ++i){
		numbers[i] = str[str_length - i - 1] - '0';
	}
	return *this;
}

//ОПК
LongNumber& LongNumber::operator = (const LongNumber& x) {
	if(this == &x) return *this;
	
	length = x.length;
	sign = x.sign;
	
	delete [] numbers;
	numbers = new int[length];
	for (int i = 0; i < length; ++i){
		numbers[i] = x.numbers[i];
	}
	
	return *this;
}

//ОПП
LongNumber& LongNumber::operator = (LongNumber&& x) {
	length = x.length;
	sign = x.sign;
	
	delete [] numbers;
	numbers = x.numbers;
	x.numbers = nullptr;
	
	return *this;
}

bool LongNumber::operator == (const LongNumber& x) const {
	if (sign != x.sign){
		return false;
	}
	if (length != x.length){
		return false;
	}
	for (int i = 0; i < length; ++i){
		if (numbers[i] != x.numbers[i]){
			return false;
		}
	}
	return true;
}

bool LongNumber::operator != (const LongNumber& x) const {
	if (sign != x.sign){
		return true;
	}
	if (length != x.length){ 
		return true;
	}
	for (int i = 0; i < length; ++i){
		if (numbers[i] != x.numbers[i]){
			return true;
		}
	}
	return false;
}

bool LongNumber::operator > (const LongNumber& x) const {
	if (sign < x.sign){
		return false;
	}
	if (length < x.length){
		return false;
	}
	if (length > x.length){
		return true;
	}
	else {
		for (int i = length - 1; i >= 0; --i){
			if (numbers[i] <= x.numbers[i]){
				return false;
			}
		}
		return true;
	}
}

bool LongNumber::operator < (const LongNumber& x) const {
	if (sign > x.sign){
		return false;
	}
	if (length > x.length){
		return false;
	}
	if (length < x.length){
		return true;
	}
	else {
		for (int i = length - 1; i >= 0; --i){
			if (numbers[i] >= x.numbers[i]){
				return false;
			}
		}
		return true;
	}
}

int compare(int *numbersA, int lengthA, int *numbersB, int lengthB){
	if (lengthA > lengthB){
		return 1;
	}
	else if (lengthA < lengthB){
		return -1;
	}
	else {
		for (int i = lengthA - 1; i >= 0; --i){
			if (numbersA[i] > numbersB[i]){
				return 1;
			}
			else if (numbersA[i] < numbersB[i]){
				return -1;
			}
		}
	}
	return 0;
}

void plus(int *numbersA, int lengthA, int *numbersB, int lengthB, int **numbersResult, int *lengthResult){
	int resultLength;
	int* resultNumbers;
	
	int maxLength;
	int minLength;
	int* maxNumbers;
	int* minNumbers;
	
	if (lengthA >= lengthB){
		maxLength = lengthA;
		minLength = lengthB;
		maxNumbers = numbersA;
		minNumbers = numbersB;
	}
	else {
		maxLength = lengthB;
		minLength = lengthA;
		maxNumbers = numbersB;
		minNumbers = numbersA;
	}

	resultNumbers = new int[maxLength + 1];

	int transition = 0;
	for (int i = 0; i < minLength; ++i){
		int sum = maxNumbers[i] + minNumbers[i] + transition;
		resultNumbers[i] = sum % 10;
		transition = sum / 10;
	}

	for (int i = minLength; i < maxLength; ++i){
		int sum = maxNumbers[i] + transition;
		resultNumbers[i] = sum % 10;
		transition = sum / 10;
	}

	resultLength = maxLength;
	if (transition > 0) {
		resultNumbers[resultLength] = transition;
		++resultLength;
	}

	*numbersResult = resultNumbers;
	*lengthResult = resultLength;
}

void minus(int *numbersA, int lengthA, int *numbersB, int lengthB, int **numbersResult, int *lengthResult){
	int resultLength;
	int* resultNumbers;

	int maxLength;
	int minLength;
	int* maxNumbers;
	int* minNumbers;
	
	maxLength = lengthA;
	minLength = lengthB;
	maxNumbers = numbersA;
	minNumbers = numbersB;

	resultNumbers = new int[maxLength];

	int transition = 0;
	for (int i = 0; i < minLength; ++i){
  		resultNumbers[i] = maxNumbers[i] - minNumbers[i] - transition;
  		if (resultNumbers[i] < 0) {
    		transition = 1;
    		resultNumbers[i] += 10;
  		} 
		else {
     		transition = 0;
  		}
	}

	for (int i = minLength; i < maxLength; ++i){
  		resultNumbers[i] = maxNumbers[i] - transition;
  		if (resultNumbers[i] < 0) {
    		transition = 1;
    		resultNumbers[i] += 10;
  		} 
		else {
     		transition = 0;
  		}
	}

	resultLength = maxLength;
	if (resultNumbers[resultLength - 1] == 0) {
		--resultLength;
	}

	*numbersResult = resultNumbers;
	*lengthResult = resultLength;
}

LongNumber LongNumber::operator + (const LongNumber& x) const { 
	int resultSign;
	int resultLength;
	int* resultNumbers;

	if (sign == x.sign){
		resultSign = sign;
		plus(numbers, length, x.numbers, x.length, &resultNumbers, &resultLength);
	}
	else {
		int cmp = compare(numbers, length, x.numbers, x.length);
		if (cmp > 0){
			resultSign = sign;
			minus(numbers, length, x.numbers, x.length, &resultNumbers, &resultLength);
		}
		else if (cmp < 0){
			resultSign = x.sign;
			minus(x.numbers, x.length, numbers, length, &resultNumbers, &resultLength);
		}
		else {
			return LongNumber("0");
		}
	}

	LongNumber result;
	result.numbers = resultNumbers;
	result.length = resultLength;
	result.sign = resultSign;
	return result;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	int resultSign;
	int resultLength;
	int* resultNumbers;

	if (sign != x.sign){
		resultSign = sign;
		plus(numbers, length, x.numbers, x.length, &resultNumbers, &resultLength);
	}
	else {
		int cmp = compare(numbers, length, x.numbers, x.length);
		if (cmp > 0){
			resultSign = sign;
			minus(numbers, length, x.numbers, x.length, &resultNumbers, &resultLength);
		}
		else if (cmp < 0){
			resultSign = -x.sign;
			minus(x.numbers, x.length, numbers, length, &resultNumbers, &resultLength);
		}
		else {
			return LongNumber("0");
		}
	}

	LongNumber result;
	result.numbers = resultNumbers;
	result.length = resultLength;
	result.sign = resultSign;
	return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	if ((*this == LongNumber("0")) or (x == LongNumber("0"))){
		return LongNumber("0");
	}

	int resultSign;
	int resultLength;
	int* resultNumbers;

	if (sign == x.sign){
		resultSign = 1;
	}
	else {
		resultSign = -1;
	}

	int maxLength;
	int minLength;
	int* maxNumbers;
	int* minNumbers;
	
	if (length >= x.length){
		maxLength = length;
		minLength = x.length;
		maxNumbers = numbers;
		minNumbers = x.numbers;
	}
	else {
		maxLength = x.length;
		minLength = length;
		maxNumbers = x.numbers;
		minNumbers = numbers;
	}

	resultLength = maxLength * 2;
	resultNumbers = new int[resultLength]();

	//Я НЕ БУДУ ЭТО ТРОГАТЬ РАДИ КАКОЙ-ТО ТАМ ОПТИМИЗАЦИИ, ОНО РАБОТАЕТ И СЛАВА БОГУ	
	for (int i = 0; i < minLength; ++i){
		for (int j = 0; j < maxLength; ++j){
			resultNumbers[j + i] = resultNumbers[j + i] + (maxNumbers[j] * minNumbers[i])% 10;
			if (resultNumbers[j + i] < 10){
				resultNumbers[j + i + 1] = resultNumbers[j + i + 1] + (maxNumbers[j] * minNumbers[i])/ 10;
			}
			else {
				resultNumbers[j + i + 1] = (resultNumbers[j + i])/10 + resultNumbers[j + i + 1] + (maxNumbers[j] * minNumbers[i])/ 10;
				resultNumbers[j + i] = (resultNumbers[j + i])%10;
			}
		}
	}

	int i = resultLength - 1;
	while (resultNumbers[i] == 0){
		--resultLength;
		--i;
	}

	LongNumber result;
	result.numbers = resultNumbers;
	result.length = resultLength;
	result.sign = resultSign;
	return result;
}

//Тут деление, но оно не работает
/*LongNumber LongNumber::operator / (const LongNumber& x) const {
	if (x == LongNumber("1"))
		return LongNumber(*this);

	LongNumber one(*this);  
	LongNumber two(x);		  
	int resultSign;
	int* result = nullptr;
	if (one.sign == two.sign){
		resultSign = 1;
	}
	else{
		resultSign = -1;
	}
	int minLength = 0;
	int maxLength = 0;
	int* Divisible = nullptr;
	int* Devider = nullptr;
	if (one.length > two.length){
		minLength = two.length;
		maxLength = one.length;
		Divisible = one.numbers;
		Devider = two.numbers;
	}
	else {
		minLength = one.length;
		maxLength = two.length;
		Divisible = two.numbers;
		Devider = one.numbers;
	}
	// Деление
	const int max_result_lenght = maxLength - minLength + 1;  

	for (int powOf10 = max_result_lenght - 1; powOf10 >= 0; powOf10--) {
		for (int k = 0; k < 10; k++) {
			LongNumber k_Devider_powOf10 = (Devider * (k) * LongNumber::pow(LongNumber("10"), powOf10));
			LongNumber kp1_Devider_powOf10 = (Devider * (k+1) * LongNumber::pow(LongNumber("10"), powOf10));

			if ((Divisible - kp1_Devider_powOf10) < LongNumber("0")) {
				result[max_result_lenght - powOf10 - 1] = k;
				Divisible = Divisible - k_Devider_powOf10;
				break;
			}
		}
	}
	int resultLength = sizeof(result)/sizeof(result[0]);
	LongNumber resultReturn = LongNumber(result, resultLength, resultSign);
	return resultReturn;
}

LongNumber LongNumber::operator % (const LongNumber& x) const {
	LongNumber resultReturn = (*this - ((*this / x) * x));
	if (resultReturn.is_negative())	{
		if (x.is_negative())
			resultReturn = resultReturn + (x * (-1));
		else
			resultReturn = resultReturn + x;
	}
	return resultReturn;
}*/

int LongNumber::get_digits_number() const noexcept {
	return length;
}

int LongNumber::get_rank_number(int rank) const {
	return numbers[length - rank];
}

bool LongNumber::is_negative() const noexcept {
	if (sign == 1){
		return false;
	}
	else{
		return true;
	}
}

// ----------------------------------------------------------
// PRIVATE
// ----------------------------------------------------------
int LongNumber::get_length(const char* const str) const noexcept {
	int str_length = std::strlen(str);
	int length;
	if (str[0] == '-'){
		length = str_length - 1;
	}
	else {
		length = str_length;
	}
	return length;
}

// ----------------------------------------------------------
// FRIENDLY
// ----------------------------------------------------------
namespace biv {
	std::ostream& operator << (std::ostream &os, const LongNumber& x) {
		if (x.sign == -1){
			os << "-";
		}
		for (int i = x.length - 1; i >= 0; --i){
			os << x.numbers[i];
		}
		return os;
	}
}

/*int main(){
	LongNumber x = LongNumber("45");
	LongNumber y = LongNumber("5");
	LongNumber z = LongNumber("5");
	LongNumber l = LongNumber ("-8");
	LongNumber h = LongNumber("12");
	LongNumber n = LongNumber("99");
	LongNumber big = LongNumber("198");
	LongNumber minusn = LongNumber("-99");
	LongNumber zero = LongNumber("0");
	LongNumber one = LongNumber("1");
	LongNumber minusone = LongNumber("-1");

	std::cout << "Проверка булевых функций:" << std::endl;
	std::cout << "45 == 5: " << (x == y) << std::endl;
	std::cout << "45 != 5: " << (x != y) << std::endl;
	std::cout << "45 > 5: " << (x > y) << std::endl;
	std::cout << "45 < 5: " << (x < y) << std::endl;
	std::cout << "37 < 45: " << (h < x) << std::endl;
	std::cout << "5 == 5: " << (y == z) << std::endl;
	std::cout << "5 != 5: " << (y != z) << std::endl;
	std::cout << "5 > 5: " << (y > z) << std::endl;	
	std::cout << "5 < 5: " << (y < z) << std::endl;
	std::cout << "-8 > 5: " << (l > z) << std::endl;
	std::cout << std::endl;

	std::cout << "Проверка дополнительных функций:" << std::endl;	
	std::cout << "Длина 45: " << x.get_digits_number() << std::endl;
	std::cout << "Длина 5: " << y.get_digits_number() << std::endl;
	std::cout << "Длина -8: " << l.get_digits_number() << std::endl;
	std::cout << "Получить 1 элемент 45: " << x.get_rank_number(1) << std::endl;
	std::cout << "Получить 2 элемент 198: " << big.get_rank_number(2) << std::endl;
	std::cout << "Отрицателен ли 5?: " << y.is_negative() << std::endl;
	std::cout << "Отрицателен ли -8?: " << l.is_negative() << std::endl;
	std::cout << std::endl;

	std::cout << "Проверка сложения:" << std::endl;
	std::cout << "45 + 0 = " << (x + zero) << std::endl;
	std::cout << "0 + 5 = " << (zero + y) << std::endl;
	std::cout << "0 + 0 = " << (zero + zero) << std::endl;
	std::cout << "1 + 1 = " << (one + one) << std::endl;
	std::cout << "1 + (-1) = " << (one + minusone) << std::endl;
	std::cout << "99 + 99 = " << (n + n) << std::endl;
	std::cout << "-99 + 12 = " << (minusn + h) << std::endl;
	std::cout << "12 + (-99) = " << (h + minusn) << std::endl;
	std::cout << "12 + (-8) = " << (h + l) << std::endl;
	std::cout << "(-8) + 12 = " << (l + h) << std::endl;
	std::cout << "45 + 5 = " << (x + y) << std::endl;
	std::cout << "5 + 45 = " << (y + x) << std::endl;
	std::cout << std::endl;

	std::cout << "Проверка вычитания:" << std::endl;
	std::cout << "45 - 0 = " << (x - zero) << std::endl;
	std::cout << "0 - 5 = " << (zero - y) << std::endl;
	std::cout << "0 - 0 = " << (zero - zero) << std::endl;
	std::cout << "1 - 1 = " << (one - one) << std::endl;
	std::cout << "1 - (-1) = " << (one - minusone) << std::endl;
	std::cout << "99 - 99 = " << (n - n) << std::endl;
	std::cout << "-99 - 12 = " << (minusn - h) << std::endl;
	std::cout << "12 - (-99) = " << (h - minusn) << std::endl;
	std::cout << "12 - (-8) = " << (h - l) << std::endl;
	std::cout << "(-8) - 12 = " << (l - h) << std::endl;
	std::cout << "45 - 5 = " << (x - y) << std::endl;
	std::cout << "5 - 45 = " << (y - x) << std::endl;
	std::cout << std::endl;

	std::cout << "Проверка умножения:" << std::endl;
	std::cout << "45 * 0 = " << (x * zero) << std::endl;
	std::cout << "45 * 1 = " << (x * one) << std::endl;
	std::cout << "1 * 45 = " << (one * x) << std::endl;
	std::cout << "1 * 1 = " << (one * one) << std::endl;
	std::cout << "1 * (-1) = " << (one * minusone) << std::endl;
	std::cout << "0 * 99 = " << (zero * n) << std::endl;
	std::cout << "12 * 99 = " << (h * n) << std::endl;
	std::cout << "198 * 99 * -1 = " << (big * n * minusone) << std::endl;
	std::cout << "12 * (-8) = " << (h * l) << std::endl;
	std::cout << "99 * 99 = " << (n * n) << std::endl;
	std::cout << std::endl;
}*/
