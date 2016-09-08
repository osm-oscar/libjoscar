package de.funroll_loops.oscar;

public class OsmCompleter extends Base<de.funroll_loops.oscar.nc.OsmCompleter> {
	public OsmCompleter() {
		super( new de.funroll_loops.oscar.nc.OsmCompleter() );
	}

	public void setFilePrefix(String filename) {
		cnc().setFilePrefix(ptr(), filename);
	}

	public void energize() {
		return cnc().energize( ptr() );
	}
	
	public OsmKeyValueObjectStore store() {
		int sptr = cnc().store( ptr() );
		return new OsmKeyValueObjectStore(sptr);
	}
}