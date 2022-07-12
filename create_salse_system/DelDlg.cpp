// DelDlg.cpp : ʵ���ļ�
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


// CDelDlg ���

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


// CDelDlg ��Ϣ�������


//void CDelDlg::OnCbnSelchangeCombo2()
//{
//	// TODO: �ڴ���ӿؼ�֪ͨ����������
//}


void CDelDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	// ��ȡ�ļ�����ȡ��Ʒ��������Ͽ�����ַ���
		//��Ҫ����#include "InfoFile.h"
		CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());
	}


	//����һ����Ʒ����ΪĬ��ѡ����
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo2();//Ĭ�ϵ���Ҫ��Ȼ���ݲ���ʾ

}


void CDelDlg::OnCbnSelchangeCombo2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString text;
	//��ȡ��ǰѡ����
	int index = m_combo.GetCurSel();
	//��ȡ��ǰ����
	m_combo.GetLBText(index, text);

	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (text == it->name.c_str())
		{
			m_price = it->price;
			m_list1 = it->num;//���ÿ������ ��ʾ���ؼ���
			m_num = 0;
			UpdateData(FALSE); //���ݸ��µ���Ӧ�Ŀؼ�
		}
	}



}

//
void CDelDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ�ؼ��ϵ����ݣ����µ���Ӧ�����ı�����
	UpdateData(TRUE);

	if (m_num <= 0 )
	{
		MessageBox(TEXT("��������Ϊ����"));
		return;
	}if (m_list1<m_num)
	{
		MessageBox(TEXT("ɾ���������ܴ��ڿ������"));
		return;
	}

	CString type;
	//��ȡ��ǰѡ����
	int index = m_combo.GetCurSel();
	//��ȡ��Ͽ�ǰ����
	m_combo.GetLBText(index, type);

	CString str;
	str.Format(_T("ɾ����Ʒ��%s \r\n���ۣ�%d \r\n������%d "), type, m_price, m_num);
	MessageBox(str);


	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (type == it->name.c_str())
		{
			it->num = it->num - m_num;
			m_list1 = it->num;//��������ͬ������ʾ��

		

	
		}
	}
	file.WirteDocline(); //�����ļ�����



	m_num = 0;
	UpdateData(FALSE); //���µ���Ӧ�Ŀؼ�




}


void CDelDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	m_combo.SetCurSel(0); //ѡ���0��Ŀ
	m_num = 0;
	OnCbnSelchangeCombo2();

}
