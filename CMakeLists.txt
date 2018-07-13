cmake_minimum_required(VERSION 3.9)
project(joscar)

find_package(JNI REQUIRED)
add_subdirectory(vendor/liboscar liboscar)

set(MY_INCLUDE_DIRS
	${JNI_INCLUDE_DIRS}
)

set(MY_LINK_LIBS
	liboscar
)

set(JOSCAR_SOURCES_CPP
	native/src/de_funroll_loops_oscar_nc_GeoHierarchySubSet.cpp
	native/src/de_funroll_loops_oscar_nc_Helpers.cpp
	native/src/de_funroll_loops_oscar_nc_OsmCompleter.cpp
	native/src/de_funroll_loops_oscar_nc_OsmItem.cpp
	native/src/de_funroll_loops_oscar_nc_OsmKeyValueObjectStore.cpp
	native/src/de_funroll_loops_oscar_nc_StringTable.cpp
	native/src/exceptionhelpers.cpp
	native/src/helpers.cpp
)

add_library(${PROJECT_NAME} SHARED ${JOSCAR_SOURCES_CPP})
target_link_libraries(${PROJECT_NAME} PUBLIC ${MY_LINK_LIBS})
target_include_directories(${PROJECT_NAME} PUBLIC ${MY_INCLUDE_DIRS})
