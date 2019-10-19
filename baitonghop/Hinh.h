#pragma once
class Hinh
{

public:
	CPoint p1,p2;
	Hinh(void);
	virtual  void thietlap(int mx1,int my1,int mx2,int my2);
	virtual void ve(CClientDC *pDC);
	virtual void dctrai();
	virtual void dcphai();
	virtual void dclen();
	virtual void dcxuong();
	virtual void phongto();
	virtual void thunho();
	virtual float dientich();
	virtual float chuvi();
	virtual int tronghinh(CPoint p);
	virtual void butbandau(CClientDC *pDC);
	virtual void xoahinh(CClientDC *pDC);
	~Hinh(void);
};

