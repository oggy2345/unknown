#include<iostream.h>
#include<graphics.h>
#include<conio.h>
#include<dos.h>
#include<math.h>

int main()
{
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"//TURBOC3//BGI");
	float x=1,y=0.00000,j=0.5,count=0.1;
	float r=15;
	setcolor(14);
	line(0,215,650,215);
	for(int k=0;k<=7;k++)
	{
		for(float i=90;i<270;i+=10)
		{
			y=cos(((i*22/7)/180))/j;
			if(y>0)
			y=-y;
			x+=5;
			setcolor(14);
			setfillstyle(1,14);
			circle(x,y*100+200,14);
			floodfill(x,y*100+200,14);
			delay(200);
			setcolor(0);
			setfillstyle(1,0);
			circle(x,y*100+200,r);
			floodfill(x,y*100+200,0);
		}
		j+=count;
		count+=0.1;
	}
	getch();
	return 0;
}



