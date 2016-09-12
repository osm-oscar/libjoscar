package de.funroll_loops.oscar.nc;

public class GeoHierarchySubSet extends Base implements BaseInterface {
	public native int create();
	public native void destroy(int ptr);
	
	public native int cellCount(int ptr);
	public native int itemCount(int ptr);
	public native int[] topK(int ptr, int count);
	public native int[] flaten(int ptr);
}