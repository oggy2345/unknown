#include<iostream.h>
#include<stdlib.h>
#include<conio.h>
#include<math.h>
#include<graphics.h>
#include<dos.h>

int main()
{
	int x1,y1,x2,y2,x3,y3,nx1,ny1,nx2,ny2,tx,ty,mx,my,sx,sy,nx3,ny3,ch;
	float t,r;
	int gd=DETECT,gm=0;
	initgraph(&gd,&gm,"//TURBOC3//BGI");
	cout<<"basic 2d transformations";
	cout<<"enter the points of triangle:";
	cin>>x1>>y1>>x2>>y2>>x3>>y3;
	line(x1,y1,x2,y2);
	line(x2,y2,x3,y3);
	line(x3,y3,x1,y1);
	getch();
	while(1)
	{
		cout<<"*****MENU*****\n";
		cout<<"1.translation\n2.scaling\n3.rotation\n4.exit\n";
		cout<<"enter your choice:";
		cin>>ch;
		switch(ch)
		{
			case 1:
				cout<<"enter the translation factor:";
				cin>>tx>>ty;
				nx1=x1+tx;
				ny1=y1+ty;
				nx2=x2+tx;
				ny2=y2+ty;
				nx3=x3+tx;
				ny3=y3+ty;
				line(nx1,ny1,nx2,ny2);
				line(nx2,ny2,nx3,ny3);
				line(nx3,ny3,nx1,ny1);
				getch();
				break;
			case 2:
				cout<<"enter the scaling factor:";
				cin>>sx>>sy;
				mx=(x1+x2+x3)/3;
				my=(y1+y2+y3)/3;
				nx1=mx+(x1-mx)*sx;
				ny1=my+(y1-my)*sy;
				nx2=mx+(x2-mx)*sx;
				ny2=my+(y2-my)*sy;
				nx3=mx+(x3-mx)*sx;
				ny3=my+(y3-my)*sy;
				line(nx1,ny1,nx2,ny2);
				line(nx2,ny2,nx3,ny3);
				line(nx3,ny3,nx1,ny1);
				getch();
				break;
			case 3:
				cout<<"enter the rotation angle:";
				cin>>r;
				t=3.14*r/180;
				nx1=abs(x1*cos(t)-y1*sin(t));
				ny1=abs(x1*sin(t)+y1*sin(t));
				nx2=abs(x2*cos(t)-y2*sin(t));
				ny2=abs(x2*cos(t)+y2*sin(t));
				nx3=abs(x3*cos(t)-y3*sin(t));
				ny3=abs(x3*cos(t)+y3*sin(t));
				line(nx1,ny1,nx2,ny2);
				line(nx2,ny2,nx3,ny3);
				line(nx3,ny3,nx1,ny1);
				getch();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"invalid choice";
		}
	}
	delay(20);
	closegraph();
	return 0;

}