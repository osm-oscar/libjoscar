#ifndef LIB_J_OSCAR_CREATION_HELPERS_H
#define LIB_J_OSCAR_CREATION_HELPERS_H
#pragma once
#include <liboscar/StaticOsmCompleter.h>

namespace libjoscar {

int createStore(const liboscar::Static::OsmKeyValueObjectStore & v);
int createOsmItem(const liboscar::Static::OsmKeyValueObjectStore::Item & v);
int createGeoHierarchySubSet(const sserialize::Static::spatial::GeoHierarchy::SubSet & v);

}

#endif