#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>
void ddaline(x1,y1,x2,y2)
{
	int dx=x2-x1;
	int dy=y2-y1;
	int steps=dx>dy?dx:dy;
	float xinc=dx/(float)steps;
	float yinc=dy/(float)steps;
	float x=x1;
	float y=y1;
	for(int i=0;i<=steps;i++)
	{
		putpixel(x,y,14);
		x+=xinc;
		y+=yinc;
	}
}
void display(int xc,int yc,int x,int y)
{
	putpixel(xc-x,yc+y,3);
	putpixel(xc+x,yc+y,3);
	putpixel(xc-x,yc-y,3);
	putpixel(xc+x,yc-y,3);
	putpixel(xc+y,yc+x,3);
	putpixel(xc-y,yc+x,3);
	putpixel(xc+y,yc-x,3);
	putpixel(xc-y,yc-x,3);
}
void circleb(int x1,int y1,int r)
{

	int x=0;
	int y=r;
	int d=3-2*r;
	display(x1,y1,x,y);
	while(y>=x)
	{
		x++;
		if(d>0)
		{
			y--;
			d=d+4*(x-y)+10;
		}
		else
		{
			d=d+4*x+6;
		}
		display(x1,y1,x,y);
	}
}
int main()
{
	int x,y,x1,y1,x2,y2,r;
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"//TURBOC3//BGI");
	circleb(150,180,57);
	circleb(150,180,57/2);
	ddaline(102,150,198,150);
	ddaline(102,150,150,236);
	ddaline(150,236,198,150);
	getch();
	delay(1000);
	closegraph();
	return 0;
}