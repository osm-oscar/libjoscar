package de.funroll_loops.oscar;

public class OsmKeyValueObjectStore extends Base<de.funroll_loops.oscar.nc.OsmKeyValueObjectStore> {
	private int m_size = 0;
	
	public OsmKeyValueObjectStore() {
	}

	public OsmKeyValueObjectStore(int ptr) {
		super(new de.funroll_loops.oscar.nc.OsmKeyValueObjectStore(), ptr);
		m_size = cnc().size( ptr() );
	}

	public int numberOfRegions() {
		return cnc().numberOfRegions( ptr() );
	}

	public int size() {
		return m_size;
	}
	
	public OsmItem at(int pos) {
		return new OsmItem( cnc().at(ptr(), pos) );
	}
	
	public StringTable keyStringTable() {
		return new StringTable( cnc().keyStringTable(ptr()) );
	}
}