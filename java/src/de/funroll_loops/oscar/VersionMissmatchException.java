package de.funroll_loops.oscar;

public class VersionMissmatchException extends Exception {
	private static final long serialVersionUID = 3030979494410795741L;
	public VersionMissmatchException() {}
	public VersionMissmatchException(String msg)  {
		super(msg);
	}
}