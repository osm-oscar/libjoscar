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

jbyteArray toByteArray(JNIEnv * env, const std::string & str) {
	jbyteArray bytes = env->NewByteArray(str.size());
	env->SetByteArrayRegion(bytes, 0, str.size(), (jbyte*) str.c_str());
    return bytes;
}

jintArray toJIntArray(JNIEnv * env, const sserialize::ItemIndex& idx) {
	std::vector<uint32_t> tmp;
	tmp.reserve(idx.size());
	idx.putInto(tmp);
	return toJIntArray(env, tmp);
}

jintArray toJIntArray(JNIEnv * env, const std::vector<uint32_t> & arr) {
	return toJIntArray(env, std::vector<int>(arr.begin(), arr.end()) );
}

jintArray toJIntArray(JNIEnv* env, const std::vector<jint> & arr) {
	jintArray ret = env->NewIntArray(arr.size());
	env->SetIntArrayRegion(ret, 0, arr.size(), & (arr.front()) );
	return ret;
}

}//end namespace libjoscar