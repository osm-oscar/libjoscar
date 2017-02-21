package de.funroll_loops.oscar.nc;

public class StringTable extends Base implements BaseInterface {
	public native long create();
	public native void destroy(long ptr);
	
	public native int size(long ptr);
	public native String at(long ptr, int pos);
}
