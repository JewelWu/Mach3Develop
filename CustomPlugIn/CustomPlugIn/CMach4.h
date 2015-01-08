// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "C:\\Mach3\\Mach3.exe" no_namespace
// CMach4 wrapper class

class CMach4 : public COleDispatchDriver
{
public:
    CMach4(){} // Calls COleDispatchDriver default constructor
    CMach4(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
    CMach4(const CMach4& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

    // Attributes
public:

    // Operations
public:


    // IMach4 methods
public:
    void LoadGCodeFile(LPCTSTR FileName)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
    }
    void CloseFile()
    {
        InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    LPDISPATCH GetScriptDispatch()
    {
        LPDISPATCH result;
        InvokeHelper(0x3, DISPATCH_METHOD, VT_DISPATCH, (void*)&result, NULL);
        return result;
    }
    void ShutDown()
    {
        InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void GetAxisPosition(double * Xpos, double * Ypos, double * Zpos, double * Apos, double * Bpos, double * Cpos)
    {
        static BYTE parms[] = VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 VTS_PR8 ;
        InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Xpos, Ypos, Zpos, Apos, Bpos, Cpos);
    }
    void CycleStart()
    {
        InvokeHelper(0x6, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void FeedHold()
    {
        InvokeHelper(0x7, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void RewindGcode()
    {
        InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    long GetLineNumber()
    {
        long result;
        InvokeHelper(0x9, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
        return result;
    }
    void SetFRO(double FeedOverride)
    {
        static BYTE parms[] = VTS_R8 ;
        InvokeHelper(0xa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FeedOverride);
    }
    CString GetRev()
    {
        CString result;
        InvokeHelper(0xb, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }

    // IMach4 properties
public:

};
