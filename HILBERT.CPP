#include<iostream.h>
#include<graphics.h>
#include<dos.h>
#include<conio.h>
#include<math.h>
void move(int j,int h,int &x,int &y)
{
	if(j==1)
	{
		y-=h;
	}
	else if(j==2)
	{
		x+=h;
	}
	else if(j==3)
	{
		y+=h;
	}
	else if(j==4)
	{
		x-=h;
	}
	lineto(x,y);
}
void hilbert(int r,int d,int l,int u,int n,int h,int &x,int &y)
{
	if(n>0)
	{
		n--;
		hilbert(d,r,u,l,n,h,x,y);
		move(r,h,x,y);
		hilbert(r,d,l,u,n,h,x,y);
		move(d,h,x,y);
		hilbert(r,d,l,u,n,h,x,y);
		move(l,h,x,y);
		hilbert(u,l,d,r,n,h,x,y);
	}
}
int main()
{
	int n;
	cout<<"enter the value for n:";
	cin>>n;
	int x0=50,y0=150,x,y,h=10,u=1,r=2,d=3,l=4;
	x=x0;
	y=y0;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"//TURBOC3//BGI");
	moveto(x,y);
	hilbert(r,d,l,u,n,h,x,y);
	delay(10000);
	closegraph();
	return 0;
}
