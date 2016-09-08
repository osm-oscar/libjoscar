package de.funroll_loops.oscar.nc;

public class OsmCompleter extends Base implements BaseInterface {

	public native int create();
	public native void destroy(int ptr);

	public native void setFilePrefix(int ptr, String filename);

	public native void energize(int ptr);
	
	public native int store(int ptr);
}