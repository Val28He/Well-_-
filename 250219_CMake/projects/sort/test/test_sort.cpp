#include <gmock/gmock.h>
#include <gtest/gtest.h>

#include "sort.hpp"

TEST(ArraysEqual, AnyElementsCount) {
	int actual [] = {2, 26, 31, 20, 14, 67, 8};
	int actual_size = sizeof(actual)/sizeof(actual[0]);
	biv::sortings::insertion_sort(actual, actual_size);
	int expected [] = {2, 8, 14, 20, 26, 31, 67};
	
	ASSERT_EQ(sizeof(expected)/sizeof(expected[0]), sizeof(actual)/sizeof(actual[0]))
		<< "Разные размеры ожидаемого и отсортированного массивов";
	
	for (int i = 0; i < sizeof(actual)/sizeof(actual[0]); ++i) {
		ASSERT_EQ(expected[i], actual[i])
			<< "Массив ожидаемый и отсортированный отличается в элементе с индексом: "
			<< i;
	}
}

int main(int argc, char **argv) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}