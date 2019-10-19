#pragma once
#include "hinh.h"
class Hinhchunhat :
	public Hinh
{
private: int x1,y1,x2,y2;
public:
	Hinhchunhat(void);
	Hinhchunhat(CPoint px1,CPoint px2);
	void thietlap(int mx1,int my1,int mx2,int my2);
	void ve(CClientDC *pDC);
	void dichuyen();
	void phongto();
	void thunho();
	float dientich();
	float chuvi();
	int tronghinh(CPoint p);
	void butbandau(CClientDC *pDC);
	void xoahinh(CClientDC *pDC);
	void dctrai();
	void dcphai();
	void dclen();
	void dcxuong();
	~Hinhchunhat(void);
};

