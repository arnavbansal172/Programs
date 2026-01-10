//Given two integer arrays val[0..n-1] and wt[0..n-1] that represent values and weights associated with n items respectively. Find out the maximum value subset of val[] such that sum of the weights of this subset is smaller than or equal to Knapsack capacity W.
//Input format:
//W - the total weight that the knapsack can hold
//N – denotes the number of items in the graph
//w, v – weight of the item, value of the item.
//Output format:
//The output is an integer – maximum possible profit
//Input:
//First thing in every pair is weight of item
//and second thing is value of item
//Item arr[] = {{2, 40}, {3.14, 50}, {1.98, 100},
//              {5, 95}, {3, 30}};
//Knapsack Capacity W = 10
//Output:
//The maximum possible profit = 235
//Explanation: The maximum possible profit is 235 by selecting items 1, 4 and 5.
//Input (stdin)
//3
//60 100 120
//3
//10 20 30
//50
//Output (stdout)
//220
//Explanation: The maximum possible profit is 220 by selecting items 1, 2 and 3.
#include<bits/stdc++.h>
using namespace std;
int knapsack(int W,int wt[],int val[],int n)
{
    int dp[n+1][W+1];
    for(int i=0;i<=n;i++)
    {
        for(int w=0;w<=W;w++)
        {
            if(i==0 || w==0)
            {
                dp[i][w]=0;
            }
            else if(wt[i-1]<=w)
            {
                dp[i][w]=max(val[i-1]+dp[i-1][w-wt[i-1]],dp[i-1][w]);
            }
            else
            {
                dp[i][w]=dp[i-1][w];
            }
        }
    }
    return dp[n][W];
}
int main()
{
    int n;
    cin>>n;
    int val[n],wt[n];
    for(int i=0;i<n;i++)
    {
        cin>>val[i];
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>wt[i];
    }
    int W;
    cin>>W;
    cout<<knapsack(W,wt,val,n);
}
