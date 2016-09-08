#include "de_funroll_loops_oscar_nc_Helpers.h"
#include "helpers.h"
#include "exceptionhelpers.h"

#include <sserialize/storage/UByteArrayAdapter.h>

/*
 * Class:     de_funroll_loops_oscar_nc_Helpers
 * Method:    setSlowTempFilePrefix
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_Helpers_setSlowTempFilePrefix
  (JNIEnv * env, jclass cls, jstring path)
{
	try {
		sserialize::UByteArrayAdapter::setTempFilePrefix(libjoscar::toString(env, path));
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_Helpers
 * Method:    setFastTempFilePrefix
 * Signature: (Ljava/lang/String;)V
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_Helpers_setFastTempFilePrefix
  (JNIEnv * env, jclass cls, jstring path)
{
	try {
		sserialize::UByteArrayAdapter::setFastTempFilePrefix(libjoscar::toString(env, path));
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}