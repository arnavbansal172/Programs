//Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

//The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.The test cases are generated such that the number of unique combinations that sum up to target is less than 150 combinations for the given input.
//3 8 
//2 3 5
//Your Output (stdout)

//2 2 3
//7
//Expected Output

//2 2 2 2
//2 3 3
//3 5
//Your Output (stdout)

//2 2 2 2
//2 3 3
//3 5
//Expected Output

#include<bits/stdc++.h>
using namespace std;
void print(vector<int> &v)
{
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
}
void solve(vector<int> &v,int target,int i,vector<int> &temp)
{
    if(target==0)
    {
        print(temp);
        return;
    }
    if(target<0)
    {
        return;
    }
    for(int j=i;j<v.size();j++)
    {
        temp.push_back(v[j]);
        solve(v,target-v[j],j,temp);
        temp.pop_back();
    }
}
int main()
{
    int n,target;
    cin>>n>>target;
    vector<int> v(n);
    for(int i=0;i<n;i++)
    {
        cin>>v[i];
    }
    vector<int> temp;
    solve(v,target,0,temp);
    return 0;
}
