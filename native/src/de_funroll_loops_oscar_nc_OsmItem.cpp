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
 * Method:    ancestors
 * Signature: (I)[I
 */
JNIEXPORT jintArray JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_ancestors
  (JNIEnv * env, jobject, jint id)
{
	try {
		auto itemPtr = objStore.get(id);
		const auto & gh = itemPtr->db().geoHierarchy();
		std::vector<int> ancestors;

		if (itemPtr->isRegion()) {
			auto region = gh.region( gh.storeIdToGhId( itemPtr->id() ) );
			for(uint32_t i(0), s(region.parentsSize()); i < s; ++i) {
				ancestors.emplace_back( region.parent(i) );
			}
			for(std::size_t i(0); i < ancestors.size(); ++i) {
				region = gh.region(ancestors.at(i));
				for(uint32_t j(0), s(region.parentsSize()); j < s; ++j) {
					ancestors.emplace_back( region.parent(j) );
				}
			}
		}
		else {
			auto cells = itemPtr->cells();
			for(uint32_t c : cells) {
				for(uint32_t i(gh.cellParentsBegin(c)), s(gh.cellParentsEnd(c)); i < s; ++i) {
					ancestors.emplace_back( gh.cellPtrs().at(i) );
				}
			}
		}
		using std::sort;
		using std::unique;
		sort(ancestors.begin(), ancestors.end());
		ancestors.resize(unique(ancestors.begin(), ancestors.end()) - ancestors.begin());
		return libjoscar::toJIntArray(env, ancestors);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return libjoscar::toJIntArray(env, std::vector<int>());
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmItem
 * Method:    isRegion
 * Signature: (I)Z
 */
JNIEXPORT jboolean JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_isRegion
  (JNIEnv * env, jobject, jint id)
{
	try {
		return objStore.get(id)->isRegion();
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return false;
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
 * Method:    keyId
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_keyId
  (JNIEnv * env, jobject, jint id, jint pos)
{
	try {
		return objStore.get(id)->keyId(pos);
	}
	catch (...) {
		libjoscar::swallow_cpp_exception_and_throw_java(env);
		return -1;
	}
}

/*
 * Class:     de_funroll_loops_oscar_nc_OsmItem
 * Method:    valueId
 * Signature: (II)I
 */
JNIEXPORT jint JNICALL Java_de_funroll_1loops_oscar_nc_OsmItem_valueId
  (JNIEnv * env, jobject, jint id, jint pos)
{
	try {
		return objStore.get(id)->valueId(pos);
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
