package de.funroll_loops.oscar;

public class StringTable extends Base<de.funroll_loops.oscar.nc.StringTable> {
	public StringTable() {
	}

	public StringTable(long _ptr) {
		super(new de.funroll_loops.oscar.nc.StringTable(), _ptr);
	}
	
	public int size() {
		return cnc().size(ptr());
	}
	
	public String at(int pos) {
		return cnc().at(ptr(), pos);
	}
}
