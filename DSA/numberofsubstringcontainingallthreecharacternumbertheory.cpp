//Given a string s consisting only of characters a, b and c. Return the number of substrings containing at least one occurrence of all these characters a, b and c.
//Sample Input:
//abcabc
//Sample Output:
//10
//Explanation:
//The substrings containing occurrence of the all three characters a, b and c are:
//abcabc
//abc
//abca
//abc
//bca

#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cin>>s;
    int n=s.size();
    int a=0,b=0,c=0;
    int ans=0;
    int i=0;
    for(int j=0;j<n;j++)
    {
        if(s[j]=='a')
        {
            a++;
        }
        else if(s[j]=='b')
        {
            b++;
        }
        else
        {
            c++;
        }
        while(a>0 && b>0 && c>0)
        {
            ans+=n-j;
            if(s[i]=='a')
            {
                a--;
            }
            else if(s[i]=='b')
            {
                b--;
            }
            else
            {
                c--;
            }
            i++;
        }
    }
    cout<<ans<<endl;
    return 0;
}