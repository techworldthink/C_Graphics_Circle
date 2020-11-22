#include<stdio.h>
#include<graphics.h>
#include<math.h>


float cal_cos(float n)
{

    float accuracy = 0.0001, x1, denominator, cosx, cosval;



    // Converting degrees to radian

    n = n * (3.142 / 180.0);



    x1 = 1;



    // maps the sum along the series

    cosx = x1;



    // holds the actual value of sin(n)

    cosval = cos(n);

    int i = 1;

    do

    {

        denominator = 2 * i * (2 * i - 1);

        x1 = -x1 * n * n / denominator;

        cosx = cosx + x1;

        i = i + 1;

    } while (accuracy <= fabs(cosval - cosx));

    return cosx;
}

float  cal_sin(float n)
{

    float accuracy = 0.0001, denominator, sinx, sinval;



    // Converting degrees to radian

    n = n * (3.142 / 180.0);



    float x1 = n;



    // maps the sum along the series

    sinx = n;



    // holds the actual value of sin(n)

    sinval = sin(n);

    int i = 1;

    do

    {

        denominator = 2 * i * (2 * i + 1);

        x1 = -x1 * n * n / denominator;

        sinx = sinx + x1;

        i = i + 1;

    } while (accuracy <= fabs(sinval - sinx));


    return sinx;
}

int main()
{

    int iloop,oloop;
    float x1,y1,x2,y2;
    int angle1=0,angle2=0;
    int s=260;
    int r=160;
    int gdriver=DETECT,gmode;
    initgraph(&gdriver,&gmode,"C:\\TURBOC3\\BGI");
    setviewport(0,0,500,500,1);
    circle(260,260,160);
    for(oloop=0;oloop<12;oloop++)
    {
        for(iloop=0;iloop<11;iloop++)
        {

          x1=cal_cos(angle1);
          y1=cal_sin(angle1);
          x2=cal_cos(angle2);
          y2=cal_sin(angle2);
          //printf(" %d ",angle2);
         // printf(" %f   %f \t",x2,y2);
       //   printf("  %f   %f    %f   %f \n",r*x1+s,r*y1+s,r*x2+s,r*y2+s);
           line(r*x1+s,r*y1+s,r*x2+s,r*y2+s);
          //printf("%f \n",cos(90*(3.142/180)));
         printf("%f \n",x2);
        //circle(r*x1+s,r*y1+s,40);
        delay(100);
           angle2=angle2+30;

        }
        angle2=oloop*30;
          angle1=angle1+30;

    }

    system("PAUSE");
    closegraph();
    return 0;
}

