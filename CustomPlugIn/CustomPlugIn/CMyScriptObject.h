// Machine generated IDispatch wrapper class(es) created with Add Class from Typelib Wizard

#import "C:\\Mach3\\Mach3.exe" no_namespace
// CMyScriptObject wrapper class

class CMyScriptObject : public COleDispatchDriver
{
public:
    CMyScriptObject(){} // Calls COleDispatchDriver default constructor
    CMyScriptObject(LPDISPATCH pDispatch) : COleDispatchDriver(pDispatch) {}
    CMyScriptObject(const CMyScriptObject& dispatchSrc) : COleDispatchDriver(dispatchSrc) {}

    // Attributes
public:

    // Operations
public:


    // IMyScriptObject methods
public:
    void StraightFeed(double x, double y, double z, double a, double b, double c)
    {
        static BYTE parms[] = VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 ;
        InvokeHelper(0x1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, x, y, z, a, b, c);
    }
    void HelpAbout()
    {
        InvokeHelper(0x2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    double GetSafeZ()
    {
        double result;
        InvokeHelper(0x3, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    void SetSafeZ(double SafeZ)
    {
        static BYTE parms[] = VTS_R8 ;
        InvokeHelper(0x4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, SafeZ);
    }
    void SetCurrentTool(short Tool)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Tool);
    }
    short GetSelectedTool()
    {
        short result;
        InvokeHelper(0x6, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    double GetToolChangeStart(short Axis)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x7, DISPATCH_METHOD, VT_R8, (void*)&result, parms, Axis);
        return result;
    }
    void StraightTraverse(double x, double y, double z, double a, double b, double c)
    {
        static BYTE parms[] = VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 VTS_R8 ;
        InvokeHelper(0x8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, x, y, z, a, b, c);
    }
    double ToolLengthOffset()
    {
        double result;
        InvokeHelper(0x9, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double CommandedFeed()
    {
        double result;
        InvokeHelper(0xa, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    void SetFeedRate(double Rate)
    {
        static BYTE parms[] = VTS_R8 ;
        InvokeHelper(0xb, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Rate);
    }
    void ActivateSignal(short Signal)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Signal);
    }
    signed char IsActive(short Signal)
    {
        signed char result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xd, DISPATCH_METHOD, VT_I1, (void*)&result, parms, Signal);
        return result;
    }
    void DeActivateSignal(short Signal)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xe, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Signal);
    }
    void SystemWaitFor(short Signal)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Signal);
    }
    double Param1()
    {
        double result;
        InvokeHelper(0x10, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double Param2()
    {
        double result;
        InvokeHelper(0x11, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double Param3()
    {
        double result;
        InvokeHelper(0x12, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    void VerifyAxis(long Silent)
    {
        static BYTE parms[] = VTS_I4 ;
        InvokeHelper(0x13, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Silent);
    }
    double GetVar(short var)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x14, DISPATCH_METHOD, VT_R8, (void*)&result, parms, var);
        return result;
    }
    void SetVar(short var, double value)
    {
        static BYTE parms[] = VTS_I2 VTS_R8 ;
        InvokeHelper(0x15, DISPATCH_METHOD, VT_EMPTY, NULL, parms, var, value);
    }
    void OpenDigFile()
    {
        InvokeHelper(0x18, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void CloseDigFile()
    {
        InvokeHelper(0x19, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void THCOn()
    {
        InvokeHelper(0x1a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void THCOff()
    {
        InvokeHelper(0x1b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void Code(LPCTSTR Command)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x1c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Command);
    }
    double GetScale(short Axis)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x1d, DISPATCH_METHOD, VT_R8, (void*)&result, parms, Axis);
        return result;
    }
    void SetScale(short Axis, double Scale)
    {
        static BYTE parms[] = VTS_I2 VTS_R8 ;
        InvokeHelper(0x1e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Axis, Scale);
    }
    void SendSerial(LPCTSTR String)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x1f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, String);
    }
    unsigned char GetPortByte(unsigned short PortAddress)
    {
        unsigned char result;
        static BYTE parms[] = VTS_UI2 ;
        InvokeHelper(0x20, DISPATCH_METHOD, VT_UI1, (void*)&result, parms, PortAddress);
        return result;
    }
    short PutPortByte(unsigned short PortAddress, unsigned char data)
    {
        short result;
        static BYTE parms[] = VTS_UI2 VTS_UI1 ;
        InvokeHelper(0x21, DISPATCH_METHOD, VT_I2, (void*)&result, parms, PortAddress, data);
        return result;
    }
    unsigned short IsMoving()
    {
        unsigned short result;
        InvokeHelper(0x22, DISPATCH_METHOD, VT_UI2, (void*)&result, NULL);
        return result;
    }
    void ResetTHC()
    {
        InvokeHelper(0x23, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    double GetParam(LPCTSTR Param)
    {
        double result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x24, DISPATCH_METHOD, VT_R8, (void*)&result, parms, Param);
        return result;
    }
    void SetParam(LPCTSTR Param, double value)
    {
        static BYTE parms[] = VTS_BSTR VTS_R8 ;
        InvokeHelper(0x25, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Param, value);
    }
    void setobj(LPCTSTR thevar, double thevalue)
    {
        static BYTE parms[] = VTS_BSTR VTS_R8 ;
        InvokeHelper(0x26, DISPATCH_METHOD, VT_EMPTY, NULL, parms, thevar, thevalue);
    }
    short GetCurrentTol()
    {
        short result;
        InvokeHelper(0x27, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    void DoOEMButton(short Button)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x28, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Button);
    }
    void LoadRun(LPCTSTR FileName)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x29, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
    }
    void DoButton(short function)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x2a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, function);
    }
    BOOL GetLED(short Led)
    {
        BOOL result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x2b, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Led);
        return result;
    }
    BOOL GetOEMLed(short Led)
    {
        BOOL result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x2c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Led);
        return result;
    }
    double GetOEMDRO(short dro)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x2d, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dro);
        return result;
    }
    double GetDRO(short dro)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x2e, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dro);
        return result;
    }
    void SetDRO(short dro, double value)
    {
        static BYTE parms[] = VTS_I2 VTS_R8 ;
        InvokeHelper(0x2f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dro, value);
    }
    void SetOEMDRO(short dro, double value)
    {
        static BYTE parms[] = VTS_I2 VTS_R8 ;
        InvokeHelper(0x30, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dro, value);
    }
    void GetCoord(LPCTSTR Question)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x31, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Question);
    }
    double GetXCoor()
    {
        double result;
        InvokeHelper(0x32, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double GetYCoor()
    {
        double result;
        InvokeHelper(0x33, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double GetZCoor()
    {
        double result;
        InvokeHelper(0x34, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double GetACoor()
    {
        double result;
        InvokeHelper(0x35, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    BOOL IsFirst()
    {
        BOOL result;
        InvokeHelper(0x36, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    void SetMachZero(short Axis)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x37, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Axis);
    }
    void RunFile()
    {
        InvokeHelper(0x38, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void SetUserDRO(short dro, double value)
    {
        static BYTE parms[] = VTS_I2 VTS_R8 ;
        InvokeHelper(0x39, DISPATCH_METHOD, VT_EMPTY, NULL, parms, dro, value);
    }
    void SetUserLED(short Led, short state)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0x3a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Led, state);
    }
    double GetUserDRO(short dro)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x3b, DISPATCH_METHOD, VT_R8, (void*)&result, parms, dro);
        return result;
    }
    short GetUserLED(short Led)
    {
        short result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x3c, DISPATCH_METHOD, VT_I2, (void*)&result, parms, Led);
        return result;
    }
    double tXStart()
    {
        double result;
        InvokeHelper(0x3d, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tZStart()
    {
        double result;
        InvokeHelper(0x3e, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tEndX()
    {
        double result;
        InvokeHelper(0x3f, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tEndZ()
    {
        double result;
        InvokeHelper(0x40, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tClearX()
    {
        double result;
        InvokeHelper(0x41, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tLead()
    {
        double result;
        InvokeHelper(0x42, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    short tSpring()
    {
        short result;
        InvokeHelper(0x43, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    short tPasses()
    {
        short result;
        InvokeHelper(0x44, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    double tChamfer()
    {
        double result;
        InvokeHelper(0x45, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tTaper()
    {
        double result;
        InvokeHelper(0x46, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tInFeed()
    {
        double result;
        InvokeHelper(0x47, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tDepthLastPass()
    {
        double result;
        InvokeHelper(0x48, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    short IsLoading()
    {
        short result;
        InvokeHelper(0x49, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    double GetABSPostion(short Axis)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x4a, DISPATCH_METHOD, VT_R8, (void*)&result, parms, Axis);
        return result;
    }
    double GetRPM()
    {
        double result;
        InvokeHelper(0x4b, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    void DoSpinCW()
    {
        InvokeHelper(0x4c, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void DoSpinCCW()
    {
        InvokeHelper(0x4d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void DoSpinStop()
    {
        InvokeHelper(0x4e, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void SetSpinSpeed(double rpm)
    {
        static BYTE parms[] = VTS_R8 ;
        InvokeHelper(0x4f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, rpm);
    }
    double InFeeds(short iteration)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x50, DISPATCH_METHOD, VT_R8, (void*)&result, parms, iteration);
        return result;
    }
    double ThreadDepth(short iteration)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x51, DISPATCH_METHOD, VT_R8, (void*)&result, parms, iteration);
        return result;
    }
    double tTapers(short iteration)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x52, DISPATCH_METHOD, VT_R8, (void*)&result, parms, iteration);
        return result;
    }
    void SetTicker(short TickerNum, LPCTSTR Message)
    {
        static BYTE parms[] = VTS_I2 VTS_BSTR ;
        InvokeHelper(0x53, DISPATCH_METHOD, VT_EMPTY, NULL, parms, TickerNum, Message);
    }
    void SetUserLabel(short LabelNum, LPCTSTR Label)
    {
        static BYTE parms[] = VTS_I2 VTS_BSTR ;
        InvokeHelper(0x54, DISPATCH_METHOD, VT_EMPTY, NULL, parms, LabelNum, Label);
    }
    void RefCombination(short combo)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x55, DISPATCH_METHOD, VT_EMPTY, NULL, parms, combo);
    }
    short IsSuchSignal(short Signal)
    {
        short result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x56, DISPATCH_METHOD, VT_I2, (void*)&result, parms, Signal);
        return result;
    }
    short OpenTeachFile(LPCTSTR name)
    {
        short result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x57, DISPATCH_METHOD, VT_I2, (void*)&result, parms, name);
        return result;
    }
    void CloseTeachFile()
    {
        InvokeHelper(0x58, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void SetButtonText(LPCTSTR Text)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x59, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Text);
    }
    void LoadStandardLayout()
    {
        InvokeHelper(0x5a, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void LoadTeachFile()
    {
        InvokeHelper(0x5b, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    BOOL IsOutputActive(short Signal)
    {
        BOOL result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x5c, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Signal);
        return result;
    }
    void SingleVerify()
    {
        InvokeHelper(0x5d, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    short GetPage()
    {
        short result;
        InvokeHelper(0x5e, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    void SetPage(short page)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x5f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, page);
    }
    void ToggleScreens()
    {
        InvokeHelper(0x60, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void PlayWave(LPCTSTR wavename)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x61, DISPATCH_METHOD, VT_EMPTY, NULL, parms, wavename);
    }
    void Speak(LPCTSTR Text)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x62, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Text);
    }
    void Message(LPCTSTR Text)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x63, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Text);
    }
    short IsStopped()
    {
        short result;
        InvokeHelper(0x64, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    void SaveWizard()
    {
        InvokeHelper(0x65, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void SingleVerifyReport(short Axis)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x66, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Axis);
    }
    void SetIJMode(short mode)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x67, DISPATCH_METHOD, VT_EMPTY, NULL, parms, mode);
    }
    short GetIJMode()
    {
        short result;
        InvokeHelper(0x68, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    double GetMinPass()
    {
        double result;
        InvokeHelper(0x69, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    short AppendTeachFile(LPCTSTR name)
    {
        short result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x6a, DISPATCH_METHOD, VT_I2, (void*)&result, parms, name);
        return result;
    }
    double Random()
    {
        double result;
        InvokeHelper(0x6b, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    short IsDiameter()
    {
        short result;
        InvokeHelper(0x6c, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    short ModGetInputWord(short bit)
    {
        short result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x6d, DISPATCH_METHOD, VT_I2, (void*)&result, parms, bit);
        return result;
    }
    short FillFromCoil(short slave, short startAddress, short nBytes)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 ;
        InvokeHelper(0x6e, DISPATCH_METHOD, VT_I2, (void*)&result, parms, slave, startAddress, nBytes);
        return result;
    }
    short FillFromStatus(short slave, short startAddress, short nBytes)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 ;
        InvokeHelper(0x6f, DISPATCH_METHOD, VT_I2, (void*)&result, parms, slave, startAddress, nBytes);
        return result;
    }
    short FillFromHolding(short slave, short startAddress, short nBytes)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 ;
        InvokeHelper(0x70, DISPATCH_METHOD, VT_I2, (void*)&result, parms, slave, startAddress, nBytes);
        return result;
    }
    short FillFromInput(short slave, short startAddress, short nBytes)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 ;
        InvokeHelper(0x71, DISPATCH_METHOD, VT_I2, (void*)&result, parms, slave, startAddress, nBytes);
        return result;
    }
    short GetModWord(short index)
    {
        short result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x72, DISPATCH_METHOD, VT_I2, (void*)&result, parms, index);
        return result;
    }
    double tMinDepth()
    {
        double result;
        InvokeHelper(0x73, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    short tGetCutType()
    {
        short result;
        InvokeHelper(0x74, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    short tGetInfeedType()
    {
        short result;
        InvokeHelper(0x75, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    void tSetCutType(short type)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x76, DISPATCH_METHOD, VT_EMPTY, NULL, parms, type);
    }
    void tSetInFeedType(short type)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x77, DISPATCH_METHOD, VT_EMPTY, NULL, parms, type);
    }
    short OpenSubroutineFile(LPCTSTR name)
    {
        short result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x78, DISPATCH_METHOD, VT_I2, (void*)&result, parms, name);
        return result;
    }
    double tZClear()
    {
        double result;
        InvokeHelper(0x79, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double FeedRate()
    {
        double result;
        InvokeHelper(0x7a, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double tCutDepth()
    {
        double result;
        InvokeHelper(0x7b, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    CString FileName()
    {
        CString result;
        InvokeHelper(0x7c, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    double MinX()
    {
        double result;
        InvokeHelper(0x7d, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double MaxX()
    {
        double result;
        InvokeHelper(0x7e, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double MinY()
    {
        double result;
        InvokeHelper(0x7f, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    double MaxY()
    {
        double result;
        InvokeHelper(0x80, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    short RetractMode()
    {
        short result;
        InvokeHelper(0x81, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    void GotoSafeZ()
    {
        InvokeHelper(0x82, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void SetPulley(short pulley)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x83, DISPATCH_METHOD, VT_EMPTY, NULL, parms, pulley);
    }
    void LoadWizard(LPCTSTR name)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x84, DISPATCH_METHOD, VT_EMPTY, NULL, parms, name);
    }
    void SetOutput(short word)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x85, DISPATCH_METHOD, VT_EMPTY, NULL, parms, word);
    }
    short GetInput(short word)
    {
        short result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x86, DISPATCH_METHOD, VT_I2, (void*)&result, parms, word);
        return result;
    }
    void SetModOutput(short reg, short value)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0x87, DISPATCH_METHOD, VT_EMPTY, NULL, parms, reg, value);
    }
    void LoadFile(LPCTSTR FileName)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x88, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
    }
    void SetTriggerMacro(short macro)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x89, DISPATCH_METHOD, VT_EMPTY, NULL, parms, macro);
    }
    void SetHomannString(short x, short y, LPCTSTR Text)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_BSTR ;
        InvokeHelper(0x8a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, x, y, Text);
    }
    void JogOn(short Axis, short dir)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0x8b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Axis, dir);
    }
    void JogOff(short Axis)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x8c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Axis);
    }
    void OpenSubFile(LPCTSTR FileName)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x8d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, FileName);
    }
    void SetToolX(double value)
    {
        static BYTE parms[] = VTS_R8 ;
        InvokeHelper(0x8e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
    }
    void SetToolZ(double value)
    {
        static BYTE parms[] = VTS_R8 ;
        InvokeHelper(0x8f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, value);
    }
    double GetTurretAng()
    {
        double result;
        InvokeHelper(0x90, DISPATCH_METHOD, VT_R8, (void*)&result, NULL);
        return result;
    }
    CString GetFiFoEntry()
    {
        CString result;
        InvokeHelper(0x91, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void RunProgram(LPCTSTR Program)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x92, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Program);
    }
    void SendFIFO(LPCTSTR com)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x93, DISPATCH_METHOD, VT_EMPTY, NULL, parms, com);
    }
    double Round(double val)
    {
        double result;
        static BYTE parms[] = VTS_R8 ;
        InvokeHelper(0x94, DISPATCH_METHOD, VT_R8, (void*)&result, parms, val);
        return result;
    }
    double roun(double val)
    {
        double result;
        static BYTE parms[] = VTS_R8 ;
        InvokeHelper(0x95, DISPATCH_METHOD, VT_R8, (void*)&result, parms, val);
        return result;
    }
    double nFmt(double val, short DEC)
    {
        double result;
        static BYTE parms[] = VTS_R8 VTS_I2 ;
        InvokeHelper(0x96, DISPATCH_METHOD, VT_R8, (void*)&result, parms, val, DEC);
        return result;
    }
    void ZeroTHC()
    {
        InvokeHelper(0x97, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    short IsWiz()
    {
        short result;
        InvokeHelper(0x98, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    void WaitForPoll()
    {
        InvokeHelper(0x99, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void SetModIOString(short slave, short x, short y, LPCTSTR OutText)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_BSTR ;
        InvokeHelper(0x9a, DISPATCH_METHOD, VT_EMPTY, NULL, parms, slave, x, y, OutText);
    }
    void Sleep(short time)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x9b, DISPATCH_METHOD, VT_EMPTY, NULL, parms, time);
    }
    void SendFIFOcr(LPCTSTR data)
    {
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0x9c, DISPATCH_METHOD, VT_EMPTY, NULL, parms, data);
    }
    void SendFIFObyte(short data)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x9d, DISPATCH_METHOD, VT_EMPTY, NULL, parms, data);
    }
    void SendFIFOword(short data)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x9e, DISPATCH_METHOD, VT_EMPTY, NULL, parms, data);
    }
    void SetTimer(short timer)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0x9f, DISPATCH_METHOD, VT_EMPTY, NULL, parms, timer);
    }
    double GetTimer(short timer)
    {
        double result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xa0, DISPATCH_METHOD, VT_R8, (void*)&result, parms, timer);
        return result;
    }
    CString AskTextQuestion(LPCTSTR Question)
    {
        CString result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0xa1, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Question);
        return result;
    }
    CString GetDROString(short nDRO)
    {
        CString result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xa2, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, nDRO);
        return result;
    }
    void LoadLinTable()
    {
        InvokeHelper(0xa3, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void SwapAxis(short Primary, short Secondary)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xa4, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Primary, Secondary);
    }
    void ResetAxisSwap()
    {
        InvokeHelper(0xa5, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void SetFormula(LPCTSTR Formula, short Axis)
    {
        static BYTE parms[] = VTS_BSTR VTS_I2 ;
        InvokeHelper(0xa6, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Formula, Axis);
    }
    short IsProbing()
    {
        short result;
        InvokeHelper(0xa7, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    short GetInBit(short index, short bit)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xa8, DISPATCH_METHOD, VT_I2, (void*)&result, parms, index, bit);
        return result;
    }
    void SetOutBit(short index, short bit)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xa9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, index, bit);
    }
    void ResetOutBit(short index, short bit)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xaa, DISPATCH_METHOD, VT_EMPTY, NULL, parms, index, bit);
    }
    void SetProbeActive(short level)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xab, DISPATCH_METHOD, VT_EMPTY, NULL, parms, level);
    }
    void StartVideo()
    {
        InvokeHelper(0xac, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void VBTest()
    {
        InvokeHelper(0xad, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void StartTHC()
    {
        InvokeHelper(0xae, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void EndTHC()
    {
        InvokeHelper(0xaf, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    void CoupleSlave(short state)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xb0, DISPATCH_METHOD, VT_EMPTY, NULL, parms, state);
    }
    double GetToolParam(short toolnum, short Param)
    {
        double result;
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xb1, DISPATCH_METHOD, VT_R8, (void*)&result, parms, toolnum, Param);
        return result;
    }
    void SetToolParam(short toolnum, short Param, double data)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_R8 ;
        InvokeHelper(0xb2, DISPATCH_METHOD, VT_EMPTY, NULL, parms, toolnum, Param, data);
    }
    void SetProbeState(short state)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xb3, DISPATCH_METHOD, VT_EMPTY, NULL, parms, state);
    }
    CString GetMainFolder()
    {
        CString result;
        InvokeHelper(0xb4, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void DoMenu(short sub, short pos)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xb5, DISPATCH_METHOD, VT_EMPTY, NULL, parms, sub, pos);
    }
    short GetMasterInput(short Param)
    {
        short result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xb6, DISPATCH_METHOD, VT_I2, (void*)&result, parms, Param);
        return result;
    }
    short GetMasterOutput(short Param)
    {
        short result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xb7, DISPATCH_METHOD, VT_I2, (void*)&result, parms, Param);
        return result;
    }
    void SetMasterOutput(short Param, short value)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xb8, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Param, value);
    }
    void SetMasterInput(short Param, short value)
    {
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xb9, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Param, value);
    }
    CString GetUserLabel(short nLabel)
    {
        CString result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xba, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, nLabel);
        return result;
    }
    CString GetToolDesc(short Tool)
    {
        CString result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xbb, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, Tool);
        return result;
    }
    void NotifyPlugins(short Message)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xbc, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Message);
    }
    short IsEstop()
    {
        short result;
        InvokeHelper(0xbd, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    short IsSafeZ()
    {
        short result;
        InvokeHelper(0xbe, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    void MachMSG(LPCTSTR Mess, LPCTSTR Title, short type)
    {
        static BYTE parms[] = VTS_BSTR VTS_BSTR VTS_I2 ;
        InvokeHelper(0xbf, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Mess, Title, type);
    }
    CString GetMessage()
    {
        CString result;
        InvokeHelper(0xc0, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    void SetModPlugString(LPCTSTR Message, short cfg, short address)
    {
        static BYTE parms[] = VTS_BSTR VTS_I2 VTS_I2 ;
        InvokeHelper(0xc1, DISPATCH_METHOD, VT_EMPTY, NULL, parms, Message, cfg, address);
    }
    void ClearFiFo()
    {
        InvokeHelper(0xc2, DISPATCH_METHOD, VT_EMPTY, NULL, NULL);
    }
    BOOL GetMachVersion(short * Major, short * Minor, short * Build)
    {
        BOOL result;
        static BYTE parms[] = VTS_PI2 VTS_PI2 VTS_PI2 ;
        InvokeHelper(0xc3, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, Major, Minor, Build);
        return result;
    }
    BOOL SetToolDesc(short ToolNumber, LPCTSTR Description)
    {
        BOOL result;
        static BYTE parms[] = VTS_I2 VTS_BSTR ;
        InvokeHelper(0xc4, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ToolNumber, Description);
        return result;
    }
    BOOL RunScript(LPCTSTR macro)
    {
        BOOL result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0xc5, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, macro);
        return result;
    }
    CString GetActiveProfileName()
    {
        CString result;
        InvokeHelper(0xc6, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    double NumberPad(LPCTSTR MessageString)
    {
        double result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0xc7, DISPATCH_METHOD, VT_R8, (void*)&result, parms, MessageString);
        return result;
    }
    long GetMyWindowsHandle()
    {
        long result;
        InvokeHelper(0xc8, DISPATCH_METHOD, VT_I4, (void*)&result, NULL);
        return result;
    }
    CString GetLoadedGCodeDir()
    {
        CString result;
        InvokeHelper(0xc9, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    CString GetLoadedGCodeFileName()
    {
        CString result;
        InvokeHelper(0xca, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    CString GetActiveProfileDir()
    {
        CString result;
        InvokeHelper(0xcb, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    CString GetActiveScreenSetName()
    {
        CString result;
        InvokeHelper(0xcc, DISPATCH_METHOD, VT_BSTR, (void*)&result, NULL);
        return result;
    }
    BOOL IncludeTLOinZFromG31()
    {
        BOOL result;
        InvokeHelper(0xcd, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    BOOL ProgramSafetyLockout()
    {
        BOOL result;
        InvokeHelper(0xce, DISPATCH_METHOD, VT_BOOL, (void*)&result, NULL);
        return result;
    }
    short GetSetupUnits()
    {
        short result;
        InvokeHelper(0xcf, DISPATCH_METHOD, VT_I2, (void*)&result, NULL);
        return result;
    }
    BOOL StartPeriodicScript(LPCTSTR ScriptPath, double UpdateTime)
    {
        BOOL result;
        static BYTE parms[] = VTS_BSTR VTS_R8 ;
        InvokeHelper(0xd0, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ScriptPath, UpdateTime);
        return result;
    }
    BOOL StopPeriodicScript(LPCTSTR ScriptPath)
    {
        BOOL result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0xd1, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, ScriptPath);
        return result;
    }
    BOOL IsPeriodicScriptRunning(LPCTSTR PathString)
    {
        BOOL result;
        static BYTE parms[] = VTS_BSTR ;
        InvokeHelper(0xd2, DISPATCH_METHOD, VT_BOOL, (void*)&result, parms, PathString);
        return result;
    }
    CString GetIODevName(short DeviceNumber)
    {
        CString result;
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xd3, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, DeviceNumber);
        return result;
    }
    short SetDevOutput(short DeviceID, short OutputNum, short value)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 ;
        InvokeHelper(0xd4, DISPATCH_METHOD, VT_I2, (void*)&result, parms, DeviceID, OutputNum, value);
        return result;
    }
    double GetIODevInput(short DeviceID, short InputNum)
    {
        double result;
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xd5, DISPATCH_METHOD, VT_R8, (void*)&result, parms, DeviceID, InputNum);
        return result;
    }
    CString GetIODevIOName(short DeviceID, short InputNumber)
    {
        CString result;
        static BYTE parms[] = VTS_I2 VTS_I2 ;
        InvokeHelper(0xd6, DISPATCH_METHOD, VT_BSTR, (void*)&result, parms, DeviceID, InputNumber);
        return result;
    }
    short SetMachPos(short Axis, double value)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_R8 ;
        InvokeHelper(0xd7, DISPATCH_METHOD, VT_I2, (void*)&result, parms, Axis, value);
        return result;
    }
    short SetInputData(short InputNumber, short PinNumber, short ActiveLow)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 ;
        InvokeHelper(0xd8, DISPATCH_METHOD, VT_I2, (void*)&result, parms, InputNumber, PinNumber, ActiveLow);
        return result;
    }
    short SetIODevDataPointers(short DeviceID, short PinNumber, short SetValueDRO, short SetOffsetDRO)
    {
        short result;
        static BYTE parms[] = VTS_I2 VTS_I2 VTS_I2 VTS_I2 ;
        InvokeHelper(0xd9, DISPATCH_METHOD, VT_I2, (void*)&result, parms, DeviceID, PinNumber, SetValueDRO, SetOffsetDRO);
        return result;
    }
    void NoDelaySpindle(short StopForSpeedChange)
    {
        static BYTE parms[] = VTS_I2 ;
        InvokeHelper(0xda, DISPATCH_METHOD, VT_EMPTY, NULL, parms, StopForSpeedChange);
    }

    // IMyScriptObject properties
public:

};
