package de.funroll_loops.oscar.nc;

public class StringTable extends Base implements BaseInterface {
	public native int create();
	public native void destroy(int ptr);
	
	public native int size(int ptr);
	public native String at(int ptr, int pos);
}
