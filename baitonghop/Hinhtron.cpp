#include "StdAfx.h"
#include "Hinhtron.h"
#include <math.h>

Hinhtron::Hinhtron(void)
{
}
Hinhtron::Hinhtron(CPoint px1,CPoint px2)
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
void Hinhtron::thietlap(int mx1,int my1,int mx2,int my2)
{
	x1=mx1;y1=my1;
	x2=mx2;y2=my2;
}
void Hinhtron::ve(CClientDC *pDC)
{
	pDC->Ellipse(x1,y1,x2,y2);
}
float Hinhtron::dientich()
{
	float kq=0,r;
	r=abs(x2-x1)/2;
	kq=3.14*r*r;
	return kq;
}
float Hinhtron::chuvi()
{
	float kq=0,r;
	r=abs(x2-x1)/2;
	kq=2*3.14*r;
	return kq;
}
int Hinhtron::tronghinh(CPoint p)
{
	int kq=0;
	if(p.x>=x1&&p.y>=y1&&p.x<=x2&&p.y<=y2)
		kq=1;
	return kq;
}
void Hinhtron::phongto()
{
	x1-=10;y1-=10;
	x2+=10;y2+=10;
}
void Hinhtron::thunho()
{
	x1 += 10; y1 += 10;
	x2 -= 10; y2 -= 10;
}
void Hinhtron::butbandau(CClientDC *pDC)
{
	CPen *pen1 = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(pen1);
}
void Hinhtron::xoahinh(CClientDC *pDC)
{
	CPen *pen2 = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(pen2);
}
void Hinhtron::dctrai()
{
	x1+=-5;
	x2+=-5;
}
void Hinhtron::dcphai()
{
	x1+=5;
	x2+=5;
}
void Hinhtron::dclen()
{
	y1+=-5;
	y2+=-5;
}
void Hinhtron::dcxuong()
{
	y1+=5;
	y2+=5;
}
Hinhtron::~Hinhtron(void)
{
	
		 
}
