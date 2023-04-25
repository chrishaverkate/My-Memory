set(target_name ${CMAKE_PROJECT_NAME}_cli)

add_executable(${target_name}
	main.cpp
)

target_link_libraries(${target_name}
	PUBLIC
		${CMAKE_PROJECT_NAME}_includes
		${CMAKE_PROJECT_NAME}_lib
)

set_target_properties(${target_name}
	PROPERTIES
		C_STANDARD 11
		CXX_STANDARD 17
)

