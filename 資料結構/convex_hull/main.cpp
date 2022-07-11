#include <iostream>
#include<cstdlib>
#include<ctime>
#include<conio.h>
#include<dos.h>
#include<graphics.h>

using namespace std;

typedef struct {
	int x;
	int y;
}point;

void draw_point(point A[]){

    int gdriver,gmode;
    gdriver=VGA;
    gmode=VGAHI;
    initgraph(&gdriver,&gmode,"c:\\tc");
    int x,y;
    for(int i=0;i<10;i++){
        x=A[i].x*3;
        y=A[i].y*3;
        cout<<"x: "<<x<<" y: "<<y<<endl;
        putpixel(x,y,LIGHTBLUE);
    }
}
void draw_line(int a, int b, int c, int d)
{
	line(a*3, b*3, c*3, d*3);
}
void judge(point A[]){
  int i,j,a,b,c,n,num1=0,num2=0;
  int flag;
  for(i=0;i<10;i++){
    for(j=i+1;j<10;j++){
        b=A[i].x-A[j].x;
        a=A[j].y-A[i].y;
        c=A[i].x*A[j].y - A[j].x*A[i].y;

        for (n = 0; n < 10; n++)
			{
				if (n!=i&&n!=j)
				{
					flag = A[n].x*a + A[n].y*b;
					if (flag< c)
						{num1++;}
					else if (flag> c)
						{num2++;}
					else {
						num1++;
						num2++;
					}
						;
				}
			}
        if(num1==8||num2==8){
            cout<<"兩點為邊界: ("<<A[i].x<<","<<A[i].y<<")("<<A[j].x<<","<<A[j].y<<")"<<endl;
            draw_line(A[i].x, A[i].y, A[j].x, A[j].y);
        }
        num1=0;num2=0;
    }
  }
}


int main()
{   point A[10];
    srand((unsigned)time(NULL));
    const int n=10;
    for(int i=0;i<n;i++){
        int a=30,b=100;
        A[i].x=(rand()%(b-a+1))+a;
        A[i].y=(rand()%(b-a+1))+a;
    }
    for(int i=0;i<10;i++){
        cout<<i+1<<":("<<A[i].x<<","<<A[i].y<<")"<<endl;
    }
    draw_point(A);
    judge(A);
    getchar();
    return 0;
}
