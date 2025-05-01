target_sources(vector_list.lib
	PRIVATE
		doubly_linked_list.cpp
		vector.cpp
	PUBLIC
		doubly_linked_list.hpp
		vector.hpp
)

target_include_directories(vector_list.lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)