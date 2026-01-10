//Given an integer array nums, return the number of longest increasing subsequences. Notice that the sequence has to be strictly increasing.
//Sample Input:
//5
//1 3 5 4 7
//Sample Output:
//2
//Explanation:
//The two longest increasing subsequences are [1, 3, 4, 7] and [1, 3, 5, 7].
//Expected Time Complexity: O(n^2)
//Expected Space Complexity: O(n)
//Expected Auxiliary Space: O(n)
//Input (stdin)
//5
//1 3 5 4 7
//Your Output (stdout)
//4
//Expected Output
//2
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> dp(n,1);
    vector<int> count(n,1);
    int max_length=1;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(v[i]>v[j])
            {
                if(dp[j]+1>dp[i])
                {
                    dp[i]=dp[j]+1;
                    count[i]=count[j];
                }
                else if(dp[j]+1==dp[i])
                {
                    count[i]+=count[j];
                }
            }
        }
        max_length=max(max_length,dp[i]);
    }
    int ans=0;
    for(int i=0;i<n;i++)
    {
        if(dp[i]==max_length)
        {
            ans+=count[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}

