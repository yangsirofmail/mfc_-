
// create_salse_system.h : create_salse_system Ӧ�ó������ͷ�ļ�
//
#pragma once
#include "LoginDlg.h"
#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Ccreate_salse_systemApp:
// �йش����ʵ�֣������ create_salse_system.cpp
//

class Ccreate_salse_systemApp : public CWinApp
{
public:
	Ccreate_salse_systemApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ccreate_salse_systemApp theApp;
