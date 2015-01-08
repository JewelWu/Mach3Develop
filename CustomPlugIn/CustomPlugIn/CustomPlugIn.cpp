// CustomPlugIn.cpp : Defines the initialization routines for the DLL.

#include "stdafx.h"
#include "resource.h"
#include "CustomPlugIn.h"
#include "TrajectoryControl.h"
#include "Mach4View.h"
#include "Engine.h"
#include "rs274ngc.h"
#include "XMLProfile.h"

#pragma warning(disable:4005) // kills redef errors from resources.

//----------------------------------------------------------------------------

// This is a Generalized Device file
// The actual device is implemented in the file with these entries. 
// Conventionally this is CustomPlugInImpl.cpp

// Here are the routines in the implementors file

// initial access to Mach profile
// when enumerating available plugins

extern CString myProfileInit(CString, CXMLProfile*);	

// called during Mach initialisation
// you can influence subsequent init by actions here
// **** Not used in typical device plugin

extern void	myInitControl();								

// called when mach fully set up

extern void	myPostInitControl();

// Called to configure the device

extern void	myConfig(CXMLProfile*);

// 10Hz update loop

extern void	myUpdate();

// called at 40Hz

extern void	myHighSpeedUpdate();

//Destruction routine for cleanup

extern void myCleanUp();
 
//----------------------------------------------------------------------------
 
// System Variables

CXMLProfile		*DevProf;
OneShort		DoButton;     // void DoButton(code);
DoubleShort		GetDRO;       // Double GetDRO(code);
VoidShortDouble	SetDRO;       // void   SetDRO(short code, double value);
BoolShort		GetLED;       // bool   GetLED(short code);
VoidShortBool	SetLED;       // void	SetLED();
CSTRret			GetProName;   // CString GetProName();
VoidLPCSTR		Code;         // void Code("G0X10Y10");

// High spped thread data block

bool KickTimer = false; //this will be a special case variable. See Update loop;
bool TimerOn = false;   // this tells us the timer is not yet running. (See Update Loop );
 
// CXMLProfile

CXMLProfile *AppProf;
CString ProfileName;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Mach3 defines of External Variables. These var's are directly usable in this dll as they are all 
// instantiated prior to this dll being opened. Most work in Mach can be done by attaching to these variables 
// You cannot, however, call functions in these classes, they are not bound to the plugin. You may only call 
// the functions instantiated in thsi dll. All variables and structures , however, may be used.
// Note the way this example uses various objects.

TrajectoryControl *MainPlanner;	// used for most planner funcitons and program control 
CMach4View *MachView;			// used for most framework and configuration calls. 
TrajBuffer *Engine;				//Ring0 memory for printer port control and other device syncronisation
setup *_setup;					//Trajectory planners setup block. Always in effect
 
// CCustomPlugInApp

// Following routines are for this DLL to function properly
// They are used to create and lock the instinces of this dll. The Dll can be loaded mumiple times, so locks are maintained. 
// Most users can ignore these functions.. Look further down for the start of the Mach callback functions.

BEGIN_MESSAGE_MAP(CCustomPlugInApp, CWinApp)
END_MESSAGE_MAP()

//----------------------------------------------------------------------------

// CCustomPlugInApp construction

CCustomPlugInApp::CCustomPlugInApp()

{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

//----------------------------------------------------------------------------

CCustomPlugInApp::~CCustomPlugInApp()

{

}

//----------------------------------------------------------------------------

// BE SURE to use GuidGen to make a GUID for each plugin that you derive
// from this file set

// The one and only CCustomPlugInApp object

CCustomPlugInApp theApp;

//const GUID CDECL BASED_CODE _tlid =
//		{ 0xC9FB259, 0xB864, 0x40A5, { 0xB5, 0x9F, 0x65, 0xE1, 0x1E, 0x20, 0x9F, 0xC4 } };

// {C39C0776-E1CF-4fdf-9E07-07C0F35C0C5F}
const GUID CDECL BASED_CODE _tlid = 
{ 0xc39c0776, 0xe1cf, 0x4fdf, { 0x9e, 0x7, 0x7, 0xc0, 0xf3, 0x5c, 0xc, 0x5f } };


const WORD _wVerMajor = 1;
const WORD _wVerMinor = 0;

//----------------------------------------------------------------------------

// CCustomPlugInApp initialization

BOOL CCustomPlugInApp::InitInstance()

{
	CWinApp::InitInstance();

	if (!AfxSocketInit()) {

		AfxMessageBox("Sockets Init Failed");

		return(FALSE);
	}

	// Register all OLE server (factories) as running.  This enables the
	// OLE libraries to create objects from other applications.

	COleObjectFactory::RegisterAll();

	return(TRUE);
}

//----------------------------------------------------------------------------

// DllGetClassObject - Returns class factory

STDAPI DllGetClassObject(REFCLSID rclsid, REFIID riid, LPVOID* ppv)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return(AfxDllGetClassObject(rclsid, riid, ppv));
}

//----------------------------------------------------------------------------

// DllCanUnloadNow - Allows COM to unload DLL

STDAPI DllCanUnloadNow(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	return(AfxDllCanUnloadNow());
}

//----------------------------------------------------------------------------

// DllRegisterServer - Adds entries to the system registry

STDAPI DllRegisterServer(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	if (!AfxOleRegisterTypeLib(AfxGetInstanceHandle(), _tlid))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll())
		return SELFREG_E_CLASS;

	return(S_OK);
}

//----------------------------------------------------------------------------

// DllUnregisterServer - Removes entries from the system registry

STDAPI DllUnregisterServer(void)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
    
	if (!AfxOleUnregisterTypeLib(_tlid, _wVerMajor, _wVerMinor))
		return SELFREG_E_TYPELIB;

	if (!COleObjectFactory::UpdateRegistryAll(FALSE))
		return SELFREG_E_CLASS;

	return(S_OK);
}

//----------------------------------------------------------------------------

// Callback Functions are instantiated here for general use.
// Get the Callbacks to the Mach3 System

//----------------------------------------------------------------------------

// void DoButton(short code);

extern "C" __declspec(dllexport) void SetDoButton(OneShort pFunc)

{
	DoButton = pFunc; 
}

//----------------------------------------------------------------------------

 // void SetDRO(short code, double value);

extern "C" __declspec(dllexport) void SetSetDRO(VoidShortDouble pFunc)

{
	SetDRO = pFunc; 
}

//----------------------------------------------------------------------------

// double GetDRO(short code);

extern "C" __declspec(dllexport) void SetGetDRO(DoubleShort pFunc)

{
	GetDRO = pFunc; 
}

//----------------------------------------------------------------------------

// bool GetLED(short code);

extern "C" __declspec(dllexport) void SetGetLED(BoolShort pFunc)  

{
	GetLED = pFunc; 
}

//----------------------------------------------------------------------------

// bool GetLED( short code );

extern "C" __declspec(dllexport) void SetSetLED(VoidShortBool pFunc)  

{
	SetLED = pFunc; 
}

//----------------------------------------------------------------------------

// bool GetLED(short code);

extern "C" __declspec(dllexport) void SetCode(VoidLPCSTR pFunc)  

{
	Code = pFunc; 
}

//----------------------------------------------------------------------------

// CString GetProfName();

extern "C" __declspec(dllexport) char* SetProName( CString name)  

{
	static CString strPlgName, strVer;

	ProfileName =   name;

	DevProf = new  CXMLProfile(); //start up the Profile class for XML usage. Same as Mach3's. 
	 
	strVer = myProfileInit(name, DevProf); // call implementors code

	strPlgName = AfxGetApp()->m_pszExeName + strVer;

	delete DevProf;
	  
	return((char*)(LPCTSTR)(strPlgName));  
}   

//----------------------------------------------------------------------------

// Calls into the DLL
//*****************************************************
//
// Mach3 Calls to the Plugin Follow
//
// Tells Mach3 whether to start the printer driver in Ring 0 or not. Return false to run a different device.
// Also gives access to parameter blocks and variables from the 4 main classes of Mach3. 

//This is a timer loop set for 25ms to keep latency low. We do need to disable it though
//if the callback loop is not running. 

//----------------------------------------------------------------------------

extern "C" __declspec(dllexport) void StopPlug(void)  

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	myCleanUp(); 
}

//----------------------------------------------------------------------------

extern "C" __declspec(dllexport) void DoDwell(double time)  

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));
}

//----------------------------------------------------------------------------

VOID CALLBACK MYProc(HWND hwnd,UINT uMsg,UINT_PTR idEvent,DWORD dwTime)

{
	static int ticks = 0;
  
	// If the update loop doesnt turn this back on in 20 ticks. ( 1/2 second) then kill the timer, user 
	// has shut us down. 
	
	ticks++;
	
	if ((ticks > 20) && (!KickTimer)) {

		KillTimer(hwnd, idEvent);

		TimerOn = false;
	}

	// Alternately , lets make sure the user has us selected, if so, keep the timer running
	// in an indefinite loop of 40hz. 
	
	if (KickTimer) { 
	
		KickTimer = false;

		ticks = 0; //reset the test

		TimerOn = true;
	}

	// We get here at 40hz only if the user has selected us as ON, and the Mach3 programs update loops are runnign correctly
	// Any interruption of Mach3 will operate as a safety watchdog and we wont get here in that case.

	myHighSpeedUpdate();
}

//----------------------------------------------------------------------------

extern "C" __declspec(dllexport) void PostInitControl()

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	//this routine is called after Mach3 has initialised. Use it as Init, BUT no usage of the XML files at all here. Only in  Init.
	//this routine is handy for changing variables that Mach3 has loaded at startup. Usually, Mach3 will permanently save any var's you change here..

	myPostInitControl(); 
}

//----------------------------------------------------------------------------

//This routine is for setting various pointers, and for shutting off the Movement Engines for an external device to use Mach3, is necessary. It
//can interrupt things from occuring.. 

extern "C" __declspec(dllexport) bool InitControl(void *oEngine , void *oSetup , void *oMainPlanner, void *oView)

{
    AFX_MANAGE_STATE(AfxGetStaticModuleState());

	Engine = (TrajBuffer*)(oEngine);

	_setup = (setup*)(oSetup);

	MachView = (CMach4View*)(oView);

	MainPlanner = (TrajectoryControl*)(oMainPlanner);
	
	TimerOn = FALSE;
    
	KickTimer = FALSE; //see update loop
	
	myInitControl();
	
	//start the printer port.. Use this for all devices that need the printer port. For now..thats all of them..

	return(TRUE);
}

//----------------------------------------------------------------------------

extern "C" __declspec(dllexport) void Config()           // CString  GetProfName();  

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	DevProf = new  CXMLProfile(); //start up the Profile class for XML usage. Same as Mach3's. 

	// XML reading and writing can occur here..

	myConfig(DevProf);

	delete DevProf; 
}

//----------------------------------------------------------------------------

// Called when Reset is pressed.

extern "C" __declspec(dllexport) void Reset() 

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());

	//Called when reset is pressed, at end of actual reset commend in Mach3. 
	//Check the Engine.Estop variable to see if we have reset or not..
}

//----------------------------------------------------------------------------

// Called when Jog is commanded. 0 for speed is Jog% jog, otherwise it is a new jog%

extern "C" __declspec(dllexport) void JogOn(short axis, short dir, double speed)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState( ));
}

//----------------------------------------------------------------------------

//Called when jog should stop on a particular axis

extern "C" __declspec(dllexport) void JogOff(short axis)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}

//----------------------------------------------------------------------------

extern "C" __declspec(dllexport) void Purge(short flags)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState());
}

//----------------------------------------------------------------------------

extern "C" __declspec(dllexport) void Probe()

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState()); 
}

//----------------------------------------------------------------------------

extern "C" __declspec(dllexport) void Home(short axis)

{
	AFX_MANAGE_STATE(AfxGetStaticModuleState()); 
}

//----------------------------------------------------------------------------

// This is your main update loop. Approx 10hz or so..
// Since the Timer refresh is too low for ModIO at only 10hz, and we want smooth control at 40hz or so, 
// we will use this loop only to shut down the main timing loop if the user disables this plugin. 
// If the plugin gets enabled, the timer procedure is kicked into life at 25ms update, or about 40hz.

// UPDATE LOOP 10 Times a Second.

extern "C" __declspec(dllexport) void Update()

{
    AFX_MANAGE_STATE(AfxGetStaticModuleState( ));

	KickTimer = true;

	//if( !TimerOn ) SetTimer(NULL, 1, 25, MYProc);

	myUpdate ();
}

//----------------------------------------------------------------------------

