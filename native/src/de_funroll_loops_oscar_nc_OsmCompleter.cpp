#include "de_funroll_loops_oscar_nc_OsmCompleter.h"
#include "exceptionhelpers.h"
#include "helpers.h"
#include "creationHelpers.h"

#include <liboscar/StaticOsmCompleter.h>

#include "ObjectStore.h"

namespace {
	libjoscar::ObjectStore<liboscar::Static::OsmCompleter> objStore;
}
/*
 * Class:     de_funroll_loops_oscar_nc_OsmCompleter
 * Method:    create
 * Signature: ()I
 */
JNIEXPORT JavaNativeHandle JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_create
  (JNIEnv * env, jobject)
{
	try {
		auto p = new liboscar::Static::OsmCompleter();
		auto id = objStore.insert(p);
		return id;
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmCompleter
 * Method:    destroy
 * Signature: (I)Z
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_destroy
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
 * Class:     de_funroll_loops_oscar_nc_OsmCompleter
 * Method:    setFilePrefix
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_setFilePrefix
  (JNIEnv * env, jobject, JavaNativeHandle id, jstring path)
{
	try {
		objStore.get(id)->setAllFilesFromPrefix( libjoscar::toString(env, path) );
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmCompleter
 * Method:    energize
 * Signature: (I)Z
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_energize
  (JNIEnv * env, jobject, JavaNativeHandle id)
{
	try {
		objStore.get(id)->energize();
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmCompleter
 * Method:    store
 * Signature: (I)I
 */
JNIEXPORT JavaNativeHandle JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_store
  (JNIEnv * env, jobject, JavaNativeHandle id)
{
	try {
		return libjoscar::createStore(objStore.get(id)->store());
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmCompleter
 * Method:    clusteredComplete
 * Signature: (Ljava/lang/String;Z)I
 */
JNIEXPORT JavaNativeHandle JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_clusteredComplete
  (JNIEnv * env, jobject, JavaNativeHandle id, jstring qjstr, jboolean treedCQR)
{
	try {
		std::string qstr( libjoscar::toString(env, qjstr) );
		auto tmp = objStore.get(id)->clusteredComplete(qstr, 0xFFFFFFFF, treedCQR, 1); 
		return libjoscar::createGeoHierarchySubSet(tmp);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}
  