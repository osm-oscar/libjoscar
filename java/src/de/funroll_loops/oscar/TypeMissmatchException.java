package de.funroll_loops.oscar;

public class TypeMissmatchException extends Exception {
	private static final long serialVersionUID = 8957638234378999804L;
	public TypeMissmatchException() {}
	public TypeMissmatchException(String msg)  {
		super(msg);
	}
}