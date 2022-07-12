
// create_salse_systemDoc.cpp : Ccreate_salse_systemDoc 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "create_salse_system.h"
#endif

#include "create_salse_systemDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// Ccreate_salse_systemDoc

IMPLEMENT_DYNCREATE(Ccreate_salse_systemDoc, CDocument)

BEGIN_MESSAGE_MAP(Ccreate_salse_systemDoc, CDocument)
END_MESSAGE_MAP()


// Ccreate_salse_systemDoc 构造/析构

Ccreate_salse_systemDoc::Ccreate_salse_systemDoc()
{
	// TODO: 在此添加一次性构造代码

}

Ccreate_salse_systemDoc::~Ccreate_salse_systemDoc()
{
}

BOOL Ccreate_salse_systemDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 在此添加重新初始化代码
	// (SDI 文档将重用该文档)
	//设置窗口标题，CDocument::SetTitle
	SetTitle(TEXT("销售管理系统"));

	return TRUE;
}




// Ccreate_salse_systemDoc 序列化

void Ccreate_salse_systemDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: 在此添加存储代码
	}
	else
	{
		// TODO: 在此添加加载代码
	}
}

#ifdef SHARED_HANDLERS

// 缩略图的支持
void Ccreate_salse_systemDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 修改此代码以绘制文档数据
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 搜索处理程序的支持
void Ccreate_salse_systemDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 从文档数据设置搜索内容。
	// 内容部分应由“;”分隔

	// 例如:     strSearchContent = _T("point;rectangle;circle;ole object;")；
	SetSearchContent(strSearchContent);
}

void Ccreate_salse_systemDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// Ccreate_salse_systemDoc 诊断

#ifdef _DEBUG
void Ccreate_salse_systemDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void Ccreate_salse_systemDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// Ccreate_salse_systemDoc 命令
