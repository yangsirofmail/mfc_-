// UserDlg.cpp : ʵ���ļ�
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


// CUserDlg ���

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


// CUserDlg ��Ϣ�������


void CUserDlg::OnInitialUpdate()
{
	CFormView::OnInitialUpdate();

	CInfoFile file;	//��Ҫͷ�ļ�#include "InfoFile.h"
	CString name, pwd;
	file.ReadLogin(name, pwd); //��ȡ�ļ����û���������

							   //��ʼ��������Ϣ
	m_user1 = TEXT("����Ա");	//���
	m_name = name;	//�û���

	UpdateData(FALSE); //�����ݸ��µ��ؼ���

	// TODO: �ڴ����ר�ô����/����û���
}


void CUserDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	UpdateData(TRUE);//���¿ؼ����ݵ���Ӧ�ı�����

	if (m_newpwd.IsEmpty() || m_surepwd.IsEmpty())
	{
		MessageBox(TEXT("�������벻��Ϊ��"));
		return;
	}

	if (m_newpwd != m_surepwd)
	{
		MessageBox(TEXT("���������ȷ�����벻���"));
		return;
	}

	CInfoFile file;	//��Ҫͷ�ļ�#include "InfoFile.h"
	CString name, pwd;
	file.ReadLogin(name, pwd); //��ȡ�ļ����û���������

	if (m_surepwd == pwd)
	{
		MessageBox(TEXT("��������;��������"));
		return;
	}

	//���û����������CString����תΪchar *
	char *tmpName, *tmpPwd;
	//�û���
	CStringA tmp1;
	tmp1 = name;
	tmpName = tmp1.GetBuffer();
	//����
	CStringA tmp2;
	tmp2 = m_surepwd;
	tmpPwd = tmp2.GetBuffer();

	file.WritePwd(tmpName, tmpPwd); //�޸�����

	MessageBox(TEXT("�����޸ĳɹ�"));

	//������������
	m_surepwd.Empty();
	m_newpwd.Empty();
	UpdateData(FALSE); //�����ݸ��µ��ؼ���

}


void CUserDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//������������
	m_surepwd.Empty();
	m_newpwd.Empty();
	UpdateData(FALSE); //�����ݸ��µ��ؼ���

}
