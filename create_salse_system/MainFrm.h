
// MainFrm.h : CMainFrame ��Ľӿ�
//

#pragma once
#include"SelectView.h"
#include"DispalyView.h"
#include "UserDlg.h"
#include"SellDlg.h"
#include "InfoDlg.h"
#include"AddDlg.h"
#include"DelDlg.h"
#define NM_A	(WM_USER + 100)
#define NM_B	(WM_USER + 101)
#define NM_C	(WM_USER + 102)
#define NM_D	(WM_USER + 103)
#define NM_E	(WM_USER + 104)
#define NM_F	(WM_USER + 105)

class CMainFrame : public CFrameWnd
{
	
protected: // �������л�����
	CMainFrame();
	DECLARE_DYNCREATE(CMainFrame)

// ����
public:

// ����
public:

// ��д
public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);

// ʵ��
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:  // �ؼ���Ƕ���Ա
	CStatusBar        m_wndStatusBar;

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
private:
	CSplitterWnd m_spliter; // �зִ��������
							//�Զ��崦����Ϣ����
	afx_msg LRESULT OnMyChange(WPARAM wPAram, LPARAM lParam);
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
public:
	afx_msg void On32773();
	afx_msg void On32774();
	afx_msg void On32775();
	afx_msg void On32776();
	afx_msg void On32777();
	afx_msg void On32778();
};


