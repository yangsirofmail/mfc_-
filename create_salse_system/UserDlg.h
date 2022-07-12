#pragma once


#include "InfoFile.h"
#include "UserDlg.h"
// CUserDlg ������ͼ

class CUserDlg : public CFormView
{
	DECLARE_DYNCREATE(CUserDlg)

protected:
	CUserDlg();           // ��̬������ʹ�õ��ܱ����Ĺ��캯��
	virtual ~CUserDlg();

public:
#ifdef AFX_DESIGN_TIME
	enum { IDD = DIALOG_USER };
#endif
#ifdef _DEBUG
	virtual void AssertValid() const;
#ifndef _WIN32_WCE
	virtual void Dump(CDumpContext& dc) const;
#endif
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
private:
	CString m_user1;
	CString m_name;
	CString m_newpwd;
	CString m_surepwd;
public:
	virtual void OnInitialUpdate();
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};


