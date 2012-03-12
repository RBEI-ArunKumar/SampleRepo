// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

// CServicer wrapper class

class CServicer : public COleDispatchDriver
{
public:
	CServicer(){} // Calls COleDispatchDriver default constructor
	CServicer(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
	CServicer(const CServicer& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

	// Attributes
public:

	// Operations
public:


	// IServicer methods
public:
	void Sum(long A, long B)
	{
		static BYTE parms[] = VTS_I4 VTS_I4 ;
		InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, A, B);
	}

	// IServicer properties
public:

};
