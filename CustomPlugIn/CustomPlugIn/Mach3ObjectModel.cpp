// Mach3ObjectModel.cpp
// This library allows access to the Mach3 scripting engine
// object model

#include "stdafx.h"

#include "CMach4.h"
#include "CMyScriptObject.h"
#include "Mach3ObjectModel.h"
#include "Mach3DRO.h"
#include "Mach3Button.h"
#include "Mach3Led.h"
#include "dbg.h"

CMach4 mach4;
CMyScriptObject scripter;
bool connected = FALSE;
BOOL bAbsDistanceMode = true;

//----------------------------------------------------------------------------

VOID Mach3ObjectModelStartup(VOID)

{
    static const IID IID_IMyScriptObject = 	{ 0xf1d3ee6c, 0xab32, 0x4996,
    { 0xb2, 0x70, 0xf4, 0x15, 0x61, 0x3f, 0x5b, 0xa3 } };
    CLSID clsid;

    PushDbgMode();

    DbgOn
        //	DbgOff

    CoInitialize(NULL);

    LPUNKNOWN lpUnk = NULL;
    LPDISPATCH lpDispatch = NULL;
    HRESULT res;

    DbgMsg(("Mach3ObjectModelStartup entry"));

    try {

        if (CLSIDFromProgID(OLESTR("Mach4.Document"),&clsid) == NOERROR) {

            if (res = GetActiveObject(clsid,NULL,&lpUnk) == NOERROR) {

                HRESULT hr = lpUnk->QueryInterface(IID_IDispatch,
                    (LPVOID*)&lpDispatch);

                lpUnk->Release();

                if (hr == NOERROR) {

                    mach4.AttachDispatch(lpDispatch, TRUE);

                    lpDispatch = mach4.GetScriptDispatch();

                    scripter.AttachDispatch(lpDispatch, TRUE);

                    connected = TRUE;

                    DbgMsg(("Mach3 control OK"));
                }
            }
        }
    }

    catch(_com_error &e) {

        com_error_msg(e);
    }

    DbgMsg(("Mach3ObjectModelStartup exit"));

    PopDbgMode();
}

//----------------------------------------------------------------------------
VOID Mach3ObjectModelShutdown(VOID)

{
    PushDbgMode();

    DbgOn
        //	DbgOff

    DbgMsg(("Mach3ObjectModelShutdown entry"));

    CoUninitialize();

    DbgMsg(("Mach3ObjectModelShutdown exit"));

    PopDbgMode();
}

//----------------------------------------------------------------------------

BOOL LoadGcodeFile(CHAR *filePath)

{
    BOOL retVal = FALSE;

    PushDbgMode();

    DbgOn
        //	DbgOff

    DbgMsg(("LoadGcodeFile entry"));

    try {

        DbgMsg(("LoadGcodeFile: filePath = %s",filePath));

        scripter.LoadFile(filePath);
    }

    catch(_com_error &e) {

        com_error_msg(e);
    }

    DbgMsg(("LoadGcodeFile exit"));

    PopDbgMode();

    return(retVal);
}

//----------------------------------------------------------------------------
BOOL RunGcodeFile(CHAR *filePath)

{
    BOOL retVal = FALSE;

    PushDbgMode();

    DbgOn
        //	DbgOff

    DbgMsg(("RunGcodeFile entry"));

    try {

        DbgMsg(("RunGcodeFile: filePath = %s",filePath));

        scripter.LoadRun(filePath);
    }

    catch(_com_error &e) {

        com_error_msg(e);
    }

    DbgMsg(("RunGcodeFile exit"));

    PopDbgMode();

    return(retVal);
}

//----------------------------------------------------------------------------

BOOL CloseGcodeFile(VOID)

{
    BOOL retVal = FALSE;

    PushDbgMode();

    DbgOn
    //	DbgOff

    DbgMsg(("CloseGcodeFile entry"));

    try {

        scripter.DoOEMButton(CLOSE_GCODE_FILE);
    }

    catch(_com_error &e) {

        com_error_msg(e);
    }

    DbgMsg(("CloseGcodeFile exit"));

    PopDbgMode();

    return(retVal);
}

//----------------------------------------------------------------------------
BOOL CycleStart(VOID)

{
    BOOL retVal = FALSE;

    PushDbgMode();

    DbgOn
        //	DbgOff

        DbgMsg(("CycleStart entry"));

    try {

        scripter.DoOEMButton(CYCLE_START);
    }

    catch(_com_error &e) {

        com_error_msg(e);
    }

    DbgMsg(("CycleStart exit"));

    PopDbgMode();

    return(retVal);
}

//----------------------------------------------------------------------------

BOOL PushOEMButton(short button)

{
    BOOL retVal = FALSE;

    PushDbgMode();

    DbgOn
        //	DbgOff

        DbgMsg(("PushOEMButton entry"));

    try {

        DbgMsg(("PushOEMButton: button = %d",button));

        scripter.DoOEMButton(button);
    }

    catch(_com_error &e) {

        com_error_msg(e);
    }

    DbgMsg(("PushOEMButton exit"));

    PopDbgMode();

    return(retVal);
}

//----------------------------------------------------------------------------
BOOL SwitchDistanceMode( BOOL bAbsolute )
{
    BOOL retVal = TRUE;

    PushDbgMode();

    DbgOn
        //	DbgOff

        DbgMsg(("SwitchDistanceMode entry"));

    try {

        DbgMsg(("SwitchDistanceMode: bAbsolute = %d", bAbsolute));

        if ( bAbsolute )
        {
            scripter.Code( "G90" ); // absolute distance mode
        }
        else
        {
            scripter.Code( "G91" ); // incremental distance mode
        }
    }

    catch(_com_error &e) {

        retVal = FALSE;
        com_error_msg(e);
    }

    DbgMsg(("SwitchDistanceMode exit"));

    PopDbgMode();

    return(retVal);
}

//----------------------------------------------------------------------------
BOOL GetCurAbsoluteMode()
{
    PushDbgMode();

    DbgOn
        //	DbgOff

        DbgMsg(("GetCurAbsoluteMode entry"));

    try {

        bAbsDistanceMode = scripter.GetOEMLed( ABS_COORD_MODE_LED );

        DbgMsg(("GetCurAbsoluteMode: bAbsolute = %d", bAbsDistanceMode));
    }

    catch(_com_error &e) {

        com_error_msg(e);
    }

    DbgMsg(("GetCurAbsoluteMode exit"));

    PopDbgMode();

    return (bAbsDistanceMode);
}