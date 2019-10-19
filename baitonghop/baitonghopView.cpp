
// baitonghopView.cpp : implementation of the CbaitonghopView class
//

#include "stdafx.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "baitonghop.h"
#endif

#include "baitonghopDoc.h"
#include "baitonghopView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CbaitonghopView

IMPLEMENT_DYNCREATE(CbaitonghopView, CView)

BEGIN_MESSAGE_MAP(CbaitonghopView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CbaitonghopView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
END_MESSAGE_MAP()

// CbaitonghopView construction/destruction

CbaitonghopView::CbaitonghopView()
{
	// TODO: add construction code here
	control=0;
	n=0;
	for(int i=0;i<20;i++)
		kt[i]=0;
	menu1.thietlap(0,0,600,90);
	menu2.thietlap(600,0,1080,90);
	ht1.thietlap(20,20,70,70);
	hv1.thietlap(75,20,125,70);
	hcn1.thietlap(130,20,210,70);
	dx1.thietlap(215,20,265,70);
	ns1.thietlap(300,30,320,70);
	dc.thietlap(400,30,440,60);
	ic.thietlap(445,30,485,60);
	xoa.thietlap(360,30,390,60);
	up.thietlap(530,8,560,33);
	dn.thietlap(530,58,560,83);
	lf.thietlap(500,33,530,58);
	rt.thietlap(560,33,590,58);
}

CbaitonghopView::~CbaitonghopView()
{
}

BOOL CbaitonghopView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CbaitonghopView drawing

void CbaitonghopView::OnDraw(CDC* /*pDC*/)
{
	CbaitonghopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	pDC =new CClientDC(this);
	menu1.ve(pDC);
	menu2.ve(pDC);
	ht1.ve(pDC);
	hv1.ve(pDC);
	hcn1.ve(pDC);
	dx1.ve(pDC);
	ns1.ve(pDC);
	ic.ve(pDC);
	dc.ve(pDC);
	xoa.ve(pDC);
	up.ve(pDC);
	dn.ve(pDC);
	lf.ve(pDC);
	rt.ve(pDC);
	pDC->TextOutW(371,37,CString("X"));
	pDC->TextOutW(417,35,CString("-"));
	pDC->TextOutW(462,35,CString("+"));
	pDC->TextOutW(540,13,CString("U"));
	pDC->TextOutW(540,63,CString("D"));
	pDC->TextOutW(510,38,CString("L"));
	pDC->TextOutW(570,38,CString("R"));
	// TODO: add draw code for native data here
}


// CbaitonghopView printing


void CbaitonghopView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CbaitonghopView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CbaitonghopView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CbaitonghopView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CbaitonghopView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CbaitonghopView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CbaitonghopView diagnostics

#ifdef _DEBUG
void CbaitonghopView::AssertValid() const
{
	CView::AssertValid();
}

void CbaitonghopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CbaitonghopDoc* CbaitonghopView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CbaitonghopDoc)));
	return (CbaitonghopDoc*)m_pDocument;
}
#endif //_DEBUG


// CbaitonghopView message handlers


void CbaitonghopView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p1.x=point.x;
	p1.y=point.y;
	for(int i=0;i<n;i++)
	{
		if(hinh[i]->tronghinh(point)==1)
		{
			CString str1,str2;
			str1.Format(_T("%f"), hinh[i]->dientich());
			pDC->TextOutW(620,30,CString("Dien tich : "));
			pDC->TextOutW(700,30,str1);
			str2.Format(_T("%f"), hinh[i]->chuvi());
			pDC->TextOutW(620,50,CString("Chu vi : "));
			pDC->TextOutW(700,70,str2);
		}
	}
	CView::OnLButtonDown(nFlags, point);
}


void CbaitonghopView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	p2.x=point.x;
	p2.y=point.y;
	if(ht1.tronghinh(point)==1)
		control=1;
	else
		if(hv1.tronghinh(point)==1)
			control=2;
		else
			if(hcn1.tronghinh(point)==1)
				control=3;
			else
				if(dx1.tronghinh(point)==1)
					control=4;
				else
					if(ns1.tronghinh(point)==1)
						control=5;
					if(dc.tronghinh(point)==1)
						control=6;
					else
						if(ic.tronghinh(point)==1)
							control=7;
						else
							if(xoa.tronghinh(point)==1)
								control=8;
							else
								if(up.tronghinh(point)==1)
									control=9;
								else
									if(dn.tronghinh(point)==1)
										control=10;
								else
									if(lf.tronghinh(point)==1)
										control=11;
									else
										if(rt.tronghinh(point)==1)
											control=12;
						else
							if(control==1)
							{
								hinh[n]=new Hinhtron(p1,p2);
								hinh[n]->ve(pDC);
								n++;
							}
							else
								if(control==2)
								{
									hinh[n]=new Hinhvuong(p1,p2);
									hinh[n]->ve(pDC);
									n++;
								}
								else
									if(control==3)
									{
										hinh[n]=new Hinhchunhat(p1,p2);
										hinh[n]->ve(pDC);
										n++;
									}
									else
										if(control==4)
										{
											hinh[n]=new Dongxu(p1,p2);
											hinh[n]->ve(pDC);
											n++;
										}
										else
											if(control==5)
											{
												hinh[n]=new Ngoisao(p1,p2);
												hinh[n]->ve(pDC);
												n++;
											}
										else
											if(control==6)
											{
												for(int i=0;i<n;i++)
												{
													if(hinh[i]->tronghinh(point)==1&&kt[i]==0)
													{
														hinh[i]->xoahinh(pDC);
														hinh[i]->ve(pDC);
														hinh[i]->thunho();
														hinh[i]->butbandau(pDC);
														hinh[i]->ve(pDC);
													}
												}	
											}
											else
												if(control==7)
												{
													for(int i=0;i<n;i++)
													{
														if(hinh[i]->tronghinh(point)==1&&kt[i]==0)
														{
															hinh[i]->xoahinh(pDC);
															hinh[i]->ve(pDC);
															hinh[i]->phongto();
															hinh[i]->butbandau(pDC);
															hinh[i]->ve(pDC);
														}
													}	
												}	
												else
													if(control==8)
													{
														for(int i=0;i<n;i++)
														{
															if(hinh[i]->tronghinh(point)==1)
															{
																hinh[i]->xoahinh(pDC);
																hinh[i]->ve(pDC);
																hinh[i]->butbandau(pDC);
																kt[i]=1;
															}
														}	
													}
														else
															if(control==9)
															{
																for(int i=0;i<n;i++)
																{
																	if(hinh[i]->tronghinh(point)==1&&kt[i]==0)
																	{
																			hinh[i]->xoahinh(pDC);
																			hinh[i]->ve(pDC);
																			hinh[i]->dclen();
																			hinh[i]->butbandau(pDC);
																			hinh[i]->ve(pDC);
																	}
																}
															}
													else
														if(control==10)
															{
																for(int i=0;i<n;i++)
																{
																	if(hinh[i]->tronghinh(point)==1&&kt[i]==0)
																	{
																			hinh[i]->xoahinh(pDC);
																			hinh[i]->ve(pDC);
																			hinh[i]->dcxuong();
																			hinh[i]->butbandau(pDC);
																			hinh[i]->ve(pDC);
																	}
																}
															}
														else
														if(control==11)
															{
																for(int i=0;i<n;i++)
																{
																	if(hinh[i]->tronghinh(point)==1&&kt[i]==0)
																	{
																			hinh[i]->xoahinh(pDC);
																			hinh[i]->ve(pDC);
																			hinh[i]->dctrai();
																			hinh[i]->butbandau(pDC);
																			hinh[i]->ve(pDC);
																	}
																}
															}
														else
															if(control==12)
															{
																for(int i=0;i<n;i++)
																{
																	if(hinh[i]->tronghinh(point)==1&&kt[i]==0)
																	{
																			hinh[i]->xoahinh(pDC);
																			hinh[i]->ve(pDC);
																			hinh[i]->dcphai();
																			hinh[i]->butbandau(pDC);
																			hinh[i]->ve(pDC);
																	}
																}
															}
	CView::OnLButtonUp(nFlags, point);
}
