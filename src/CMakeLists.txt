add_subdirectory(element)
add_subdirectory(lib)
add_subdirectory(model)
add_subdirectory(item)
add_subdirectory(page)
add_subdirectory(qml)
add_subdirectory(util)

target_sources(${PROJECT_NAME} PRIVATE
	${CMAKE_CURRENT_SOURCE_DIR}/main.cpp
	${CMAKE_CURRENT_SOURCE_DIR}/qmlmanager.cpp)