
// MainFrm.cpp : CMainFrame 类的实现
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
	ID_SEPARATOR,           // 状态行指示器
	ID_INDICATOR_CAPS,
	ID_INDICATOR_NUM,
	ID_INDICATOR_SCRL,
};

// CMainFrame 构造/析构

CMainFrame::CMainFrame()
{
	// TODO: 在此添加成员初始化代码
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
		TRACE0("未能创建状态栏\n");
		return -1;      // 未能创建
	}
	m_wndStatusBar.SetIndicators(indicators, sizeof(indicators)/sizeof(UINT));
	//
	//设置主窗口的图标 标题和初始位置和窗口大小

	//设置图标，IDI_ICON_WIN为图标资源ID，此为WINAPI函数
	SetClassLong(m_hWnd, GCL_HICON, (LONG)AfxGetApp()->LoadIconW(IDI_ICON_WIN));
	//设置窗口的位置和大小：CWnd::MoveWindow
	//0, 0, 起点坐标x和y
	//800, 500, 窗口宽度和高度
	MoveWindow(0, 0, 800, 500);

	//将窗口移动到屏幕中央，CWnd::CenterWindow
	CenterWindow();

	//设置窗口标题，CDocument::SetTitle
	SetTitle(TEXT("2021:9:10"));


	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return TRUE;
}

// CMainFrame 诊断

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


// CMainFrame 消息处理程序


//自定义消息的回调函数 创建窗口的代码 
LRESULT CMainFrame::OnMyChange(WPARAM wPAram, LPARAM lParam)
{
	CCreateContext   Context;

	switch (wPAram)
	{
	case NM_A:
	{
		


		Context.m_pNewViewClass = RUNTIME_CLASS(CUserDlg);//临时保存新的也就是创建的类窗口
		Context.m_pCurrentFrame = this;//记录这个窗口
		Context.m_pLastView = (CFormView*)m_spliter.GetPane(0, 1);//获取原来的第0行第1列的空窗口
		m_spliter.DeleteView(0, 1);//通过差分窗口的对象 删除第0行的第1列窗口
		m_spliter.CreateView(0, 1, RUNTIME_CLASS(CUserDlg), CSize(600, 500), &Context);// 在0行1列创建临时保存的窗口
		CUserDlg *pNewView = (CUserDlg *)m_spliter.GetPane(0, 1);//获取新窗口的位置
		m_spliter.RecalcLayout();//对新界面进行布局
		pNewView->OnInitialUpdate();//并且调用新窗口的初始化函数初始化更新窗口
		m_spliter.SetActivePane(0, 1);//激活新窗口
	}
	break;
	case NM_B:
	{
		//CSellDlg类需要包含头文件#include "SellDlg.h"
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


		//CInfoDlg类需要包含头文件#include "InfoDlg.h"
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
			//CInfoDlg类需要包含头文件#include "InfoDlg.h"
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
			//CDelDlg类需要包含头文件#include "DelDlg.h"
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
//静态拆分 window文档
BOOL CMainFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext)
{
	// TODO: 在此添加专用代码和/或调用基类

	// 静态拆分窗口，1行2列，CSplitterWnd::CreateStatic
	m_spliter.CreateStatic(this, 1, 2);

	// 创建视图：CSplitterWnd::CreateView
	//0, 0 ： 放在第0行第0列的位置
	//RUNTIME_CLASS(CSelectView) ：需要头文件#include "SelectView.h"， CSelectView在SelectView.h中声明
	// CSize(250, 500)：指定视图宽度和高度
	//pContext ： 为OnCreateClient()最后一个形参
	m_spliter.CreateView(0, 0, RUNTIME_CLASS(CSelectView), CSize(200, 500), pContext);

	//0, 1： 放在第0行第1列的位置
	//CDispalyView，需要头文件#include "DispalyView.h"
	m_spliter.CreateView(0, 1, RUNTIME_CLASS(CDispalyView), CSize(600, 500), pContext);

	return TRUE;

	//return CFrameWnd::OnCreateClient(lpcs, pContext);
}


//菜单栏 代码


void CMainFrame::On32773()
{
	// TODO: 在此添加命令处理程序代码
	//::postMessage发送自定义消息 AfxGetMainWnd获取主窗口 GetSafeHwnd获得窗口句柄
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_A, (WPARAM)NM_A, (LPARAM)0);

}


void CMainFrame::On32774()
{
	//::postMessage发送自定义消息
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_B, (WPARAM)NM_B, (LPARAM)0);
}


void CMainFrame::On32775()
{
//::postMessage发送自定义消息
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_C, (WPARAM)NM_C, (LPARAM)0);
}


void CMainFrame::On32776()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_D, (WPARAM)NM_D, (LPARAM)0);
}


void CMainFrame::On32777()
{
	// TODO: 在此添加命令处理程序代码
	::PostMessage(AfxGetMainWnd()->GetSafeHwnd(), NM_E, (WPARAM)NM_E, (LPARAM)0);
}


void CMainFrame::On32778()
{
	// TODO: 在此添加命令处理程序代码
	exit(0);
}
