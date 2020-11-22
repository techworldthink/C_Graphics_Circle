
#include<stdio.h>
#include<graphics.h>

int main()
{
    int a[16]={100,140,180,220,260,300,340,380,420,380,340,300,260,220,180,140};
    int b[16]={260,300,340,380,420,380,340,300,260,220,180,140,100,140,180,220};
    int iloop,oloop;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    setviewport(0,0,1000,1000,10);
    circle(260,260,160);
    for(oloop=0;oloop<16;oloop++)
    {
        for(iloop=1;iloop<16;iloop++)
        {
            line(a[oloop],b[oloop],a[iloop],b[iloop]);
        }
    }


    system("PAUSE");
    closegraph();
    return 0;
}
