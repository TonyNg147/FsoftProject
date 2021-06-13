#pragma once


// CWithdrawAnother0 dialog

class CWithdrawAnother0 : public CDialogEx
{
	DECLARE_DYNAMIC(CWithdrawAnother0)

public:
	CWithdrawAnother0(CWnd* pParent = nullptr);   // standard constructor
	virtual ~CWithdrawAnother0();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DLG_WITHDRAW_ANOTHER };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CStatic m_InputMoney;
	CStatic m_MinMaxMoney;
	CButton m_Yes;
	CEdit m_EditMoney;
	CButton m_Wrong;
	BOOL OnInitDialog();
	void LayoutControl();
};
