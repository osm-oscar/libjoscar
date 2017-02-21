#include "de_funroll_loops_oscar_nc_OsmKeyValueObjectStore.h"
#include "helpers.h"
#include "creationHelpers.h"
#include "exceptionhelpers.h"
#include "ObjectStore.h"

namespace {
	libjoscar::ObjectStore<liboscar::Static::OsmKeyValueObjectStore> objStore;
}

namespace libjoscar {

JavaNativeHandle createStore(const liboscar::Static::OsmKeyValueObjectStore & v) {
	return objStore.insert(new liboscar::Static::OsmKeyValueObjectStore(v) );
}

} //end namespace libjoscar

/*
 * Class:     de_funroll_loops_oscar_nc_OsmKeyValueObjectStore
 * Method:    create
 * Signature: ()I
 */
JNIEXPORT JavaNativeHandle JNICALL Java_de_funroll_1loops_oscar_nc_OsmKeyValueObjectStore_create
  (JNIEnv * env, jobject)
{
	try {
		return objStore.insert( new liboscar::Static::OsmKeyValueObjectStore() );
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmKeyValueObjectStore
 * Method:    destroy
 * Signature: (I)Z
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_OsmKeyValueObjectStore_destroy
  (JNIEnv * env, jobject, JavaNativeHandle id)
{
	try {
		objStore.destroy(id);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmKeyValueObjectStore
 * Method:    numberOfRegions
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmKeyValueObjectStore_numberOfRegions
  (JNIEnv * env, jobject, JavaNativeHandle id)
{
	try {
		return objStore.get(id)->geoHierarchy().regionSize();
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmKeyValueObjectStore
 * Method:    size
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmKeyValueObjectStore_size
  (JNIEnv * env, jobject, JavaNativeHandle id)
{
	try {
		return objStore.get(id)->size();
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmKeyValueObjectStore
 * Method:    at
 * Signature: (II)I
 */
JNIEXPORT JavaNativeHandle JNICALL Java_de_funroll_1loops_oscar_nc_OsmKeyValueObjectStore_at
  (JNIEnv * env, jobject, JavaNativeHandle id, jint pos)
{
	try {
		return libjoscar::createOsmItem( objStore.get(id)->at(pos) );
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmKeyValueObjectStore
 * Method:    keyStringTable
 * Signature: (I)I
 */
JNIEXPORT JavaNativeHandle JNICALL Java_de_funroll_1loops_oscar_nc_OsmKeyValueObjectStore_keyStringTable
  (JNIEnv * env, jobject, JavaNativeHandle id)
{
	try {
		return libjoscar::createStringTable( objStore.get(id)->keyStringTable() );
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}