// UserDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "create_salse_system.h"
#include "UserDlg.h"


// CUserDlg

IMPLEMENT_DYNCREATE(CUserDlg, CFormView)

CUserDlg::CUserDlg()
	: CFormView(DIALOG_USER)
	, m_user1(_T(""))
	, m_name(_T(""))
	, m_newpwd(_T(""))
	, m_surepwd(_T(""))
{

}

CUserDlg::~CUserDlg()
{
}

void CUserDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user1);
	DDX_Text(pDX, IDC_EDIT3, m_name);
	DDX_Text(pDX, IDC_EDIT2, m_newpwd);
	DDX_Text(pDX, IDC_EDIT4, m_surepwd);
}

BEGIN_MESSAGE_MAP(CUserDlg, CFormView)
	ON_BN_CLICKED(IDOK, &CUserDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CUserDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CUserDlg 诊断

#ifdef _DEBUG
void CUserDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CUserDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CUserDlg 消息处理程序


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CInfoFile file;	//需要头文件#include "InfoFile.h"
	CString name, pwd;
	file.ReadLogin(name, pwd); //读取文件的用户名和密码

							   //初始化个人信息
	m_user1 = TEXT("销售员");	//身份
	m_name = name;	//用户名

	UpdateData(FALSE); //把数据更新到控件上

	// TODO: 在此添加专用代码和/或调用基类
}


void CUserDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	UpdateData(TRUE);//更新控件内容到对应的变量中

	if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
	{
		MessageBox(TEXT("输入密码不能为空"));
		return;
	}

	if (m_newpwd != m_surepwd)
	{
		MessageBox(TEXT("输入密码和确定密码不相等"));
		return;
	}

	CInfoFile file;	//需要头文件#include "InfoFile.h"
	CString name, pwd;
	file.ReadLogin(name, pwd); //读取文件的用户名和密码

	if (m_surepwd == pwd)
	{
		MessageBox(TEXT("输入密码和旧密码相等"));
		return;
	}

	//把用户名和密码的CString类型转为char *
	char *tmpName, *tmpPwd;
	//用户名
	CStringA tmp1;
	tmp1 = name;
	tmpName = tmp1.GetBuffer();
	//密码
	CStringA tmp2;
	tmp2 = m_surepwd;
	tmpPwd = tmp2.GetBuffer();

	file.WritePwd(tmpName, tmpPwd); //修改密码

	MessageBox(TEXT("密码修改成功"));

	//输入框内容清空
	m_surepwd.Empty();
	m_newpwd.Empty();
	UpdateData(FALSE); //把数据更新到控件上

}


void CUserDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	//输入框内容清空
	m_surepwd.Empty();
	m_newpwd.Empty();
	UpdateData(FALSE); //把数据更新到控件上

}
