#include<stdio.h>
#include<math.h>

void survive(int n,int e, int d){
    int sweetrequired = e*d;
    int days = d/7;
    double day = d/7.0;
    int dp = d - days;

    if(e>n){
        return -1;
    }
    if (n*dp < e*d){
        return -1;
    }
    if(n*dp >= e*d){
        return ceil(day);
    }
}

int main(){
    int n,e,d;
    scanf("%d %d %d",&n,&e,&d);
    printf("%d",survive(n,e,d));
    return 0;
}