#include "helpers.h"

namespace libjoscar {

std::string toString(JNIEnv* env, const jstring& jstr) {
	jboolean iscopy;
	const char * jstrUtf8 = env->GetStringUTFChars(jstr, &iscopy);
	std::string tmp(jstrUtf8);
	env->ReleaseStringUTFChars(jstr, jstrUtf8);
	return tmp;
}
jstring toJString(JNIEnv* env, const std::string& str) {
	return env->NewStringUTF( str.c_str() );
}

}//end namespace libjoscar