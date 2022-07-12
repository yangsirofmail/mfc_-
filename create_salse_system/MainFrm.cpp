
// MainFrm.cpp : CMainFrame ���ʵ��
//

#include "stdafx.h"
#include "create_salse_system.h"

#include "MainFrm.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CMainFrame

IMPLEMENT_DYNCREATE(CMainFrame, CFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CFrameWnd)
	ON_WM_CREATE()
	ON_MESSAGE(NM_A,OnMyChange)
	ON_MESSAGE(NM_B, OnMyChange)
	ON_MESSAGE(NM_C, OnMyChange)
	ON_MESSAGE(NM_D, OnMyChange)
	ON_MESSAGE(NM_E, OnMyChange)


	ON_COMMAND(ID_32773, &CMainFrame::On32773)
	ON_COMMAND(ID_32774, &CMainFrame::On32774)
	ON_COMMAND(ID_32775, &CMainFrame::On32775)
	ON_COMMAND(ID_32776, &CMainFrame::On32776)
	ON_COMMAND(ID_32777, &CMainFrame::On32777)
	ON_COMMAND(ID_32778, &CMainFrame::On32778)
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR,           // ״̬��ָʾ��
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame ����/����

CMainFrame::CMainFrame()
{
	// TODO: �ڴ���ӳ�Ա��ʼ������
}

CMainFrame::~CMainFrame()
{
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!m_wndStatusBar.Create(this))
	{
		TRACE0("δ�ܴ���״̬��\n");
		return -1;      // δ�ܴ���
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//
	//���������ڵ�ͼ�� ����ͳ�ʼλ�úʹ��ڴ�С

	//����ͼ�꣬IDI_ICON_WINΪͼ����ԴID����ΪWINAPI����
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_WIN));
	//���ô��ڵ�λ�úʹ�С��CWnd::MoveWindow
	//0, 0, �������x��y
	//800, 500, ���ڿ�Ⱥ͸߶�
	MoveWindow(0, 0, 800, 500);

	//�������ƶ�����Ļ���룬CWnd::CenterWindow
	CenterWindow();

	//���ô��ڱ��⣬CDocument::SetTitle
	SetTitle(TEXT("2021:9:10"));


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return TRUE;
}

// CMainFrame ���

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CFrameWnd::Dump(dc);
}
#endif //_DEBUG


// CMainFrame ��Ϣ�������


//�Զ�����Ϣ�Ļص����� �������ڵĴ��� 
LRESULT CMainFrame::OnMyChange(WPARAM wPAram, LPARAM lParam)
{
	CCreateContext   Context;

	switch (wPAram)
	{
	case NM_A:
	{
		


		Context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);//��ʱ�����µ�Ҳ���Ǵ������ര��
		Context.m_pCurrentFrame = this;//��¼�������
		Context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);//��ȡԭ���ĵ�0�е�1�еĿմ���
		m_spliter.DeleteView(0, 1);//ͨ����ִ��ڵĶ��� ɾ����0�еĵ�1�д���
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(600, 500), &Context);// ��0��1�д�����ʱ����Ĵ���
		CUserDlg *pNewView = (CUserDlg *)m_spliter.GetPane(0, 1);//��ȡ�´��ڵ�λ��
		m_spliter.RecalcLayout();//���½�����в���
		pNewView->OnInitialUpdate();//���ҵ����´��ڵĳ�ʼ��������ʼ�����´���
		m_spliter.SetActivePane(0, 1);//�����´���
	}
	break;
	case NM_B:
	{
		//CSellDlg����Ҫ����ͷ�ļ�#include "SellDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CSellDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CSellDlg), CSize(600, 0), &Context);
		CSellDlg *pNewView = (CSellDlg *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}
		break;
	case NM_C:
	{


		//CInfoDlg����Ҫ����ͷ�ļ�#include "InfoDlg.h"
		Context.m_pNewViewClass = RUNTIME_CLASS(CInfoDlg);
		Context.m_pCurrentFrame = this;
		Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
		m_spliter.DeleteView(0, 1);
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CInfoDlg), CSize(600, 0), &Context);
		CInfoDlg *pNewView = (CInfoDlg *)m_spliter.GetPane(0, 1);
		m_spliter.RecalcLayout();
		pNewView->OnInitialUpdate();
		m_spliter.SetActivePane(0, 1);
	}

		break;
	case NM_D:
		{
			//CInfoDlg����Ҫ����ͷ�ļ�#include "InfoDlg.h"
			Context.m_pNewViewClass = RUNTIME_CLASS(CAddDlg);
			Context.m_pCurrentFrame = this;
			Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
			m_spliter.DeleteView(0, 1);
			m_spliter.CreateView(0, 1, RUNTIME_CLASS(CAddDlg), CSize(600, 0), &Context);
			CAddDlg *pNewView = (CAddDlg *)m_spliter.GetPane(0, 1);
			m_spliter.RecalcLayout();
			pNewView->OnInitialUpdate();
			m_spliter.SetActivePane(0, 1);
		}
		break;
	case NM_E:
	
		{
			//CDelDlg����Ҫ����ͷ�ļ�#include "DelDlg.h"
			Context.m_pNewViewClass = RUNTIME_CLASS(CDelDlg);
			Context.m_pCurrentFrame = this;
			Context.m_pLastView = (CFormView *)m_spliter.GetPane(0, 1);
			m_spliter.DeleteView(0, 1);
			m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDelDlg), CSize(600, 0), &Context);
			CDelDlg *pNewView = (CDelDlg *)m_spliter.GetPane(0, 1);
			m_spliter.RecalcLayout();
			pNewView->OnInitialUpdate();
			m_spliter.SetActivePane(0, 1);
		}

		break;
		
	default:
		MessageBox(_T("error"));
	}


	return 0;
}
//��̬��� window�ĵ�
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: �ڴ����ר�ô����/����û���

	// ��̬��ִ��ڣ�1��2�У�CSplitterWnd::CreateStatic
	m_spliter.CreateStatic(this, 1, 2);

	// ������ͼ��CSplitterWnd::CreateView
	//0, 0 �� ���ڵ�0�е�0�е�λ��
	//RUNTIME_CLASS(CSelectView) ����Ҫͷ�ļ�#include "SelectView.h"�� CSelectView��SelectView.h������
	// CSize(250, 500)��ָ����ͼ��Ⱥ͸߶�
	//pContext �� ΪOnCreateClient()���һ���β�
	m_spliter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 500), pContext);

	//0, 1�� ���ڵ�0�е�1�е�λ��
	//CDispalyView����Ҫͷ�ļ�#include "DispalyView.h"
	m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDispalyView), CSize(600, 500), pContext);

	return TRUE;

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}


//�˵��� ����


void CMainFrame::On32773()
{
	// TODO: �ڴ���������������
	//::postMessage�����Զ�����Ϣ AfxGetMainWnd��ȡ������ GetSafeHwnd��ô��ھ��
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);

}


void CMainFrame::On32774()
{
	//::postMessage�����Զ�����Ϣ
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
}


void CMainFrame::On32775()
{
//::postMessage�����Զ�����Ϣ
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
}


void CMainFrame::On32776()
{
	// TODO: �ڴ���������������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
}


void CMainFrame::On32777()
{
	// TODO: �ڴ���������������
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
}


void CMainFrame::On32778()
{
	// TODO: �ڴ���������������
	exit(0);
}
