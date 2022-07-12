
// create_salse_system.h : create_salse_system 应用程序的主头文件
//
#pragma once
#include "LoginDlg.h"
#ifndef __AFXWIN_H__
	#error "在包含此文件之前包含“stdafx.h”以生成 PCH 文件"
#endif

#include "resource.h"       // 主符号


// Ccreate_salse_systemApp:
// 有关此类的实现，请参阅 create_salse_system.cpp
//

class Ccreate_salse_systemApp : public CWinApp
{
public:
	Ccreate_salse_systemApp();


// 重写
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// 实现
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Ccreate_salse_systemApp theApp;
