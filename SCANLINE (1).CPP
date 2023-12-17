#include<iostream.h>
#include<dos.h>
#include<conio.h>
#include<graphics.h>
class xyz{
public:
void scanline(int[],int[],int);
};
void xyz::scanline(int xx[10],int yy[10],int n){
int i,k,temp,ymax=480,ymin=0,inx[50],y,cnt;
float m[50],dx,dy;
setcolor(WHITE);
for(i=0;i<n;i++){
if(yy[i]>=ymax)
ymax=yy[i];
if(yy[i]<=ymin)
ymin=yy[i];
dx=xx[i+1]-xx[i];
dy=yy[i+1]-yy[i];
if(dx==0)
m[i]=0;
if(dy==0)
m[i]=1;
if(dx!=0&&dy!=0)
m[i]=(float)(dx/dy);
}
for(y=ymin;y<=ymax;y++){
int cnt=0;
for(i=0;i<n;i++){
if((yy[i]>y&&yy[i+1]<=y)||(yy[i]<=y&&yy[i+1]>y)){
inx[cnt]=(xx[i]+(m[i]*(y-yy[i])));
cnt++;
}
}
for(k=0;k<cnt-1;k++){
for(i=0;i<cnt-1;i++){
if(inx[i]>inx[i+1]){
temp=inx[i];
inx[i]=inx[i+1];
inx[i+1]=temp;
}
}
}
for(i=0;i<cnt-1;i+=2){
line(inx[i],y,inx[i+1]+1,y);
delay(100);
}
}
}
int main(){
int xx[10],yy[10],n,i=0,x,y,gd=DETECT,gm=0;
xyz s;
cout<<"enter number of vertices:";
cin>>n;
for(i=0;i<n;i++){
cout<<"\n enter vertices of polygon::";
cin>>xx[i];
cin>>yy[i];
}
xx[i]=xx[0];
yy[i]=yy[0];
initgraph(&gd,&gm,"//TURBOC3//BGI");
for(i=0;i<n-1;i++){
delay(200);
line(xx[i],yy[i],xx[i+1],yy[i+1]);
}
s.scanline(xx,yy,n);
getch();
//capture("abc.bmp");
closegraph();
return 0;
}
