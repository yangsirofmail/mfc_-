#pragma once
#include "afxwin.h"

#include"InfoFile.h"

// CDelDlg 窗体视图

class CDelDlg : public CFormView
{
	DECLARE_DYNCREATE(CDelDlg)

protected:
	CDelDlg();           // 动态创建所使用的受保护的构造函数
	virtual ~CDelDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_DEL };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
private:
	CComboBox m_combo;
	int m_price;
	int m_num;
public:
//	afx_msg void OnCbnSelchangeCombo2();
	virtual void OnInitialUpdate();
	afx_msg void OnCbnSelchangeCombo2();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
private:
	int m_list1;
};


