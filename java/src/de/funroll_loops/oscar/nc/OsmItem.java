package de.funroll_loops.oscar.nc;

public class OsmItem extends Base implements BaseInterface {

	public native long create();
	public native void destroy(long ptr);

	public native int id(long ptr);
	public native int[] ancestors(long ptr);
	
	public native boolean isRegion(long ptr);
	
	public native int size(long ptr);
	
	public native int keyId(long ptr, int pos);
	public native int valueId(long ptr, int pos);
	
	public native String key(long ptr, int pos);
	public native String value(long ptr, int pos);

}