//find all possible permutation of given array of distinct element using   backtracking
#include<bits/stdc++.h>
#include<iostream>
using namespace std;
void permute(int *a,int i,int n){
    if(i==n){
        for(int j=0;j<n;j++)
            cout<<a[j]<<" ";
        cout<<endl;
        return;
    }
    for(int j=i;j<n;j++){
        swap(a[i],a[j]);
        permute(a,i+1,n);
        swap(a[i],a[j]);
    }
}

int main(){
    int a[]={1,2,3};
    permute(a,0,3);
    return 0;
}
