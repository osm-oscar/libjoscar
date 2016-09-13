package de.funroll_loops.oscar;

public class OsmItem extends Base<de.funroll_loops.oscar.nc.OsmItem> {

	public OsmItem() {
	}

	public OsmItem(int _ptr) {
		super(new de.funroll_loops.oscar.nc.OsmItem(), _ptr);
	}
	
	public int id() {
		return cnc().id( ptr() );
	}
	
	public int[] ancestors() {
		return cnc().ancestors( ptr() );
	}
	
	public boolean isRegion() {
		return cnc().isRegion( ptr() );
	}
	
	public int size() {
		return cnc().size( ptr() );
	}

	public int keyId(int pos) {
		return cnc().keyId(ptr(), pos);
	}
	
	public int valueId(int pos) {
		return cnc().valueId(ptr(), pos);
	}
	
	public String key(int pos) {
		return cnc().key(ptr(), pos);
	}
	
	public String value(int pos) {
		return cnc().value(ptr(), pos);
	}
}