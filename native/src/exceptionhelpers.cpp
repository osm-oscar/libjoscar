#include "exceptionhelpers.h"
#include <sserialize/utility/exceptions.h>
#include <iostream>

namespace libjoscar {

NewJavaException::NewJavaException(JNIEnv * env, const char* t, const char* m) :
ThrownJavaException(t+std::string(" ")+m)
{
	jclass newExcCls = env->FindClass(t);
	if (newExcCls != NULL) {
		env->ThrowNew(newExcCls, m);
	}
	//if it is null, a NoClassDefFoundError was already thrown
}


void assert_no_exception(JNIEnv * env) {
	if (env->ExceptionCheck()==JNI_TRUE)  {
		throw ThrownJavaException("assert_no_exception");
	}
}

void swallow_cpp_exception_and_throw_java(JNIEnv * env) {
	try {
		throw;
	}
	catch(const ThrownJavaException&) {
		//already reported to Java, ignore
	}
	catch(const std::bad_alloc& rhs) {
		//translate OOM C++ exception to a Java exception
		NewJavaException(env, "java/lang/OutOfMemoryError", rhs.what()); 
	}
	catch(const std::ios_base::failure& rhs) { //sample translation
		//translate IO C++ exception to a Java exception
		NewJavaException(env, "java/io/IOException", rhs.what()); 
	}
	catch (const sserialize::InvalidReferenceException & e) {
		NewJavaException(env, "java/lang/NullPointerException", e.what());
	}
	catch (const sserialize::CorruptDataException & e) {
		NewJavaException(env, "de/funroll_loops/oscar/CurruptDataException", e.what());
	}
	catch (const sserialize::VersionMissMatchException & e) {
		NewJavaException(env, "de/funroll_loops/oscar/VersionMissMatchException", e.what());
	}
	catch (const sserialize::TypeMissMatchException & e) {
		NewJavaException(env, "de/funroll_loops/oscar/TypeMissMatchException", e.what());
	}
	catch (const sserialize::Exception & e) {
		NewJavaException(env, "de/funroll_loops/oscar/Exception", e.what());
	}
	catch(const std::exception& e) {
		//translate unknown C++ exception to a Java exception
		NewJavaException(env, "java/lang/Error", e.what());
	} catch(...) {
		//translate unknown C++ exception to a Java exception
		NewJavaException(env, "java/lang/Error", "Unknown exception type");
	}
}

}//end namespace