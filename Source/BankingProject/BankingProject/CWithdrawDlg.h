#pragma once


// CWithdrawDlg dialog

class CWithdrawDlg : public CDialogEx
{
	DECLARE_DYNAMIC(CWithdrawDlg)

public:
	CWithdrawDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CWithdrawDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_WITHDRAW };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_InputMoney;
	CButton m_FiveMillions;
	CButton m_ThreeMillions;
	CButton m_FiveHundreds;
	CButton m_TwoMillions;
	CButton m_OneMillions;
	CButton m_Another;
	BOOL OnInitDialog();
	void LayoutControl();
};
