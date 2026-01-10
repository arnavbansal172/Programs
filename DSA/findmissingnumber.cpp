// find the miising number
//input n =5
//62134
//output 5
#include <stdio.h>
#include <iostream>
#include<stdlib.h>

int main(){
    int n;
    scanf("%d", &n);
    int arr[n];
    int counter[n+1];

    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
        counter [i] = 0;
    }

    counter[n] = 0;

    for (int i =0; i<n; i++){
        counter[arr[i]-1] = 1;
    }

    for (int i=0;i<n;i++){
        if (counter[i] == 0){
            printf("%d", i+1);
            break;
        }
    }
    return 0;
    }
