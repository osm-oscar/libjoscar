#/bin/bash

BASE_PATH=$(pwd)

cd "${BASE_PATH}/java" && ant || exit

cd "${BASE_PATH}/native/src" || exit

javah -classpath "${BASE_PATH}/java/build" de.funroll_loops.oscar.nc.Helpers
javah -classpath "${BASE_PATH}/java/build" de.funroll_loops.oscar.nc.OsmItem
javah -classpath "${BASE_PATH}/java/build" de.funroll_loops.oscar.nc.OsmCompleter
javah -classpath "${BASE_PATH}/java/build" de.funroll_loops.oscar.nc.OsmKeyValueObjectStore
javah -classpath "${BASE_PATH}/java/build" de.funroll_loops.oscar.nc.StringTable
javah -classpath "${BASE_PATH}/java/build" de.funroll_loops.oscar.nc.GeoHierarchySubSet
