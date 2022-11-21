#include <stdio.h>
#include <math.h>
int main(){
    double s,r0=1,r1=0;
    while(fabs(r0-r1)>1e-10){     //gets the cross-point of y=2x-3 and y=sinx.
        r1=r0;
        r0=r1-(sin(r1)-2*r1+3)/(cos(r1)-2);
    }
    s=6+cos(r0)-cos(0)+(3-sin(r0))*(3-r0)/2;    //s1=integral(sinx-2x+3,0,r0),s2 is the area of the triangle.
    printf("%.10f\n",s);
    return 0;
}
/*
    (your idea here)
*/