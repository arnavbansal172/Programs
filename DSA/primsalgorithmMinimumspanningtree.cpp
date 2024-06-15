//Prims MST
//A connected and undirected graph is given. Find the cost of minimum spanning tree.
//Note : If there is no edge given for a node, you may skip that node in MST.
//Input Format:
//First line - n and m, the number of nodes and edges
//Then there are m lines each containing u, v, and w.
//u and v are the nodes and w is the weight of the edge.
//Output Format:
//A single integer representing the cost of minimum spanning tree.
//Sample Input:
//9 13
//0 1 4
//1 2 8
//2 3 7
//3 4 9
//4 5 10
//5 6 2
//6 7 1
//0 7 8
//1 7 11
//7 8 7
//2 8 2
//2 5 4
//3 5 14
//Sample Output:
//37
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,m;
    cin>>n>>m;
    vector<pair<int,int>> adj[n];
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});
        adj[v].push_back({u,w});
    }
    int parent[n];
    int key[n];
    bool mstSet[n];
    for(int i=0;i<n;i++)
    {
        key[i]=INT_MAX;
        mstSet[i]=false;
    }
    key[0]=0;
    parent[0]=-1;
    for(int i=0;i<n-1;i++)
    {
        int mini=INT_MAX,u;
        for(int v=0;v<n;v++)
        {
            if(mstSet[v]==false && key[v]<mini)
            {
                mini=key[v];
                u=v;
            }
        }
        mstSet[u]=true;
        for(auto it:adj[u])
        {
            int v=it.first;
            int weight=it.second;
            if(mstSet[v]==false && weight<key[v])
            {
                parent[v]=u;
                key[v]=weight;
            }
        }
    }
    int sum=0;
    for(int i=1;i<n;i++)
    {
        sum+=key[i];
    }
    cout<<sum<<endl;
    return 0;
}
//Time Complexity: O(n^2)   
//Space Complexity: O(n)

