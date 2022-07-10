// evc_quicken2kDlg.h : header file
//

#if !defined(AFX_EVC_QUICKEN2KDLG_H__8ADF8C47_D9C4_11D3_B8F8_A8A030FB8471__INCLUDED_)
#define AFX_EVC_QUICKEN2KDLG_H__8ADF8C47_D9C4_11D3_B8F8_A8A030FB8471__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CEvc_quicken2kDlg dialog

class CEvc_quicken2kDlg : public CDialog
{
// Construction
public:
	CEvc_quicken2kDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CEvc_quicken2kDlg)
	enum { IDD = IDD_EVC_QUICKEN2K_DIALOG };
	CEdit	m_cUnused;
	CEdit	m_cUcode;
	CEdit	m_cSerial;
	CString	m_sSerial;
	CString	m_sUcode;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CEvc_quicken2kDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CEvc_quicken2kDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnGo();
	afx_msg void OnAbout();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_EVC_QUICKEN2KDLG_H__8ADF8C47_D9C4_11D3_B8F8_A8A030FB8471__INCLUDED_)
