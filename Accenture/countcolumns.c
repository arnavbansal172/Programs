#include<stdio.h>

int main(){
    int x,y;
    scanf ("%d %d",&x,&y);
    int a[x,y];

    for (int i = 0; i < x; i++){
        for (int j = 0; j < y; j++){
            scanf("%d",&a[i,j]);
        }
    }
    int sum =0;

    for(int i = 0; i < y; i++) {
            if(i%2 ==0){
                for(int j = 0; j < x; j++){
                    sum += a[j,i];
                }
            }
            else{
                for(int j = x-1; j >= 0; j--){
                sum += a[j,i];
                }
            }
    }
    printf("%d",sum);
    return 0;
}
