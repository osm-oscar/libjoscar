package de.funroll_loops.oscar.nc;

public class GeoHierarchySubSet extends Base implements BaseInterface {
	public native long create();
	public native void destroy(long ptr);
	
	public native int cellCount(long ptr);
	public native int itemCount(long ptr);
	public native int[] topK(long ptr, int count);
	public native int[] flaten(long ptr);
}