#include "StdAfx.h"
#include "Ngoisao.h"
#include "math.h"

Ngoisao::Ngoisao(void)
{
}

Ngoisao::Ngoisao(CPoint px1,CPoint px2)
{
	x1=px1.x;y1=px1.y;
	x2=px2.x;y2=px2.y;
	xt=x1;
	r = (x2-x1)/sin((36*3.14)/180);
	yt=y2-(r*cos((36*3.14)/180));
	for(int i=0;i<5;i++)
	{
		x[i]=xt+r*cos((i*72+270)*3.14/180);
		y[i]=yt+r*sin((i*72+270)*3.14/180);
	}
	//x1=x[0];x2=x[1];x3=x[2];x4=x[3];x5=x[4];
	//y1=y[0];y2=y[1];y3=y[2];y4=y[3];y5=y[4];
}
void Ngoisao::thietlap(int mx1,int my1,int mx2,int my2)
{
	x1=mx1;y1=my1;
	x2=mx2;y2=my2;
	xt=x1;
	r = (x2-x1)/sin((36*3.14)/180);
	yt=y2-(r*cos((36*3.14)/180));
	for(int i=0;i<5;i++)
	{
		x[i]=xt+r*cos((i*72+270)*3.14/180);
		y[i]=yt+r*sin((i*72+270)*3.14/180);
	}
	//x1=x[0];x2=x[1];x3=x[2];x4=x[3];x5=x[4];
	//y1=y[0];y2=y[1];y3=y[2];y4=y[3];y5=y[4];
}
void Ngoisao::ve(CClientDC *pDC)
{
	/*pDC->MoveTo(x1,y1);
	pDC->LineTo(x3,y3);
	pDC->MoveTo(x1,y1);
	pDC->LineTo(x4,y4);
	pDC->MoveTo(x2,y2);
	pDC->LineTo(x4,y4);
	pDC->MoveTo(x2,y2);
	pDC->LineTo(x5,y5);
	pDC->MoveTo(x3,y3);
	pDC->LineTo(x5,y5);*/
	pDC->MoveTo(x[0],y[0]);
	pDC->LineTo(x[2],y[2]);
	pDC->MoveTo(x[0],y[0]);
	pDC->LineTo(x[3],y[3]);
	pDC->MoveTo(x[1],y[1]);
	pDC->LineTo(x[3],y[3]);
	pDC->MoveTo(x[1],y[1]);
	pDC->LineTo(x[4],y[4]);
	pDC->MoveTo(x[2],y[2]);
	pDC->LineTo(x[4],y[4]);

}
float Ngoisao::dientich()
{
	float kq=0;
	kq=2*r*cos((18*3.14)/180);
	return kq;
}
float Ngoisao::chuvi()
{
	return 0;
}
int Ngoisao::tronghinh(CPoint p)
{
	int kq=0;
	if(p.x>=x1&&p.y>=y1&&p.x<=x2&&p.y<=y2)
		kq=1;
	return kq;
}
void Ngoisao::phongto()
{
	x[0]-=10;y[0]-=10;
	x[0]-=10;y[0]-=10;
	x[2]+=10;y[2]+=10;
	//x3+=;y3+=;
	//x4+
}
void Ngoisao::thunho()
{
	x1 += 10; y1 += 10;
	x2 -= 10; y2 -= 10;
}
void Ngoisao::butbandau(CClientDC *pDC)
{
	CPen *pen1 = new CPen(PS_SOLID,1,RGB(0,0,0));
	pDC->SelectObject(pen1);
}
void Ngoisao::xoahinh(CClientDC *pDC)
{
	CPen *pen2 = new CPen(PS_SOLID,1,RGB(255,255,255));
	pDC->SelectObject(pen2);
}
void Ngoisao::dctrai()
{
	/*x[0]+=-5;
	x[1]+=-5;
	x[2]+=-5;
	x[3]+=-5;
	x[4]+=-5;*/
}
void Ngoisao::dcphai()
{
	/*x[0]+=5;
	x[1]+=5;
	x[2]+=5;
	x[3]+=5;
	x[4]+=5;*/
}
void Ngoisao::dclen()
{
	/*y[0]+=-5;
	y[1]+=-5;
	y[2]+=-5;
	y[3]+=-5;
	y[4]+=-5;*/
}
void Ngoisao::dcxuong()
{
	/*y[0]+=5;
	y[1]+=5;
	y[2]+=5;
	y[3]+=5;
	y[4]+=5;*/
}

Ngoisao::~Ngoisao(void)
{
}
