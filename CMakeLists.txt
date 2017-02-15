cmake_minimum_required(VERSION 3.0)
project(joscar)

set(MY_C_FLAGS "${CMAKE_C_FLAGS} -frounding-math -std=c99 -Wall -Wextra -Wno-unknown-pragmas -Wstrict-overflow=4")
set(MY_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frounding-math -std=gnu++14 -Wall -Wextra -Wno-unknown-pragmas -Wstrict-overflow=4")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MY_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CXX_FLAGS}")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${DEBUG_FLAGS}")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} ${DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${DEBUG_FLAGS}")

find_package(JNI REQUIRED)
add_subdirectory(vendor/liboscar liboscar)

include_directories(
	${JNI_INCLUDE_DIRS}
	${LIBOSCAR_INCLUDE_DIR}
)

SET(JOSCAR_LINK_LIBS
	${LIBOSCAR_LINK_LIBRARIES}
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
target_link_libraries(${PROJECT_NAME} ${JOSCAR_LINK_LIBS})
add_dependencies(${PROJECT_NAME} liboscar)