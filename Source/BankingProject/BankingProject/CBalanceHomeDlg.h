#pragma once


// CBalanceHomeDlg dialog

class CBalanceHomeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CBalanceHomeDlg)

public:
	CBalanceHomeDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CBalanceHomeDlg();

	// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_BALANCE_HOME };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	HICON m_hIcon;    //edit
	//edit
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//edit
	DECLARE_MESSAGE_MAP()
private:
	CStatic m_balanceHomeTextHeader;
	CButton m_balanceHomeButtonDefault;
	CButton m_balanceHomeButtonDeposits;
	CButton m_balanceHomeButtonSaving;
	CButton m_balanceHomeButtonCredit;
	CButton m_balanceHomeButtonReturnCash;
public:
	void LayoutControl();
	afx_msg void OnBnClickedButtonBalanceHomeDefault();
};

