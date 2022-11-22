#include <stdio.h>
#include <stdlib.h>
#define MAXL 114        // maximum length and width of arrays
int comp(const void* a, const void* b){     //used in qsort()
    return *(int*)b-*(int*)a;
}
//using pointer to deliver multi-dimentional arrays into functions
int max(const int *x,const int xa){
    int y[xa];
    for(int i=0;i<xa;i++)
        y[i]=*(x+i);        //store the element in two dimensional array
    qsort(y,xa,sizeof(int),comp);   //sort the array,and the first element is the maximum.
    return y[0];
}
void Cvl(const int *data,const int darea[],const int *core,const int carea[],int *result,int rarea[]){
    //using result[][] to store the result,rarea[] to store the width and length of result[][]
    int dw=darea[0],dl=darea[1];
    int cw=carea[0],cl=carea[1];
    for(int i=0;i<=dw-cw;i++){      //scan the array in width
        int p=0;
        for(int j=0;j<=dl-cl;j++){      //scan the array in length
            int sum=0;
            for(int m=0;m<cw;m++)
                for(int n=0;n<cl;n++)
                    sum+=*(data+MAXL*(i+m)+j+n)*(*(core+MAXL*m+n));     //equal to data[i+m][j+n]*core[m][n]
            *(result+MAXL*rarea[0]+(p++))=sum;      //equal to result[width][length]
            rarea[1]+=!i;   //the length just need to count once
        }
        rarea[0]++;
    }
}
void Pool(const int *data,const int darea[],const int area[],int *result,int rarea[]){
    int dw=darea[0],dl=darea[1];
    int w=area[0],l=area[1];
    for(int i=0;i<dw;i+=w){
        int p=0;
        for(int j=0;j<dl;j+=l){
            int tw=(i+w>dw)?(dw-i):w,tl=(j+l>dl)?(dl-j):l;      //avoid "ArrayOutOfBoundsException"
            int temp[tw][tl];
            for(int m=0;m<tw;m++)
                for(int n=0;n<tl;n++)
                    temp[m][n]=*(data+MAXL*(i+m)+j+n);
            *(result+MAXL*rarea[0]+(p++))=max(temp[0],tw*tl);
            rarea[1]+=!i;
        }
        rarea[0]++;
    }
}
int main(){
    int d[MAXL][MAXL]={0},c[MAXL][MAXL]={0},da[2]={0},ca[2]={0};
    printf("(THE MAX LENGTH IS %d.)\nthe width and length of the data:",MAXL);
    scanf("%d %d",&da[0],&da[1]);
    printf("data:\n");
    for(int i=0;i<da[0];i++)
        for(int j=0;j<da[1];j++)
            scanf("%d",&d[i][j]);
    printf("the width and length of the Cvl core:");
    scanf("%d %d",&ca[0],&ca[1]);
    printf("Cvl core:\n");
    for(int i=0;i<ca[0];i++)
        for(int j=0;j<ca[1];j++)
            scanf("%d",&c[i][j]);
    int t[MAXL][MAXL]={0},ta[2]={0};
    Cvl(d[0],da,c[0],ca,t[0],ta);
    printf("Cvl result:");
    for(int i=0;i<ta[0];i++){
        printf("\n");
        for(int j=0;j<ta[1];j++)
            printf("%d ",t[i][j]);
    }  
    printf("\n");                       //Cvl completed
    int a[2]={0};
    printf("the width and length of the pool:");
    scanf("%d %d",&a[0],&a[1]);
    int r[MAXL][MAXL]={0},ra[2]={0};
    Pool(t[0],ta,a,r[0],ra);
    printf("Pool result:\n");
    for(int i=0;i<ra[0];i++){
        for(int j=0;j<ra[1];j++)
            printf("%d ",r[i][j]);
        printf("\n");
    }                                   //Pool completed         
    return 0;
}
/*
    (your idea here)
*/