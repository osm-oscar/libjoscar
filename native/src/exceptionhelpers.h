#ifndef LIB_J_OSCAR_EXCEPTION_HELPERS_H
#define LIB_J_OSCAR_EXCEPTION_HELPERS_H
#pragma once

#include <stdexcept>
#include <jni.h>
//nice exceptions handlers for java/c++ from 
//http://stackoverflow.com/questions/4138168/what-happens-when-i-throw-a-c-exception-from-a-native-java-method

namespace libjoscar {

//This is how we represent a Java exception already in progress
struct ThrownJavaException : std::runtime_error {
	ThrownJavaException() : std::runtime_error("") {}
	ThrownJavaException(const std::string& msg ) : std::runtime_error(msg) {}
};

void assert_no_exception(JNIEnv * env);

struct NewJavaException : public ThrownJavaException {
	NewJavaException(JNIEnv * env, const char* t="", const char* m="");
};


void swallow_cpp_exception_and_throw_java(JNIEnv * env);

}//end namespace

#endif