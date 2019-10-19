#include "StdAfx.h"
#include "Hinhvuong.h"
#include <math.h>


Hinhvuong::Hinhvuong(void)
{
}

Hinhvuong::Hinhvuong(CPoint px1,CPoint px2)
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
}
void Hinhvuong::thietlap(int mx1,int my1,int mx2,int my2)
{
	x1=mx1;y1=my1;
	x2=mx2;y2=my2;
}
void Hinhvuong::ve(CClientDC *pDC)
{
	pDC->Rectangle(x1,y1,x2,y2);
}
float Hinhvuong::dientich()
{
	float kq=0,a;
	a=abs(x2-x1);
	kq=a*a;
	return kq;
}
float Hinhvuong::chuvi()
{
	float kq=0,a;
	a=abs(x2-x1);
	kq=4*a;
	return kq;
}
int Hinhvuong::tronghinh(CPoint p)
{
	int kq=0;
	if(p.x>=x1&&p.y>=y1&&p.x<=x2&&p.y<=y2)
		kq=1;
	return kq;
}
void Hinhvuong::phongto()
{
	x1-=10;y1-=10;
	x2+=10;y2+=10;
}
void Hinhvuong::thunho()
{
	x1 += 10; y1 += 10;
	x2 -= 10; y2 -= 10;
}
void Hinhvuong::butbandau(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
}
void Hinhvuong::xoahinh(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
}
void Hinhvuong::dctrai()
{
	x1+=-5;
	x2+=-5;
}
void Hinhvuong::dcphai()
{
	x1+=5;
	x2+=5;
}
void Hinhvuong::dclen()
{
	y1+=-5;
	y2+=-5;
}
void Hinhvuong::dcxuong()
{
	y1+=5;
	y2+=5;
}
Hinhvuong::~Hinhvuong(void)
{
}
