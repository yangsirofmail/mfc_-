
// create_salse_systemView.h : Ccreate_salse_systemView 类的接口
//

#pragma once


class Ccreate_salse_systemView : public CView
{
protected: // 仅从序列化创建
	Ccreate_salse_systemView();
	DECLARE_DYNCREATE(Ccreate_salse_systemView)

// 特性
public:
	Ccreate_salse_systemDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Ccreate_salse_systemView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // create_salse_systemView.cpp 中的调试版本
inline Ccreate_salse_systemDoc* Ccreate_salse_systemView::GetDocument() const
   { return reinterpret_cast<Ccreate_salse_systemDoc*>(m_pDocument); }
#endif

