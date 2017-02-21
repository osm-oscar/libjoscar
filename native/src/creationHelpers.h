#ifndef LIB_J_OSCAR_CREATION_HELPERS_H
#define LIB_J_OSCAR_CREATION_HELPERS_H
#pragma once
#include <liboscar/StaticOsmCompleter.h>
#include "types.h"

namespace libjoscar {

JavaNativeHandle createStore(const liboscar::Static::OsmKeyValueObjectStore & v);
JavaNativeHandle createStringTable(const sserialize::Static::StringTable & v);
JavaNativeHandle createOsmItem(const liboscar::Static::OsmKeyValueObjectStore::Item & v);
JavaNativeHandle createGeoHierarchySubSet(const sserialize::Static::spatial::GeoHierarchy::SubSet & v);

}

#endif