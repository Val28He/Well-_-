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
		numbers[i] = str[str_length - i - 1];
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
		for (int i = 0; i < length; ++i){
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
		for (int i = 0; i < length; ++i){
			if (numbers[i] >= x.numbers[i]){
				return false;
			}
		}
		return true;
	}
}

LongNumber LongNumber::operator + (const LongNumber& x) const {
	LongNumber result;
	if (x == LongNumber("0")){
		return LongNumber (*this);
	}
	if (*this == LongNumber("0")){
		return LongNumber (x); 
	}
	LongNumber one(*this);
	LongNumber two(x);
	int resultSign;
	int* resultNumbers = nullptr;
	if (one.sign == two.sign){
		int minLength = 0;
		int maxLength = 0;
		int* maxNumbers = nullptr;
		if (one.length > two.length){
			minLength = two.length;
			maxLength = one.length;
			maxNumbers = one.numbers;
		}
		else {
			minLength = one.length;
			maxLength = two.length;
			maxNumbers = two.numbers;
		}

		int sumNumbers[maxLength + 1];
		for (int i = 0; i < maxLength + 1; i++) {
			sumNumbers[i] = 0;
		}

		resultSign = one.sign;
		int diff = maxLength - minLength;
		for (int i = 0; i < minLength; ++i) {
			if (one.numbers[i] + two.numbers[i] < 10){
				sumNumbers[i] = one.numbers[i] + two.numbers[i];
			}
			else {
				sumNumbers[i] = (one.numbers[i] + two.numbers[i])%10;
				sumNumbers[i + 1] = sumNumbers[i + 1] + (one.numbers[i] + two.numbers[i])/10;
			}
		}
		if (sumNumbers[0] == 0){
			if (diff > 0){
				for (int i = minLength; i < maxLength; ++i) {
					sumNumbers[i] = maxNumbers[i];
				}
			}
		}
		if (sumNumbers[maxLength - 1] == 0){
			for (int i = 1; i < maxLength; ++i){
				resultNumbers[i - 1] = sumNumbers[i];
			}
		}
		else {
			resultNumbers = sumNumbers;
		}
	}
	else {
		int minLength = 0;
		int maxLength = 0;
		int maxSign = 0;
		int minSign = 0;
		int* maxNumbers = nullptr;
		int* minNumbers = nullptr;
		if (one.length > two.length){
			minLength = two.length;
			maxLength = one.length;
			maxNumbers = one.numbers;
			minNumbers = two.numbers;
			maxSign = one.sign;
			minSign = two.sign;
		}
		else {
			minLength = one.length;
			maxLength = two.length;
			maxNumbers = two.numbers;
			minNumbers = one.numbers;
			maxSign = two.sign;
			minSign = one.sign;
		}
		int sumNumbers[maxLength];
		int diff = maxLength - minLength;
		for (int i = 0; i < minLength; ++i){
			if (maxNumbers[i] - minNumbers[i] >= 0){
				sumNumbers[i] = maxNumbers[i] - minNumbers[i];
			}	
			else {
				sumNumbers[i] = 10 + maxNumbers[i] - minNumbers[i];
				maxNumbers[i + 1] = maxNumbers[i + 1] - 1;
			}
		}
		if (sumNumbers[maxLength - 1] == 0){
			for (int i = 1; i < maxLength; ++i){
				resultNumbers[i - 1] = sumNumbers[i];
			}
		}
		else {
			resultNumbers = sumNumbers;
		}
		resultSign = maxSign;
	}
	int resultLength = sizeof(resultNumbers)/sizeof(resultNumbers[0]);
	result.numbers = resultNumbers;
	result.length = resultLength;
	result.sign = resultSign;
	return result;
}

LongNumber LongNumber::operator - (const LongNumber& x) const {
	LongNumber result;
	if (x == LongNumber("0")){
		return LongNumber(*this);
	}
	if (*this == LongNumber("0")){
		return LongNumber(x);
	}
	LongNumber one(*this);
	LongNumber two(x);
	int resultSign;
	int* resultNumbers = nullptr;
	if (one.sign == two.sign){
		int minLength = 0;
		int maxLength = 0;
		int maxSign = 0;
		int minSign = 0;
		int* maxNumbers = nullptr;
		int* minNumbers = nullptr;
		if (one.length > two.length){
			minLength = two.length;
			maxLength = one.length;
			maxNumbers = one.numbers;
			minNumbers = two.numbers;
			maxSign = one.sign;
			minSign = two.sign;
		}
		else {
			minLength = one.length;
			maxLength = two.length;
			maxNumbers = two.numbers;
			minNumbers = one.numbers;
			maxSign = two.sign;
			minSign = one.sign;
		}
		int diffNumbers[maxLength];
		int diff = maxLength - minLength;
		for (int i = 0; i < minLength; ++i){
			if (maxNumbers[i] - minNumbers[i] >= 0){
				diffNumbers[i] = maxNumbers[i] - minNumbers[i];
			}	
			else {
				diffNumbers[i] = 10 + maxNumbers[i] - minNumbers[i];
				maxNumbers[i + 1] = maxNumbers[i + 1] - 1;
			}
		}
		if (diffNumbers[maxLength - 1] == 0){
			for (int i = 1; i < maxLength; ++i){
				resultNumbers[i - 1] = diffNumbers[i];
			}
		}
		else {
			resultNumbers = diffNumbers;
		}
		resultSign = maxSign;
	}

	else {
		int minLength = 0;
		int maxLength = 0;
		int* maxNumbers = nullptr;
		if (one.length > two.length){
			minLength = two.length;
			maxLength = one.length;
			maxNumbers = one.numbers;
		}
		else {
			minLength = one.length;
			maxLength = two.length;
			maxNumbers = two.numbers;
		}
		int diffNumbers[maxLength + 1];
		resultSign = one.sign;
		int diff = maxLength - minLength;
		for (int i = 0; i < minLength; ++i) {
			if (one.numbers[i] + two.numbers[i] < 10){
				diffNumbers[i] = one.numbers[i] + two.numbers[i];
			}
			else {
				diffNumbers[i] = (one.numbers[i] + two.numbers[i])%10;
				diffNumbers[i] = diffNumbers[i] + (one.numbers[i] + two.numbers[i])/10;
			}
		}
		if (diffNumbers[0] == 0){
			if (diff > 0){
				for (int i = minLength; i < maxLength; ++i) {
					diffNumbers[i] = maxNumbers[i];
				}
			}
		}
		if (diffNumbers[maxLength - 1] == 0){
			for (int i = 1; i < maxLength; ++i){
				resultNumbers[i - 1] = diffNumbers[i];
			}
		}
		else {
			resultNumbers = diffNumbers;
		}
	}
	int resultLength = sizeof(resultNumbers)/sizeof(resultNumbers[0]);
	result.numbers = resultNumbers;
	result.length = resultLength;
	result.sign = resultSign;
	return result;
}

LongNumber LongNumber::operator * (const LongNumber& x) const {
	LongNumber result;
	if (x == LongNumber("1")){
		return LongNumber(*this);
	}
	if (*this == LongNumber("1")){
		return LongNumber(x);
	}
	if ((*this == LongNumber("0")) or (x == LongNumber("0"))){
		return "0";
	}
	LongNumber one(*this);
	LongNumber two(x);
	int resultSign;
	if (one.sign == two.sign){
		resultSign = 1;
	}
	else{
		resultSign = -1;
	}
	int minLength = 0;
	int maxLength = 0;
	int* maxNumbers = nullptr;
	int* minNumbers = nullptr;
	if (one.length > two.length){
		minLength = two.length;
		maxLength = one.length;
		maxNumbers = one.numbers;
		minNumbers = two.numbers;
	}
	else {
		minLength = one.length;
		maxLength = two.length;
		maxNumbers = two.numbers;
		minNumbers = one.numbers;
	}
	int multLength = maxLength * 2;
	int* multNumbers = nullptr;
	for (int i = 0; i < minLength; ++i){
		for (int j = 0; j < maxLength; ++j){
			multNumbers[j + i] = multNumbers[j + i] + (maxNumbers[j] * minNumbers[i])%10;
			multNumbers[j + i + 1] = multNumbers[j + i + 1] + (maxNumbers[j] * minNumbers[i])/10;
		}
	}
	int* resultNumbers = nullptr;
	for (int i = multLength - 1; i >= 0; --i){
		if (multNumbers[i] != 0){
			for (int j = 0; j < i + 1; ++j){
				resultNumbers[j] = multNumbers[j];
				break;
			}
		}
	}
	int resultLength = sizeof(resultNumbers)/sizeof(resultNumbers[0]);
	result.numbers = resultNumbers;
	result.length = resultLength;
	result.sign = resultSign;
	return result;
}

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
	return numbers[rank];
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

int main(){
	LongNumber x = LongNumber("45");
	LongNumber y = LongNumber("0");
	LongNumber z = x + y;
	std::cout << z;
}
