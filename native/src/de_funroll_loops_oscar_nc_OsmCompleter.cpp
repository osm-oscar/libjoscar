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
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_create
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
JNIEXPORT jboolean JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_destroy
  (JNIEnv * env, jobject obj, jint id)
{
	try {
		objStore.destroy(id);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return false;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmCompleter
 * Method:    setFilePrefix
 * Signature: (ILjava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_setFilePrefix
  (JNIEnv * env, jobject, jint id, jstring path)
{
	try {
		return objStore.get(id)->setAllFilesFromPrefix();
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return false;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmCompleter
 * Method:    energize
 * Signature: (I)Z
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_energize
  (JNIEnv * env, jobject, jint id)
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
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmCompleter_store
  (JNIEnv * env, jobject, jint id)
{
	try {
		return libjoscar::createStore(objStore.get(id)->store());
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}