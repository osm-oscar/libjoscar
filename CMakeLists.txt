cmake_minimum_required(VERSION 2.8)
project(joscar)

find_package(JNI REQUIRED)
# find_package(LIBRT REQUIRED)

set(MY_C_FLAGS "${CMAKE_C_FLAGS} -frounding-math -std=c99 -Wall -Wextra -Wno-unknown-pragmas -Wstrict-overflow=4")
set(MY_CXX_FLAGS "${CMAKE_CXX_FLAGS} -frounding-math -std=gnu++14 -Wall -Wextra -Wno-unknown-pragmas -Wstrict-overflow=4")

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${MY_C_FLAGS}")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${MY_CXX_FLAGS}")
set(CMAKE_C_FLAGS_DEBUG "${CMAKE_C_FLAGS_DEBUG} ${DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} ${DEBUG_FLAGS}")
set(CMAKE_C_FLAGS_RELWITHDEBINFO "${CMAKE_C_FLAGS_RELWITHDEBINFO} ${DEBUG_FLAGS}")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "${CMAKE_CXX_FLAGS_RELWITHDEBINFO} ${DEBUG_FLAGS}")

include_directories(
	${CMAKE_SOURCE_DIR}
	${CMAKE_CURRENT_BINARY_DIR}
	${CMAKE_CURRENT_SOURCE_DIR}
	${JNI_INCLUDE_DIRS}
	${CMAKE_SOURCE_DIR}/vendor/liboscar/include
	${CMAKE_SOURCE_DIR}/vendor/liboscar/vendor/sserialize/include
	${LIBDTS2_INCLUDE_DIR}
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

SET(JOSCAR_LINK_LIBS
	${LIBRT_LIBRARIES}
	${liboscar_BINARY_DIR}/libliboscar.so
	${sserialize_BINARY_DIR}/libsserialize.a
)

add_subdirectory(vendor/liboscar liboscar)

add_library(${PROJECT_NAME} SHARED ${JOSCAR_SOURCES_CPP})
target_link_libraries(${PROJECT_NAME} ${JOSCAR_LINK_LIBS})
add_dependencies(${PROJECT_NAME} liboscar)