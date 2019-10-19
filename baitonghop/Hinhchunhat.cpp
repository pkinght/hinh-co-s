#include "StdAfx.h"
#include "Hinhchunhat.h"
#include <math.h>

Hinhchunhat::Hinhchunhat(void)
{
}

Hinhchunhat::Hinhchunhat(CPoint px1,CPoint px2)
{
	p1.x=px1.x;
	p1.y=px1.y;
	p2.x=px2.x;
	p2.y=px2.y;
	x1=p1.x;y1=p1.y;
	x2=p2.x;y2=p2.y;
}
void Hinhchunhat::thietlap(int mx1,int my1,int mx2,int my2)
{
	x1=mx1;y1=my1;
	x2=mx2;y2=my2;
}
void Hinhchunhat::ve(CClientDC *pDC)
{
	pDC->Rectangle(x1,y1,x2,y2);
}
float Hinhchunhat::dientich()
{
	float kq=0,a,b;
	a=abs(x2-x1);
	b=abs(y2-x1);
	kq=a*b;
	return kq;
}
float Hinhchunhat::chuvi()
{
	float kq=0,a,b;
	a=abs(x2-x1);
	b=abs(y2-x1);
	kq=2*(a+b);
	return kq;
}
int Hinhchunhat::tronghinh(CPoint p)
{
	int kq=0;
	if(p.x>=x1&&p.y>=y1&&p.x<=x2&&p.y<=y2)
		kq=1;
	return kq;
}
void Hinhchunhat::phongto()
{
	x1-=10;y1-=10;
	x2+=10;y2+=10;
}
void Hinhchunhat::thunho()
{
	x1 += 10; y1 += 10;
	x2 -= 10; y2 -= 10;
}
void Hinhchunhat::butbandau(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(npen);
}
void Hinhchunhat::xoahinh(CClientDC *pDC)
{
	CPen *npen = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(npen);
}
void Hinhchunhat::dctrai()
{
	x1+=-5;
	x2+=-5;
}
void Hinhchunhat::dcphai()
{
	x1+=5;
	x2+=5;
}
void Hinhchunhat::dclen()
{
	y1+=-5;
	y2+=-5;
}
void Hinhchunhat::dcxuong()
{
	y1+=5;
	y2+=5;
}
Hinhchunhat::~Hinhchunhat(void)
{
}
