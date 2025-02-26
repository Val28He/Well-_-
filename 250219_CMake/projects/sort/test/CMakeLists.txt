set(SOURCES
	test_sort.cpp
)

add_executable(test_sort ${SOURCES})
target_link_libraries(test_sort
	gtest_main
	gmock_main
	sort_lib
)

add_test(test_sort test_sort)