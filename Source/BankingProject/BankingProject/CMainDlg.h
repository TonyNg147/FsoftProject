#pragma once

#include "CWithdrawDlg.h"
#include "CBalanceHomeDlg.h"



// CMainDlg dialog

class CMainDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CMainDlg)

public:
	CMainDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CMainDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_MAIN };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()

	CStatic m_staticMainScrTopText;
	CButton m_btMainScrWithdraw;
	CButton m_btMainScrBalance;
	CButton m_btMainScrChangePin;
	CButton m_btMainScrTransferMoney;
public:
	BOOL OnInitDialog();
	void LayoutControl();
	void SetFontSize();
	void SetText();
	afx_msg void OnBnClickedButtonWidthdraw();
	afx_msg void OnBnClickedButtonBalance();
	afx_msg void OnBnClickedButtonChangePin();
	afx_msg void OnBnClickedButtonTransferMoney();
};
