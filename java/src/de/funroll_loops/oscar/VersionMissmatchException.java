package de.funroll_loops.oscar;

public class VersionMissmatchException extends Exception {
	public VersionMissmatchException() {}
	public VersionMissmatchException(String msg)  {
		super(msg);
	}
}