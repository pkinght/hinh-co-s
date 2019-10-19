#include "StdAfx.h"
#include "Dongxu.h"
#include <math.h>

Dongxu::Dongxu(void)
{
}
Dongxu::Dongxu(CPoint px1,CPoint px2)
{
	p1.x=px1.x;
	p1.y=px1.y;
	p2.x=px2.x;
	p2.y=px2.y;
	if(p1.y<p2.y)
	{
		x1=p1.x;
		x2=p2.x;
		y1=p1.y;
		y2=(abs(x2-x1)-(p2.y-y1))+p2.y;
	}
	else
	{
		x1=p2.x;
		x2=p1.x;
		y1=p2.y;
		y2=(abs(x2-x1)-(p2.y-y1))+p2.y;
	}
	if(x1<x2)
	{
		x3=x1+abs(2*(x2-x1))/7;
		y3=y1+abs(2*(y2-y1))/7;
		x4=x2-abs(2*(x2-x1))/7;
		y4=y2-abs(2*(y2-y1))/7;
	}
	else
	{
		x3=x1-abs(2*(x2-x1))/7;
		y3=y1+abs(2*(y2-y1))/7;
		x4=x2+abs(2*(x2-x1))/7;
		y4=y2-abs(2*(y2-y1))/7;
	}
	
}
void Dongxu::thietlap(int mx1,int my1,int mx2,int my2)
{
	x1=mx1;y1=my1;
	x2=mx2;y2=my2;
	x3=x1+abs(2*(x2-x1))/7;
	y3=y1+abs(2*(y2-y1))/7;
	x4=x2-abs(2*(x2-x1))/7;
	y4=y2-abs(2*(y2-y1))/7;
}
void Dongxu::ve(CClientDC *pDC)
{
	pDC->Ellipse(x1,y1,x2,y2);
	pDC->Ellipse(x3,y3,x4,y4);
}

float Dongxu::dientich()
{
	float kq1=0,kq2=0,kq=0,r1,r2;
	r1=abs(x2-x1)/2;
	r2=abs(x4-x3)/2;
	kq1=3.14*r1*r1;
	kq2=3.14*r2*r2;
	kq=kq1-kq2;
	return kq;
}
float Dongxu::chuvi()
{
	float kq=0,r;
	r=abs(x2-x1)/2;
	kq=2*3.14*r;
	return kq;
}
int Dongxu::tronghinh(CPoint p)
{
	int kq=0;
	if(p.x>=x1&&p.y>=y1&&p.x<=x2&&p.y<=y2)
		kq=1;
	return kq;
}
void Dongxu::phongto()
{
	x1-=10;y1-=10;
	x2+=10;y2+=10;
	x3=x1+abs(2*(x2-x1))/7;
	y3=y1+abs(2*(y2-y1))/7;
	x4=x2-abs(2*(x2-x1))/7;
	y4=y2-abs(2*(y2-y1))/7;
}
void Dongxu::thunho()
{
	x1 += 10; y1 += 10;
	x2 -= 10; y2 -= 10;
	x3=x1+abs(2*(x2-x1))/7;
	y3=y1+abs(2*(y2-y1))/7;
	x4=x2-abs(2*(x2-x1))/7;
	y4=y2-abs(2*(y2-y1))/7;
}
void Dongxu::butbandau(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
}
void Dongxu::xoahinh(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
}
void Dongxu::dctrai()
{
	x1+=-5;
	x2+=-5;
}
void Dongxu::dcphai()
{
	x1+=5;
	x2+=5;
}
void Dongxu::dclen()
{
	y1+=-5;
	y2+=-5;
}
void Dongxu::dcxuong()
{
	y1+=5;
	y2+=5;
}
Dongxu::~Dongxu(void)
{
}
