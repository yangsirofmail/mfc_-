
// create_salse_systemView.h : Ccreate_salse_systemView ��Ľӿ�
//

#pragma once


class Ccreate_salse_systemView : public CView
{
protected: // �������л�����
	Ccreate_salse_systemView();
	DECLARE_DYNCREATE(Ccreate_salse_systemView)

// ����
public:
	Ccreate_salse_systemDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// ʵ��
public:
	virtual ~Ccreate_salse_systemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // create_salse_systemView.cpp �еĵ��԰汾
inline Ccreate_salse_systemDoc* Ccreate_salse_systemView::GetDocument() const
   { return reinterpret_cast<Ccreate_salse_systemDoc*>(m_pDocument); }
#endif

