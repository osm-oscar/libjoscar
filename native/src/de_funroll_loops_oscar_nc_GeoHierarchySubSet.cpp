#include "de_funroll_loops_oscar_nc_GeoHierarchySubSet.h"
#include "exceptionhelpers.h"
#include "helpers.h"
#include "creationHelpers.h"
#include "ObjectStore.h"

namespace {
	libjoscar::ObjectStore<sserialize::Static::spatial::GeoHierarchy::SubSet> objStore;
}

namespace libjoscar {

int createGeoHierarchySubSet(const sserialize::Static::spatial::GeoHierarchy::SubSet & v) {
	return objStore.insert(new sserialize::Static::spatial::GeoHierarchy::SubSet(v) );
}

}//end namespace libjoscar

/*
 * Class:     de_funroll_loops_oscar_nc_GeoHierarchySubSet
 * Method:    create
 * Signature: ()I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_GeoHierarchySubSet_create
  (JNIEnv * env, jobject)
{
	try {
		return objStore.insert(new sserialize::Static::spatial::GeoHierarchy::SubSet() );
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_GeoHierarchySubSet
 * Method:    destroy
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_de_funroll_1loops_oscar_nc_GeoHierarchySubSet_destroy
  (JNIEnv * env, jobject, jint id)
{
	try {
		return objStore.destroy(id);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_GeoHierarchySubSet
 * Method:    cellCount
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_GeoHierarchySubSet_cellCount
  (JNIEnv * env, jobject, jint id)
{
	try {
		return objStore.get(id)->cqr().cellCount();
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_GeoHierarchySubSet
 * Method:    itemCount
 * Signature: (I)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_GeoHierarchySubSet_itemCount
  (JNIEnv * env, jobject, jint id)
{
	try {
		return objStore.get(id)->cqr().flaten().size();
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_GeoHierarchySubSet
 * Method:    topK
 * Signature: (II)[I
 */
JNIEXPORT jintArray JNICALL Java_de_funroll_1loops_oscar_nc_GeoHierarchySubSet_topK
  (JNIEnv * env, jobject, jint id, jint count)
{
	try {
		auto ghs = objStore.get(id);
		sserialize::ItemIndex idx = ghs->topK(ghs->root(), count);
		return libjoscar::toJIntArray(env, idx);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return libjoscar::toJIntArray(env, std::vector<uint32_t>() );
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_GeoHierarchySubSet
 * Method:    flatten
 * Signature: (I)[I
 */
JNIEXPORT jintArray JNICALL Java_de_funroll_1loops_oscar_nc_GeoHierarchySubSet_flaten
  (JNIEnv * env, jobject, jint id)
{
	try {
		auto ghs = objStore.get(id);
		sserialize::ItemIndex idx = ghs->cqr().flaten();
		return libjoscar::toJIntArray(env, idx);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return libjoscar::toJIntArray(env, std::vector<uint32_t>() );
	}
}