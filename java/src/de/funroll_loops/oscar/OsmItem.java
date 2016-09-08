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
	
	public int size() {
		return cnc().size( ptr() );
	}

	public String key(int pos) {
		return cnc().key(ptr(), pos);
	}
	
	public String value(int pos) {
		return cnc().value(ptr(), pos);
	}
}