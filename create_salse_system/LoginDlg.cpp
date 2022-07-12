// LoginDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "create_salse_system.h"
#include "LoginDlg.h"
#include "afxdialogex.h"


// CLoginDlg �Ի���

IMPLEMENT_DYNAMIC(CLoginDlg, CDialogEx)

CLoginDlg::CLoginDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(DIALOG_LOGIN, pParent)
	, m_user(_T(""))
	, m_pwd(_T(""))
{

}

CLoginDlg::~CLoginDlg()
{
}

void CLoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_user);
	DDX_Text(pDX, IDC_EDIT2, m_pwd);
}


BEGIN_MESSAGE_MAP(CLoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &CLoginDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CLoginDlg::OnBnClickedCancel)
	ON_WM_CLOSE()
END_MESSAGE_MAP()


// CLoginDlg ��Ϣ�������


BOOL CLoginDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	m_user = TEXT("��ͷ�����");	//�û���
	m_pwd = TEXT("123456");//����
	UpdateData(FALSE); //���ݸ��µ���Ӧ�Ŀؼ�

	return TRUE;  // return TRUE unless you set the focus to a control
				  // �쳣: OCX ����ҳӦ���� FALSE
}


void CLoginDlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//CDialogEx::OnOK();

	UpdateData(TRUE); //���¿ؼ������ݵ���Ӧ�ı���

	CInfoFile file; //���������ļ��������Ҫͷ�ļ�#include "InfoFile.h" 
	CString user, pwd;

	//��ȡ�����ļ�����ȡ�û������룬����Ϊ���ô���
	file.ReadLogin(user, pwd);

	if (m_user == user)//�û������
	{
		if (m_pwd != pwd)
		{
			MessageBox(_T("�������"));
			m_user.Empty(); //���
			m_pwd.Empty();
		}
		else
		{
			CDialogEx::OnOK();
		}
	}
	else
	{
		MessageBox(_T("�û���������"));
		m_user.Empty();
		m_pwd.Empty();
	}

}


void CLoginDlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	exit(0);	//������������
	//	CDialogEx::OnCancel();
}


void CLoginDlg::OnClose()
{
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	exit(0);	//������������
	CDialogEx::OnClose();
}


void CLoginDlg::OnOK()
{
	// TODO: �ڴ����ר�ô����/����û���

//	CDialogEx::OnOK();
}
