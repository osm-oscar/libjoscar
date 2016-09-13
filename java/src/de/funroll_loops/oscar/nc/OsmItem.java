package de.funroll_loops.oscar.nc;

public class OsmItem extends Base implements BaseInterface {

	public native int create();
	public native void destroy(int ptr);

	public native int id(int ptr);
	public native int[] ancestors(int ptr);
	
	public native boolean isRegion(int ptr);
	
	public native int size(int ptr);
	
	public native int keyId(int ptr, int pos);
	public native int valueId(int ptr, int pos);
	
	public native String key(int ptr, int pos);
	public native String value(int ptr, int pos);

}