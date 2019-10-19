
// baitonghopView.h : interface of the CbaitonghopView class
//

#pragma once

#include "Hinh.h"
#include "Hinhtron.h"
#include "Hinhchunhat.h"
#include "Hinhvuong.h"
#include "Dongxu.h"
#include "Ngoisao.h"
class CbaitonghopView : public CView
{
protected: // create from serialization only
	CbaitonghopView();
	DECLARE_DYNCREATE(CbaitonghopView)

// Attributes
public:
	CbaitonghopDoc* GetDocument() const;

// Operations
public:
	CClientDC *pDC;
	CPoint p1,p2;
	Hinh *hinh[20];
	Hinhtron ht1,ic,dc;
	Hinhvuong hv1,xoa,up,dn,lf,rt;
	Hinhchunhat hcn1,menu1,menu2;
	Ngoisao ns1;
	Dongxu dx1;
	int control,n,kt[20];
// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CbaitonghopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
};

#ifndef _DEBUG  // debug version in baitonghopView.cpp
inline CbaitonghopDoc* CbaitonghopView::GetDocument() const
   { return reinterpret_cast<CbaitonghopDoc*>(m_pDocument); }
#endif

