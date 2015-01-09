// PluginTestDlg.cpp : implementation file
//

#include "stdafx.h"
#include "CustomPlugIn.h"
#include "PluginTestDlg.h"
#include "afxdialogex.h"
#include "dbg.h"

#include "CMyScriptObject.h"
#include "Mach3Button.h"
#include "Mach3ObjectModel.h"

extern CMyScriptObject scripter;
extern bool bAbsDistanceMode;

enum EDISTANCE_MODE
{
    ABSOLUTE_DISTANCE = 0,
    INCREMENTAL_DISTANCE,
    MAX_DISTANCE
};


// CPluginTestDlg dialog

IMPLEMENT_DYNAMIC(CPluginTestDlg, CDialog)

CPluginTestDlg::CPluginTestDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPluginTestDlg::IDD, pParent)
    , m_nDistanceMode( ABSOLUTE_DISTANCE )
{

}

CPluginTestDlg::~CPluginTestDlg()
{
}

void CPluginTestDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialog::DoDataExchange(pDX);
    DDX_Radio(pDX, IDC_RADIO_ABSOLUTE_DISTANCE, m_nDistanceMode);
	DDV_MinMaxInt(pDX, m_nDistanceMode, ABSOLUTE_DISTANCE, MAX_DISTANCE);
}

void CPluginTestDlg::InitUI()
{
    m_nDistanceMode = ( bAbsDistanceMode ) ? ABSOLUTE_DISTANCE : INCREMENTAL_DISTANCE;

    UpdateData( FALSE );

    DbgMsg(("InitUI: bAbsDistanceMode= %d", bAbsDistanceMode ));
}

BEGIN_MESSAGE_MAP(CPluginTestDlg, CDialog)
    ON_BN_CLICKED(IDOK, &CPluginTestDlg::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &CPluginTestDlg::OnBnClickedCancel)
    ON_BN_CLICKED(IDC_RESET, &CPluginTestDlg::OnBnClickedReset)
    ON_BN_CLICKED(IDC_LOAD_RR, &CPluginTestDlg::OnBnClickedLoadRr)
    ON_BN_CLICKED(IDC_RUN_RR, &CPluginTestDlg::OnBnClickedRunRr)
    ON_BN_CLICKED(IDC_RADIO_INCREMENTAL_DISTANCE, &CPluginTestDlg::OnBnClickedRadioIncrementalDistance)
    ON_BN_CLICKED(IDC_RADIO_ABSOLUTE_DISTANCE, &CPluginTestDlg::OnBnClickedRadioAbsoluteDistance)
END_MESSAGE_MAP()


// CPluginTestDlg message handlers


void CPluginTestDlg::OnBnClickedOk()
{
    DbgMsg(("OnBnClickedOk entry"));

    ShowWindow(SW_HIDE);

    DbgMsg(("OnBnClickedOk exit"));

    //CDialog::OnOK();
}


void CPluginTestDlg::OnBnClickedCancel()
{
    DbgMsg(("OnBnClickedCancel entry"));

    ShowWindow(SW_HIDE);

    DbgMsg(("OnBnClickedCancel exit"));
    //CDialog::OnCancel();
}


void CPluginTestDlg::OnBnClickedReset()
{
    DoButton(MACH3_RESET);	// Reset (1021)
}


void CPluginTestDlg::OnBnClickedLoadRr()
{
    //scripter.LoadFile("C:\\Mach3\\GCode\\roadrunner.tap");
    LoadGcodeFile( "C:\\Mach3\\GCode\\roadrunner.tap" );
}


void CPluginTestDlg::OnBnClickedRunRr()
{
    DoButton(CYCLE_START);
}


void CPluginTestDlg::OnBnClickedRadioIncrementalDistance()
{
    SwitchDistanceMode( FALSE );
    UpdateData( TRUE );
}


void CPluginTestDlg::OnBnClickedRadioAbsoluteDistance()
{
    SwitchDistanceMode( TRUE );
    UpdateData( TRUE );
}
