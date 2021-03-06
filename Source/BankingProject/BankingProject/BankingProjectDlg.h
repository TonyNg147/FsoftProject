
// BankingProjectDlg.h : header file
//

#pragma once
#include "CWaitingMsgDialog.h"
#include "CWithdrawDlg.h"
#include "CWithdrawAnother0.h"
#include "CContinueDlg.h"
#include "CMainDlg.h"


// CBankingProjectDlg dialog
class CBankingProjectDlg : public CDialogEx
{
// Construction
public:
	CBankingProjectDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_BANKINGPROJECT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

private:
	CButton m_btTest;
	CMenu m_menu;

public:
	void LayoutControl();

	CWaitingMsgDialog m_waitingMsgDlg;
	afx_msg void OnPhulh1WaitingscMain();
	/*
		SangTH5 editer
	*/
	afx_msg void OnSangth5Balancedlg();
	/*
		end Sang editer
	*/
	afx_msg void OnTrangpt24Withdraw();
	afx_msg void OnTrangpt24Another();
	afx_msg void OnPhulh1Continuescr();
	afx_msg void OnPhulh1Mainscr();
};
