package de.funroll_loops.oscar;

public class GeoHierarchySubSet extends Base<de.funroll_loops.oscar.nc.GeoHierarchySubSet> {

	public GeoHierarchySubSet(int _ptr) {
		super(new de.funroll_loops.oscar.nc.GeoHierarchySubSet(), _ptr);
	}
	
	public int cellCount() {
		return cnc().cellCount( ptr() );
	}
	
	public int itemCount() {
		return cnc().itemCount( ptr() );
	}
	
	public int[] topK(int count) {
		return cnc().topK(ptr(), count);
	}
	
	public int[] flaten() {
		return cnc().flaten( ptr() );
	}
}
