cmake_minimum_required(VERSION 2.8)
project(joscar)

find_package(JNI REQUIRED)
# find_package(LIBRT REQUIRED)

include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${JNI_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR}/vendor/liboscar/include
	${CMAKE_SOURCE_DIR}/vendor/liboscar/vendor/sserialize/include
)

set(JOSCAR_SOURCES_CPP
	de_funroll_loops_oscar_nc_OsmCompleter.cpp
	de_funroll_loops_oscar_nc_OsmKeyValueObjectStore.cpp
	de_funroll_loops_oscar_nc_OsmItem.cpp
	de_funroll_loops_oscar_exceptionhelpers.cpp
)

SET(JOSCAR_LINK_LIBS
	${LIBRT_LIBRARIES}
)

add_subdirectory(vendor/liboscar liboscar)

add_library(${PROJECT_NAME} SHARED ${JOSCAR_SOURCES_CPP})
target_link_libraries(${PROJECT_NAME} ${JOSCAR_LINK_LIBS})
add_dependencies(${PROJECT_NAME} liboscar)