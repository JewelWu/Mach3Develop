#pragma once

#include "resource.h"

// CPluginTestDlg dialog

class CPluginTestDlg : public CDialog
{
	DECLARE_DYNAMIC(CPluginTestDlg)

public:
	CPluginTestDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CPluginTestDlg();

    void InitUI();

// Dialog Data
	enum { IDD = IDD_PLUGIN_TEST };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
    
	DECLARE_MESSAGE_MAP()
public:
    afx_msg void OnBnClickedOk();
    afx_msg void OnBnClickedCancel();
    afx_msg void OnBnClickedReset();
    afx_msg void OnBnClickedLoadRr();
    afx_msg void OnBnClickedRunRr();
    afx_msg void OnBnClickedRadioIncrementalDistance();
    afx_msg void OnBnClickedRadioAbsoluteDistance();
    int m_nDistanceMode;
};
