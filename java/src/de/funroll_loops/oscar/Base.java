package de.funroll_loops.oscar;

import de.funroll_loops.oscar.nc.BaseInterface;

class Base<T_NATIVE_COMMUNICATOR extends de.funroll_loops.oscar.nc.BaseInterface> {
	protected T_NATIVE_COMMUNICATOR m_nc;
	protected long m_ptr;
	
	protected T_NATIVE_COMMUNICATOR nc() {
		return m_nc;
	}
	
	//checked version of nc, calls throws_on_invalid
	protected T_NATIVE_COMMUNICATOR cnc() {
		throw_on_invalid();
		return nc();
	}
	
	protected long ptr() {
		return m_ptr;
	}
	
	protected void finalize() throws Throwable {
		try {
			close();
		}
		finally {
			super.finalize();
		}
	}
	
	protected void close() {
		if (valid()) {
			nc().destroy( ptr() );
		}
	}

	protected void throw_on_invalid() {
		if (!valid()) {
			throw new java.lang.NullPointerException();
		}
	}
	
	//public functions
	
	public Base() {
		m_ptr = BaseInterface.null_pointer;
	}
	
	public Base(T_NATIVE_COMMUNICATOR _nc, long _ptr) {
		m_nc = _nc;
		m_ptr = _ptr;
	}
	
	public Base(T_NATIVE_COMMUNICATOR _nc) {
		m_nc = _nc;
		m_ptr = nc().create();
	}
	
	public boolean valid() {
		return m_ptr != BaseInterface.null_pointer;
	}
}