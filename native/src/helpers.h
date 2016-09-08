#ifndef LIB_J_OSCAR_HELPERS_H
#define LIB_J_OSCAR_HELPERS_H
#pragma once

#include <jni.h>

#include <string>

namespace libjoscar {


std::string toString(JNIEnv * env, const jstring & jstr);
jstring toJString(JNIEnv * env, const std::string & str);

}

#endif