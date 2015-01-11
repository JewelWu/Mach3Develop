// CustomPlugInImpl.cpp  

#include "stdafx.h"
#include "resource.h"
#include "TrajectoryControl.h"
#include "Mach4View.h"
#include "Engine.h"
#include "rs274ngc.h"
#include "XMLProfile.h"

#include "CustomPlugInImpl.h"
#include "PluginTestDlg.h"
#include "Mach3ObjectModel.h"
#include "Utility.h"
#include "dbg.h"

#include <mmsystem.h>
#include <math.h> 

#define WM_CUSTOM_PLUGIN_OPEN   WM_USER + 1

bool MachWindowFound = false;
HWND mach3Wnd;
CWnd mach3CWnd;
int RangeStart = 0;

CPluginTestDlg *dlg;

// ===========================================================================
// 
// Global variables for this code 
//
// ===========================================================================

extern CMach4View *MachView;

 
//============================================================================
//
// Here are the routines which are called by Mach3
// They are the core of every plugin
//
//============================================================================

//----------------------------------------------------------------------------

// Used for destruction of variables prior to exit.
// Called as Mach3 shuts down. 

void myCleanUp()

{
	DbgMsg(("myCleanUp entry"));

    Mach3ObjectModelShutdown();

    if ( dlg )
    {
        dlg->DestroyWindow();
    }
    
    mach3CWnd.Detach();

    if ( dlg )
    {
        delete dlg;
    }    

	DbgMsg(("myCleanUp exit"));
}

//----------------------------------------------------------------------------

// initial access to Mach profile when enumerating available plugins
// Returns the second half on the "pluging id" for the list in Operator
// CustomPlugIn adds the file name at the start of the string

CString	myProfileInit(CString name, CXMLProfile *DevProf)	

{
	DbgMsg(("myProfileInit entry"));

	//this gets the default directory DefDir in which Mach3 is located.  and the profile name ex. "Mach3Mill"
	//DefDir = DevProf->GetProfileString("Preferences","DefDir","C:\\Mach3\\");
    //Profile = DevProf->GetProfileString("Preferences","Profile","Mach3Mill");

	DbgMsg(("myProfileInit exit"));

	return(" CustomPlugIn PlugIn - James W. Leonard Ver 1.0");
}

//----------------------------------------------------------------------------

// called during Mach initialisation. You can influence subsequent init by actions here
// **** Not used in typical device plugin

void myInitControl()

{
	DbgMsg(("myInitControl entry"));

    RangeStart  = GetMenuRange( 1 ); //we request 2 menu ID's to use..

	DbgMsg(("myInitControl exit"));
}

//----------------------------------------------------------------------------

void myPostInitControl()

{
	// called when mach fully set up so all data can be used but initialization  outcomes not affected

	DbgMsg(("myPostInitControl entry"));

#ifndef _DEBUG

    RelMsg(("Release build CustomPlugin"));

#endif

    /*mach3Wnd = GetMach3MainWindow();

    mach3CWnd.Attach(mach3Wnd);

    dlg = new CPluginTestDlg;

    dlg->Create(IDD_PLUGIN_TEST, &mach3CWnd);

    Mach3ObjectModelStartup();*/

    AfxBeginThread( ProcessFindMach3, NULL);

    //static bool menued = false;
    //if ( !menued )
    //{
    //    DbgMsg(("menued"));
    //    //" Startup of Menu handler"
    //    menued = true;
    //    CFrameWnd *MachFrame = MachView->MachFrame;
    //    if ( MachFrame )
    //    {
    //        DbgMsg(("MachFrame"));
    //        CMenu *menu = MachFrame->GetMenu();
    //        if ( menu )
    //        {
    //            DbgMsg(("menu"));
    //            int pos = FindMenuItem( menu, "PlugIn Control" );
    //            //here we can add menu items to Mach3's menu..
    //            HMENU control = GetSubMenu( menu->m_hMenu, pos);
    //            InsertMenu ( control, -1, MF_BYPOSITION, WM_CUSTOM_PLUGIN_OPEN, "CustomPlugin" );
    //        }
    //    }
    //}
    
	DbgMsg(("myPostInitControl exit"));
}

//----------------------------------------------------------------------------

// Called to configure the device
// Has read/write access to Mach XML profile to remember what it needs to.

void myConfig(CXMLProfile *DevProf)

{
	DbgMsg(("myConfig entry"));

    GetCurAbsoluteMode();
    dlg->InitUI();
    dlg->ShowWindow(SW_SHOW);

	DbgMsg(("myConfig exit"));
}

//----------------------------------------------------------------------------

// 10Hz update loop

void myUpdate()

{
	//DbgMsg(("myUpdate entry"));

    if (MachWindowFound == true)
    {
        DbgMsg(("myUpdate entry"));

        MachWindowFound = false;
        CreateDlgOutside();

        DbgMsg(("myUpdate exit"));
    }

	//DbgMsg(("myUpdate exit"));
}

//----------------------------------------------------------------------------

// called at 40Hz. This is used for Higher Res timing needs. 
// only use as required, it can use alot of system resources. 

void myHighSpeedUpdate()

{
	// DbgMsg(("myHighSpeedUpdate entry"));

	
	// DbgMsg(("myHighSpeedUpdate exit"));
}

//----------------------------------------------------------------------------

void myNotify(int ID)
{
    //DbgMsg(("myNotify entry"));

    if (ID == RangeStart)
    {
        GetCurAbsoluteMode();
        if ( dlg )
        {
            dlg->InitUI();
            dlg->ShowWindow(SW_SHOW);
        }
        else
        {
            DbgMsg(("myNotify: dlg NULL"));
        }
    }

    //DbgMsg(("myNotify exit"));
}

//----------------------------------------------------------------------------

// ======================================================================================================
//
// The Helpers follow
//
//=======================================================================================================

// put your helper routines here

UINT  ProcessFindMach3( LPVOID param )
{
    DbgMsg(("ProcessFindMach3 entry"));

    do {
        EnumWindows(EnumWindowsProc2, NULL);
    }while(mach3Wnd==NULL);
    
    MachWindowFound = true;
    DbgMsg(("ProcessFindMach3: Find mach3 window"));

    return 0;
}

BOOL CALLBACK EnumWindowsProc2(HWND hWnd, LPARAM lParam)
{
    char String[255];

    if (!hWnd)
    {
        return TRUE;      // Not a window
    }
    if (!::IsWindowVisible(hWnd))
    {
        return TRUE;      // Not visible
    }
    if (!SendMessage(hWnd, WM_GETTEXT, sizeof(String), (LPARAM)String))
    {
        return TRUE;      // No window title
    }

    GetWindowText(hWnd,String,0);
    CString toto(String);

    if (toto.Find("Mach3 CNC ",0) !=-1)
    {
        DbgMsg(("EnumWindowsProc2: Find Mach3 window."));
        mach3Wnd=hWnd;
        return 1;
    }

    return TRUE;
}

void CreateDlgOutside(void)
{
    DbgMsg(("CreateDlgOutside entry"));

    if ( mach3Wnd == NULL )
    {
        DbgMsg(("CreateDlgOutside: NULL mach3Wnd"));
        return;
    }

    mach3CWnd.Attach(mach3Wnd);
    dlg = new CPluginTestDlg;
    dlg->Create(IDD_PLUGIN_TEST, &mach3CWnd);
    Mach3ObjectModelStartup();

    static bool menued = false; 
    if( !menued) 
    { 
        DbgMsg(("CreateDlgOutside: menued"));

        //" Startup of Menu handler" 
        menued = true;
        if (mach3Wnd != NULL)
        {
            CMenu *menu = mach3CWnd.GetMenu();
            if ( menu )
            {
                int pos = FindMenuItem( menu, "PlugIn Control" );
                //here we can add menu items to Mach3's menu..
                HMENU control = GetSubMenu( menu->m_hMenu, pos);
                InsertMenu ( control, -1, MF_BYPOSITION, RangeStart, "ÂX¥R¥\¯à" );
                mach3CWnd.DrawMenuBar(); 
            }
        }
    }

    DbgMsg(("CreateDlgOutside exit"));
}