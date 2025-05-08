#include<stdio.h>
#include<math.h>

int survive(int n,int e, int d){
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
        printf("%s",ceil(day));
    }
}

int main(){
    int n,e,d;
    int x = survive (n,e,d); 
    scanf("%d %d %d",&n,&e,&d);
    printf("%d",x);
    return 0;
}