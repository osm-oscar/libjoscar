#ifndef LIB_J_OSCAR_HELPERS_H
#define LIB_J_OSCAR_HELPERS_H
#pragma once

#include <jni.h>

#include <string>
#include <sserialize/containers/ItemIndex.h>

namespace libjoscar {


std::string toString(JNIEnv * env, const jstring & jstr);
jstring toJString(JNIEnv * env, const std::string & str);
jintArray toJIntArray(JNIEnv * env, const sserialize::ItemIndex & idx);
jintArray toJIntArray(JNIEnv* env, const std::vector< uint32_t >& arr);
jintArray toJIntArray(JNIEnv* env, const std::vector<jint> & arr);


}

#endif