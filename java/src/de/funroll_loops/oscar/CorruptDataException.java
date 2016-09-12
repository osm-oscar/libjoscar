package de.funroll_loops.oscar;

public class CorruptDataException extends de.funroll_loops.oscar.Exception {
	private static final long serialVersionUID = -1998532489875308530L;
	public CorruptDataException() {}
	public CorruptDataException(String msg)  {
		super(msg);
	}
}