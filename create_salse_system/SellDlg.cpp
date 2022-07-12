// SellDlg.cpp : ʵ���ļ�
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


// CSellDlg ���

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


// CSellDlg ��Ϣ�������

//��ʼ�����µĴ���
void CSellDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	// TODO: �ڴ����ר�ô����/����û���
	//��ȡ�ļ�����ȡ��Ʒ��������Ͽ�����ַ���
	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	//file.ls ��������洢�ı��ص��ı���Ϣ ͨ��ReadDocline����ѭ�����ļ���ȡ

	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		m_combo.AddString((CString)it->name.c_str());//string ת��char* ��ת��CString
	}

	file.ls.clear(); //���list������

					 //����һ����Ʒ����ΪĬ��ѡ����
	m_combo.SetCurSel(0);
	OnCbnSelchangeCombo1();//�����ֶ�����ѡ����¼� �γɸճ������ܿ���Ĭ����Ʒ�Ŀ��
}

//��Ʒ�л��ᴥ�����¼����� ��--�Ե��������ͻ��л���Ʒ �����¼� ��������CBN_SELCHANGE

//��Ҫ����#include "InfoFile.h"
void CSellDlg::OnCbnSelchangeCombo1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	CString text;
	//��ȡ��ǰѡ����
	int index = m_combo.GetCurSel();
	//��ȡ��ǰ����
	m_combo.GetLBText(index, text);
	//������Ʒ���� ��ȡ ��Ʒ�Ŀ��͵��� ��ʾ��������
	CInfoFile file;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	//����һ������
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (text == it->name.c_str())
		{
			m_list = it->num;//���ÿ������ ��ʾ���ؼ���
			m_price = it->price;//���ü۸񵽿ؼ���
			///m_num = 0;//�������Ҫ �����������Ϊ0
			UpdateData(FALSE); //���ݸ��µ���Ӧ�Ŀؼ�
		}
	}

	file.ls.clear(); //���list������

}

//����ť�ڶ�Ӧ�Ĵ���
void CSellDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	//��ȡ�ؼ������µ����ݸ��µ���Ӧ�����ı�����
	UpdateData(TRUE);

	if (m_num <= 0)
	{
		MessageBox(TEXT("����ĸ���Ҫ����0"));
		return;
	}
	//�����������ܴ��ڿ������
	else if (m_list<m_num)
	{
		MessageBox(TEXT("����ĸ������ܴ��ڿ������"));
		return;
	}


	//������ʵ��
	CString type;
	//��ȡ��ǰѡ����
	int index = m_combo.GetCurSel();//��ȡѡ����
	//��ȡ��Ͽ�ǰ����
	m_combo.GetLBText(index, type);//�����ȡ����Ҳ������Ʒ����

	//��Ҫ����#include "InfoFile.h"
	CInfoFile file;
	CString str;
	file.ReadDocline(); //��ȡ��Ʒ��Ϣ
	for (list<msg>::iterator it = file.ls.begin(); it != file.ls.end(); it++)
	{
		if (type == it->name.c_str())
		{
			it->num = it->num - m_num;//��������
			m_list = it->num;//���ٿ����ʾ������
							 //�Ҳ���ʾ���������ʾ
							 //TEXT ��_Tһ��
		
			str.Format(_T("��Ʒ��%s \r\n���ۣ�%d \r\n������%d \r\n�ܼۣ�%d"), type, m_price, m_num, m_price*m_num);

			m_sellInfo = str; //������Ϣ
			UpdateData(FALSE);//����
			//str�����ݾ��Ƕ�����Ϣͨ�����������з��� �����ļ� �ø�ʽ���ַ�����������Ϣͨ���޸ĺ�����ݽ����滻
			MessageBox(L"����ɹ�");//��ʾ�û�����ɹ�
		
		}
	}

	//������ʾ���� ��� �� ���±��� ����������

	file.WirteDocline(); //���±����ļ�����
	//	file.ls.clear(); //���list������  
	m_sellInfo.Empty();//��ն�����Ϣ��ʾ��  
	m_num = 0;//����ʾ�Ĺ������Ϊ0
	UpdateData(FALSE); //���µ���Ӧ�Ŀؼ�

}

//ȡ����ť
void CSellDlg::OnBnClickedCancel()
{
	m_combo.SetCurSel(0); //ѡ���0��Ŀ
	m_sellInfo = "";//�ö�����ʾ��ҳΪ��  
	m_num = 0;//�ù��������Ϊ0 ��Ȼȡ���� ��������ݲ���
	OnCbnSelchangeCombo1();//�ֶ�����Ĭ����ʾ�¼�Ҫ��Ȼ Ĭ�ϲ���ʾ���

	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
