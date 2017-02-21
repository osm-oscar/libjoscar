package de.funroll_loops.oscar;

public class OsmCompleter extends Base<de.funroll_loops.oscar.nc.OsmCompleter> {
	public OsmCompleter() {
		super( new de.funroll_loops.oscar.nc.OsmCompleter() );
	}

	public void setFilePrefix(String filename) {
		cnc().setFilePrefix(ptr(), filename);
	}

	public void energize() {
		cnc().energize( ptr() );
	}
	
	public OsmKeyValueObjectStore store() {
		long sptr = cnc().store( ptr() );
		return new OsmKeyValueObjectStore(sptr);
	}
	
	public GeoHierarchySubSet clusteredComplete(String qstr, boolean treedCQR) {
		long sptr = cnc().clusteredComplete(ptr(), qstr, treedCQR);
		return new GeoHierarchySubSet(sptr);
	}
}