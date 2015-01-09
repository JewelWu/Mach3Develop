// CustomPlugInImpl.h : main header file for the user implementation code of the plugin
// Include near the end of the #Include list

#pragma once

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

typedef void (CALLBACK *NoParms) ();
typedef void (_cdecl *OneShort) ( short );
typedef double (_cdecl *DoubleShort) ( short );
typedef void (_cdecl *DoubleShortDouble) ( short , double );
typedef bool (_cdecl *BoolShort) ( short );
typedef void (_cdecl *CSTRret) ( CString );
typedef void (_cdecl *VoidLPCSTR) (LPCTSTR );
typedef int  (_cdecl *IntShort) ( short );

// ===========================================================================================
//
// Here are the entry points to the implementation to be called by Mach3

// initial access to Mach profile
// when enumerating available plugins

CString	myProfileInit(CString name, CXMLProfile *DevProf);

// called during Mach initialization
// you can influence subsequent init by actions here
// **** Not used in typical device plugin

void myInitControl();									

// called when mach is fully set up

void myPostInitControl();

// Called to configure the device

void myConfig(CXMLProfile *DevProf);

// 10Hz update loop

void myUpdate();

// called at 40Hz

void myHighSpeedUpdate();

// Used to cleanup heap variables before destruction of PlugIn

void myCleanUp();

 // homing and probing calls from Mach3.

void myHome(short axis);

void myProbe();            

void myNotify(int ID);

// ==================================================================================================
//
// Here are the main data areas with which the implementor will do his/her work
//
// ==================================================================================================

// These pointers are set up in the code during init of DLL

// ************** Beware *****************
// You can alter almost anything and so hasten the end of the world as we know it

extern TrajectoryControl *MainPlanner;	// used for most planner funcitons and program control 
extern CMach4View *MachView;			// used for most framework and configuration calls. 
extern TrajBuffer *Engine;				// Ring0 memory for printer port control and other device syncronisation
extern setup *_setup;					// Trajectory planners setup block. Always in effect

// =====================================================================================================
//
// Here are the pointers to the functions we can call in Mach 3
//
// =====================================================================================================

extern OneShort           DoButton;     // void DoButton(code)
extern DoubleShort        GetDRO;       // Double GetDRO(code)
extern DoubleShortDouble  SetDRO;       // void SetDRO(short code, double value);
extern BoolShort          GetLED;       // bool GetLED(short code);
extern CSTRret            GetProName;   // CString GetProName()
extern VoidLPCSTR         Code;         // void Code("G0X10Y10");
extern IntShort           GetMenuRange;

// =====================================================================================================

UINT  ProcessFindMach3( LPVOID param );
BOOL CALLBACK EnumWindowsProc2(HWND hWnd, LPARAM lParam);
void CreateDlgOutside(void);