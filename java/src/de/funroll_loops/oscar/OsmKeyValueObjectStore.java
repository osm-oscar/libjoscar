package de.funroll_loops.oscar;

public class OsmKeyValueObjectStore extends Base<de.funroll_loops.oscar.nc.OsmKeyValueObjectStore> {
	
	public OsmKeyValueObjectStore() {
	}

	public OsmKeyValueObjectStore(int ptr) {
		super(new de.funroll_loops.oscar.nc.OsmKeyValueObjectStore(), ptr);
	}
	
	public int size() {
		return cnc().size( ptr() );
	}
	
	public OsmItem at(int pos) {
		return new OsmItem( cnc().at(ptr(), pos) );
	}
	
}