// Mach3ObjectModel.h
// This library allows access to the Mach3 scripting engine
// object model

VOID Mach3ObjectModelStartup(VOID);
VOID Mach3ObjectModelShutdown(VOID);
BOOL LoadGcodeFile(CHAR *filePath);
BOOL RunGcodeFile(CHAR *filePath);
BOOL CloseGcodeFile(VOID);
BOOL CycleStart(VOID);
BOOL PushOEMButton(short button);
BOOL SwitchDistanceMode( BOOL bAbsolute );
BOOL GetCurAbsoluteMode();