// DelDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "create_salse_system.h"
#include "DelDlg.h"


// CDelDlg

IMPLEMENT_DYNCREATE(CDelDlg, CFormView)

CDelDlg::CDelDlg()
	: CFormView(DIALOG_DEL)
	, m_price(0)
	, m_num(0)
	, m_list1(0)
{

}

CDelDlg::~CDelDlg()
{
}

void CDelDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO2, m_combo);
	DDX_Text(pDX, IDC_EDIT3, m_price);
	DDX_Text(pDX, IDC_EDIT4, m_num);
	DDX_Text(pDX, IDC_EDIT1, m_list1);
}

BEGIN_MESSAGE_MAP(CDelDlg, CFormView)
//	ON_CBN_SELCHANGE(IDC_COMBO2, &CDelDlg::OnCbnSelchangeCombo2)
ON_CBN_SELCHANGE(IDC_COMBO2, &CDelDlg::OnCbnSelchangeCombo2)
ON_BN_CLICKED(IDOK, &CDelDlg::OnBnClickedOk)
ON_BN_CLICKED(IDCANCEL, &CDelDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CDelDlg 诊断

#ifdef _DEBUG
void CDelDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CDelDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CDelDlg 消息处理程序


//void CDelDlg::OnCbnSelchangeCombo2()
//{
//	// TODO: 在此添加控件通知处理程序代码
//}


void CDelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	// 读取文件，获取商品名，给组合框添加字符串
		//需要包含#include "InfoFile.h"
		CInfoFile file;
	file.ReadDocline(); //读取商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());
	}


	//将第一个商品名设为默认选中项
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo2();//默认调用要不然数据不显示

}


void CDelDlg::OnCbnSelchangeCombo2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString text;
	//获取当前选中项
	int index = m_combo.GetCurSel();
	//获取当前内容
	m_combo.GetLBText(index, text);

	//需要包含#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //读取商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (text == it->name.c_str())
		{
			m_price = it->price;
			m_list1 = it->num;//设置库存数量 显示到控件中
			m_num = 0;
			UpdateData(FALSE); //内容更新到对应的控件
		}
	}



}

//
void CDelDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取控件上的内容，更新到对应关联的变量中
	UpdateData(TRUE);

	if (m_num <= 0 )
	{
		MessageBox(TEXT("个数不能为负数"));
		return;
	}if (m_list1<m_num)
	{
		MessageBox(TEXT("删除个数不能大于库存数量"));
		return;
	}

	CString type;
	//获取当前选中项
	int index = m_combo.GetCurSel();
	//获取组合框当前内容
	m_combo.GetLBText(index, type);

	CString str;
	str.Format(_T("删除商品：%s \r\n单价：%d \r\n个数：%d "), type, m_price, m_num);
	MessageBox(str);


	//需要包含#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //读取商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (type == it->name.c_str())
		{
			it->num = it->num - m_num;
			m_list1 = it->num;//将库存个数同步到显示框

		

	
		}
	}
	file.WirteDocline(); //更新文件内容



	m_num = 0;
	UpdateData(FALSE); //更新到对应的控件




}


void CDelDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码

	m_combo.SetCurSel(0); //选择第0项目
	m_num = 0;
	OnCbnSelchangeCombo2();

}
