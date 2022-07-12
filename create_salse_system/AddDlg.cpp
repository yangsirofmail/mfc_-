// AddDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "create_salse_system.h"
#include "AddDlg.h"


// CAddDlg

IMPLEMENT_DYNCREATE(CAddDlg, CFormView)

CAddDlg::CAddDlg()
	: CFormView(DIALOG_ADD)
	, m_price1(0)
	, m_num1(0)
	, m_name2(_T(""))
	, m_price2(0)
	, m_num2(0)
	, m_stock_num(0)
	, m_new_stock(0)
{

}

CAddDlg::~CAddDlg()
{
}

void CAddDlg::DoDataExchange(CDataExchange* pDX)
{
	CFormView::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, m_combo);
	DDX_Text(pDX, IDC_EDIT1, m_price1);
	DDX_Text(pDX, IDC_EDIT2, m_num1);
	DDX_Text(pDX, IDC_EDIT4, m_name2);
	DDX_Text(pDX, IDC_EDIT5, m_price2);
	DDX_Text(pDX, IDC_EDIT6, m_num2);
	DDX_Text(pDX, IDC_EDIT8, m_stock_num);

}

BEGIN_MESSAGE_MAP(CAddDlg, CFormView)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CAddDlg::OnCbnSelchangeCombo1)
	ON_BN_CLICKED(IDOK, &CAddDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CAddDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDOK2, &CAddDlg::OnBnClickedOk2)
	ON_BN_CLICKED(IDCANCEL2, &CAddDlg::OnBnClickedCancel2)
END_MESSAGE_MAP()


// CAddDlg ���

#ifdef _DEBUG
void CAddDlg::AssertValid() const
{
	CFormView::AssertValid();
}

#ifndef _WIN32_WCE
void CAddDlg::Dump(CDumpContext& dc) const
{
	CFormView::Dump(dc);
}
#endif
#endif //_DEBUG


// CAddDlg ��Ϣ�������


void CAddDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ȡ�ļ�����ȡ��Ʒ��������Ͽ�����ַ���
	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());
	}

	file.ls.clear(); //���list������

					 //����һ����Ʒ����ΪĬ��ѡ����
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();//���ó�ʼ�� Ҫ��Ȼ ���������ʾ
}


void CAddDlg::OnCbnSelchangeCombo1()
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
			m_price1 = it->price;
			m_stock_num = it->num;//�����Ϣ
			m_num1 = 0;
			UpdateData(FALSE); //���ݸ��µ���Ӧ�Ŀؼ�
		}
	}

	file.ls.clear(); //���list������

}


//��Ҫ����#include "InfoFile.h"
void CAddDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ�ؼ��ϵ����ݣ����µ���Ӧ�����ı�����
	UpdateData(TRUE);

	if (m_num1 <= 0)
	{
		MessageBox(TEXT("��Ӹ���Ҫ����0"));
		return;
	}

	//��ȡ�����Ʒ����Ʒ����

	CString type;
	//��ȡ��ǰѡ����
	int index = m_combo.GetCurSel();//��ȡ��������
	//��ȡ��Ͽ�ǰ����
	m_combo.GetLBText(index, type);//ͨ��������ȡֵ ��ŵ�type��

 //��ȡ��Ʒ��Ϣ
	CInfoFile file;
	file.ReadDocline(); 
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (type == it->name.c_str())
		{
			it->num += m_num1;//����
			m_stock_num += m_num1;//���
			it->price = m_price1;//�۸�

		
		}
	}
	//��ʾ�û���ӳɹ�
	CString str;
	str.Format(_T("����� ��Ʒ��%s \r\n���ۣ�%d \r\n������%d"), type, m_price1, m_num1);
	MessageBox(str);


	//���µ��ı�����
	file.WirteDocline(); //�����ļ�����

	file.ls.clear(); //���list������
	m_num1 = 0;
	UpdateData(FALSE); //���µ���Ӧ�Ŀؼ�

}

//ȡ����ť
void CAddDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	// TODO:  �ڴ���ӿؼ�֪ͨ����������

	m_combo.SetCurSel(0);
	m_num1 = 0;

	OnCbnSelchangeCombo1();

}

//�������Ʒ
void CAddDlg::OnBnClickedOk2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	UpdateData(TRUE); //��ȡ�ؼ�����

	if (m_num2 <= 0 || m_price2 <= 0 || m_name2.IsEmpty())//���ֿյ� �۸�С��0 ���� С��0������Ϊ��
	{
		MessageBox(TEXT("������Ϣ����"));
		return;
	}

	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ���µ��ı��ڵ���Ʒ��Ϣ
	file.Addline(m_name2, m_num2, m_price2); //�����Ʒ
	file.WirteDocline(); //������ͬ�����ļ�
	file.ls.clear(); //���list������
	MessageBox(_T("��ӳɹ�"));

	//������Ʒ Ҳ���� �����ֲ��뵽 �����Ʒ�ĵ�һ��λ��
	m_combo.InsertString(0, m_name2);
	m_combo.SetCurSel(0);//��ȡ��Ʒ���±�
	OnCbnSelchangeCombo1();
	//��� 
	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);

}

//ȡ����ť ������մ���
void CAddDlg::OnBnClickedCancel2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_name2.Empty();
	m_num2 = 0;
	m_price2 = 0;
	UpdateData(FALSE);

}
