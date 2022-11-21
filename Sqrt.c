#include <stdio.h>
#include <math.h>
#include <time.h>
int main(){
    double x;
    scanf("%lf",&x);
    clock_t t0=clock();     //get the time when the calculation starts
    double r0=x/2,r1=0;
    while(fabs(r0-r1)>1e-10){       //Newton's formula
        r1=r0;
        r0=r1-(r1*r1-x)/2/r1;
    }
    clock_t t1=clock();     //get the time when the calculation ends
    printf("%.10f\ntime:%f\n",r0,(double)(t1-t0)/CLOCKS_PER_SEC);   //calculte how much time the calculation used
    clock_t t2=clock();
    double r=sqrt(x);
    clock_t t3=clock();
    printf("%.10f\ntime:%f\n",r,(double)(t3-t2)/CLOCKS_PER_SEC);
    return 0;
}
/*
    (your idea here)
*/