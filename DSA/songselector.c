//int PlayList(int airtime, int songs[], int n, int k)
//the function accepts an positive integer airtime, an array of positive integers songs of size n argument, an integer n  as its arguments. The function is expected to return an integer representing the 3 songs that can be played whose sume is exactly equal to airtime
//if no such songs are found the function should return -1
//Note:
//1. Each song can be played only once
//2. The songs should be played in the order they appear in the array
//3. The function should return -1 if no such songs are found
//Example
//Input
//airtime: 10
//songs: 1 3 4 5 6
//n: 5
//Output
//1 3 6
//Explanation
//The sum of 1, 3 and 6 is 10
//Hence 1 3 6 is the output

#include <stdio.h>
#include <stdlib.h>

int main(){
    int airtime;
    int n;
    scanf("%d\n %d",&airtime,&n);

    int songs[n];
    for(int i=0;i<n;i++){
        scanf("%d",&songs[i]);
    }
    int found = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(songs[i]+songs[j]+songs[k] == airtime){
                    printf("%d %d %d",songs[i],songs[j],songs[k]);
                    found = 1;
                    break;
                }
            }
            if(found == 1){
                break;  
            }
        }
        if(found == 1){
            break;
        }
    }
    if(found == 0){
        printf("-1");
    }

    return 0;
}