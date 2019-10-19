#pragma once
#include "hinh.h"
class Ngoisao:public Hinh
{
private: int x1,y1,x2,y2,x3,y3,x4,y4,x5,y5;
		 float r,rad,x[5],y[5];
		 float xt,yt;

public:
	Ngoisao(void);
	Ngoisao(CPoint px1,CPoint px2);
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
	~Ngoisao(void);
};

