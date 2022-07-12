// SellDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "create_salse_system.h"
#include "SellDlg.h"


// CSellDlg

IMPLEMENT_DYNCREATE(CSellDlg, CFormView)

CSellDlg::CSellDlg()
	: CFormView(DIALOG_SELL)
	, m_price(0)
	, m_num(0)
	, m_sellInfo(_T(""))
	
	, m_list(0)
{

}

CSellDlg::~CSellDlg()
{
}

void CSellDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price);
	DDX_Text(pDX, IDC_EDIT2, m_num);
	DDX_Text(pDX, IDC_EDIT4, m_sellInfo);

	DDX_Text(pDX, IDC_EDIT6, m_list);
}

BEGIN_MESSAGE_MAP(CSellDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CSellDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CSellDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CSellDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSellDlg 诊断

#ifdef _DEBUG
void CSellDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CSellDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CSellDlg 消息处理程序

//初始化更新的代码
void CSellDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类
	//读取文件，获取商品名，给组合框添加字符串
	//需要包含#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //读取商品信息
	//file.ls 容器里面存储的本地的文本信息 通过ReadDocline进行循环的文件读取

	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());//string 转到char* 在转成CString
	}

	file.ls.clear(); //清空list的内容

					 //将第一个商品名设为默认选中项
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();//并且手动调用选项的事件 形成刚出来就能看到默认商品的库存
}

//商品切换会触发的事件代码 、--以点击下拉框就会切换商品 触发事件 触发代码CBN_SELCHANGE

//需要包含#include "InfoFile.h"
void CSellDlg::OnCbnSelchangeCombo1()
{
	// TODO: 在此添加控件通知处理程序代码

	CString text;
	//获取当前选中项
	int index = m_combo.GetCurSel();
	//获取当前内容
	m_combo.GetLBText(index, text);
	//根据商品名称 获取 商品的库存和单价 显示到窗口中
	CInfoFile file;
	file.ReadDocline(); //读取商品信息
	//遍历一遍数据
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (text == it->name.c_str())
		{
			m_list = it->num;//设置库存数量 显示到控件中
			m_price = it->price;//设置价格到控件中
			///m_num = 0;//这个不需要 这个是让数量为0
			UpdateData(FALSE); //内容更新到对应的控件
		}
	}

	file.ls.clear(); //清空list的内容

}

//购买按钮内对应的代码
void CSellDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码

	//获取控件上最新的内容更新到对应关联的变量中
	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("购买的个数要大于0"));
		return;
	}
	//购买数量不能大于库存数量
	else if (m_list<m_num)
	{
		MessageBox(TEXT("购买的个数不能大于库存数量"));
		return;
	}


	//购买功能实现
	CString type;
	//获取当前选中项
	int index = m_combo.GetCurSel();//获取选中项
	//获取组合框当前内容
	m_combo.GetLBText(index, type);//从项获取内容也就是商品名称

	//需要包含#include "InfoFile.h"
	CInfoFile file;
	CString str;
	file.ReadDocline(); //读取商品信息
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (type == it->name.c_str())
		{
			it->num = it->num - m_num;//减少数量
			m_list = it->num;//减少库存显示的数量
							 //右侧提示框的内容显示
							 //TEXT 和_T一样
		
			str.Format(_T("商品：%s \r\n单价：%d \r\n个数：%d \r\n总价：%d"), type, m_price, m_num, m_price*m_num);

			m_sellInfo = str; //销售信息
			UpdateData(FALSE);//更新
			//str的内容就是订单信息通过迭代器进行访问 本地文件 用格式化字符串将本地信息通过修改后的数据进行替换
			MessageBox(L"购买成功");//提示用户购买成功
		
		}
	}

	//订单显示内容 清空 、 更新本地 的数据内容

	file.WirteDocline(); //更新本地文件内容
	//	file.ls.clear(); //清空list的内容  
	m_sellInfo.Empty();//清空订单信息显示栏  
	m_num = 0;//让显示的购买个数为0
	UpdateData(FALSE); //更新到对应的控件

}

//取消按钮
void CSellDlg::OnBnClickedCancel()
{
	m_combo.SetCurSel(0); //选择第0项目
	m_sellInfo = "";//让订单显示框页为空  
	m_num = 0;//让购买的数量为0 不然取消了 购买框内容不动
	OnCbnSelchangeCombo1();//手动触发默认显示事件要不然 默认不显示库存

	// TODO: 在此添加控件通知处理程序代码
}
