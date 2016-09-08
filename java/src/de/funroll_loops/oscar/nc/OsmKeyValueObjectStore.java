package de.funroll_loops.oscar.nc;

public class OsmKeyValueObjectStore extends Base implements BaseInterface {
	
	public native int create();
	public native boolean destroy(int ptr);

	public native int size(int ptr);
	
	public native int at(int ptr, int pos);
}