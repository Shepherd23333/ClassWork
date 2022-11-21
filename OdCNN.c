#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAXL 1145
int comp(const void* a, const void* b){   //used in qsort()
    return *(int*)b-*(int*)a;
}
int Cvl(int data[],int dl,int core[],int cl,int result[]){
    int rl=0;
    for(int i=0;i<=dl-cl;i++){          //scan the array one by one
        int sum=0;
        for(int j=0;j<cl;j++)           
            sum+=data[i+j]*core[j];
        result[rl++]=sum;   //the result is stored in array
    }
    return rl;      //return the length of the result array
}
int Pool(int data[],int dl,int len,int result[]){
    int rl=0;
    for(int i=0;i<dl;i+=len){
        int t[len],tl=(i+len>dl)?(dl-i):len;    //avoid "ArrayOutOfBoundsException"
        for(int j=0;j<tl;j++)
            t[j]=data[i+j];
        qsort(t,tl,sizeof(t[0]),comp);   //sort the array,and the first element is the maximum.
        result[rl++]=t[0];
    }
    return rl;
}
int main(){
    int d[MAXL],c[MAXL],l,dl=0,cl=0;
    char ch;
    printf("THE MAX NUMBER IS %d\ndata:",MAXL);
    while((ch=getchar())!='\n'){    //read the data until line feed,the number is unknown.
        if(isdigit(ch)||ch=='-')    //judge the digit(including the negative digit)
            ungetc(ch,stdin);
        scanf("%d",&d[dl++]);
    }
    printf("Cvl core:");
    while((ch=getchar())!='\n'){    //read the core
        if(isdigit(ch)||ch=='-')
            ungetc(ch,stdin);
        scanf("%d",&c[cl++]);
    }    
    int t[MAXL],tl;
    tl=Cvl(d,dl,c,cl,t);
    printf("Cvl result:");
    for(int i=0;i<tl;i++)
        printf("%d ",t[i]);
    printf("\n");                   //Cvl completed
    printf("pool length:");
    scanf("%d",&l);
    int r[MAXL],rl;
    rl=Pool(t,tl,l,r);
    printf("Pool result:");
    for(int i=0;i<rl;i++)
        printf("%d ",r[i]);     //Pool completed
    return 0;
}
/*
    (your idea here)
*/