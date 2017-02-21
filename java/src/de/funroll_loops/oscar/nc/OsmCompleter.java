package de.funroll_loops.oscar.nc;

public class OsmCompleter extends Base implements BaseInterface {

	public native long create();
	public native void destroy(long ptr);

	public native void setFilePrefix(long ptr, String filename);

	public native void energize(long ptr);
	
	public native long store(long ptr);
	
	public native long clusteredComplete(long ptr, String qstr, boolean treedCQR);
}