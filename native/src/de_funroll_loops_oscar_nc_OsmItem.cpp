#include "de_funroll_loops_oscar_nc_OsmItem.h"
#include "creationHelpers.h"
#include "helpers.h"
#include "exceptionhelpers.h"
#include "ObjectStore.h"

namespace {
	libjoscar::ObjectStore<liboscar::Static::OsmKeyValueObjectStore::Item> objStore;
}

namespace libjoscar {

int createOsmItem(const liboscar::Static::OsmKeyValueObjectStore::Item & v) {
	return objStore.insert( new liboscar::Static::OsmKeyValueObjectStore::Item(v) );
}

} //end namespace libjoscar

/*
 * Class:     de_funroll_loops_oscar_nc_OsmItem
 * Method:    create
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_create
  (JNIEnv * env, jobject)
{
	try {
		return objStore.insert(new liboscar::Static::OsmKeyValueObjectStore::Item());
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmItem
 * Method:    destroy
 * Signature: (I)Z
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_destroy
  (JNIEnv * env, jobject, jint id)
{
	try {
		objStore.destroy(id);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmItem
 * Method:    id
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_id
  (JNIEnv * env, jobject, jint id)
{
	try {
		return objStore.get(id)->id();
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmItem
 * Method:    size
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_size
  (JNIEnv * env, jobject, jint id)
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
 * Class:     de_funroll_loops_oscar_nc_OsmItem
 * Method:    key
 * Signature: (II)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_key
  (JNIEnv * env, jobject, jint id, jint pos)
{
	try {
		return libjoscar::toJString(env, objStore.get(id)->key(pos) );
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return libjoscar::toJString(env, std::string());
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmItem
 * Method:    value
 * Signature: (II)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_value
  (JNIEnv * env, jobject, jint id, jint pos)
{
	try {
		return libjoscar::toJString(env, objStore.get(id)->value(pos) );
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return libjoscar::toJString(env, std::string());
	}
}
