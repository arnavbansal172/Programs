//Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.
//Input: height = [4,2,0,3,2,5]
//Output: 9

#include<stdio.h>
#include<vector>
#include<algorithm.h>

using namespace std;
int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)
        {
            return 0;
        }
        int left[n];
        int right[n];
        left[0]=height[0];
        for(int i=1;i<n;i++)
        {
            left[i]=max(left[i-1],height[i]);
        }
        right[n-1]=height[n-1];
        for(int i=n-2;i>=0;i--)
        {
            right[i]=max(right[i+1],height[i]);
        }
        int water=0;
        for(int i=0;i<n;i++)
        {
            water+=min(left[i],right[i])-height[i];
        }
        return water;
    }
    int main()
    {
        vector<int> height={4,2,0,3,2,5};
        cout<<trap(height);
    }
