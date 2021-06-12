
// BankingProjectDlg.h : header file
//

#pragma once


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

public:
	void LayoutControl();
	CStatic m_ChooseMoney;
	CButton m_FiveMillions;
	CButton m_ThreeMillions;
	CButton m_FiveHundreds;
	CButton m_TwoMillions;
	CButton m_OneMillion;
	CButton m_Another;
};
