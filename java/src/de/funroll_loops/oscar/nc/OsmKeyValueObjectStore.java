package de.funroll_loops.oscar.nc;

public class OsmKeyValueObjectStore extends Base implements BaseInterface {
	
	public native long create();
	public native void destroy(long ptr);

	public native int numberOfRegions(long ptr);
	public native int size(long ptr);
	
	public native long at(long ptr, int pos);
	
	public native long keyStringTable(long ptr);
}