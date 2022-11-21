#include <stdio.h>
#include <math.h>
int main(){
    int i;
    double pi=acos(-1);
    /*
    from the formula we can know that the theoretical minimum value is -7,
    then we can just do something to find the argument which can get -7.
    obviously,when sinx=1 and sin x^2=-1,the argument is found.
    */
    for(i=0;;i+=2){
        double x=pi/2+i*pi;
        if(fabs(sin(x*x)+1)<1e-10)
            break;
    }
    printf("min=%.10f\nx=%d¦Ð\n",-7.0,i);
    return 0;
}
/*
    (your idea here)
*/