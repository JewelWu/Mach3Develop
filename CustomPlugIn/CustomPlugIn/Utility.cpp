// Utility.cpp
// Utility / helper functions for Mach3 plugin authoring

#include "stdafx.h"
#include "Utility.h"
#include "dbg.h"

//----------------------------------------------------------------------------

HWND GetMach3MainWindow(VOID)

{
    HWND m3 = NULL;

    m3 = FindWindow(NULL,"Mach3 CNC Controller ");

    if (NULL != m3) {

        DbgMsg(("found Mach3 window"));
    }

    return(m3);
}

// FindMenuItem() will find a menu item string from the specified
// popup menu and returns its position (0-based) in the specified 
// popup menu. It returns -1 if no such menu item string is found.
int FindMenuItem( CMenu* Menu, LPCTSTR MenuString )
{
    ASSERT(Menu);
    ASSERT(::IsMenu(Menu->GetSafeHmenu()));

    int count = Menu->GetMenuItemCount();
    for (int i = 0; i < count; i++)
    {
        CString str;
        if (Menu->GetMenuString(i, str, MF_BYPOSITION) &&
            str.Compare(MenuString) == 0)
            return i;
    }

    return -1;
}

