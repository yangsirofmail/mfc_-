
// create_salse_systemView.cpp : Ccreate_salse_systemView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "create_salse_system.h"
#endif

#include "create_salse_systemDoc.h"
#include "create_salse_systemView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Ccreate_salse_systemView

IMPLEMENT_DYNCREATE(Ccreate_salse_systemView, CView)

BEGIN_MESSAGE_MAP(Ccreate_salse_systemView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
END_MESSAGE_MAP()

// Ccreate_salse_systemView ����/����

Ccreate_salse_systemView::Ccreate_salse_systemView()
{
	// TODO: �ڴ˴���ӹ������

}

Ccreate_salse_systemView::~Ccreate_salse_systemView()
{
}

BOOL Ccreate_salse_systemView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Ccreate_salse_systemView ����

void Ccreate_salse_systemView::OnDraw(CDC* /*pDC*/)
{
	Ccreate_salse_systemDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
}


// Ccreate_salse_systemView ��ӡ

BOOL Ccreate_salse_systemView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Ccreate_salse_systemView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Ccreate_salse_systemView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: ��Ӵ�ӡ����е��������
}


// Ccreate_salse_systemView ���

#ifdef _DEBUG
void Ccreate_salse_systemView::AssertValid() const
{
	CView::AssertValid();
}

void Ccreate_salse_systemView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Ccreate_salse_systemDoc* Ccreate_salse_systemView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Ccreate_salse_systemDoc)));
	return (Ccreate_salse_systemDoc*)m_pDocument;
}
#endif //_DEBUG


// Ccreate_salse_systemView ��Ϣ�������
