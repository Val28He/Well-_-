target_sources(sort_lib
	PRIVATE
		sort.cpp
	PUBLIC
		sort.hpp
)

target_include_directories(sort_lib PUBLIC
	"${PROJECT_SOURCE_DIR}/src"
)