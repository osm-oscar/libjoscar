#include "de_funroll_loops_oscar_nc_StringTable.h"
#include "exceptionhelpers.h"
#include "helpers.h"
#include "creationHelpers.h"
#include "ObjectStore.h"

namespace {
	libjoscar::ObjectStore<sserialize::Static::StringTable> objStore;
}

namespace libjoscar {

JavaNativeHandle createStringTable(const sserialize::Static::StringTable & v) {
	return objStore.insert(new sserialize::Static::StringTable(v) );
}

}//end namespace libjoscar

/*
 * Class:     de_funroll_loops_oscar_nc_StringTable
 * Method:    create
 * Signature: ()I
 */
JNIEXPORT JavaNativeHandle JNICALL Java_de_funroll_1loops_oscar_nc_StringTable_create
  (JNIEnv * env, jobject)
{
	try {
		return objStore.insert(new sserialize::Static::StringTable() );
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_StringTable
 * Method:    destroy
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_StringTable_destroy
  (JNIEnv * env, jobject, JavaNativeHandle id)
{
	try {
		return objStore.destroy(id);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_StringTable
 * Method:    size
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_StringTable_size
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
 * Class:     de_funroll_loops_oscar_nc_StringTable
 * Method:    at
 * Signature: (II)Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_de_funroll_1loops_oscar_nc_StringTable_at
  (JNIEnv * env, jobject, JavaNativeHandle id, jint pos)
{
	try {
		return libjoscar::toJString(env, objStore.get(id)->at(pos));
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return libjoscar::toJString(env, std::string());
	}
}