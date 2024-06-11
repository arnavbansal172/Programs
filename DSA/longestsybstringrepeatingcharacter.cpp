//longest substring with repeating characters
#include<bits/stdc++.h>
using namespace std;
int longestSubstring(string s){
    int n=s.length();
    int ans=0;
    for(int i=0;i<n;i++){
        unordered_set<char> st;
        for(int j=i;j<n;j++){
            if(st.find(s[j])!=st.end())
                break;
            else{
                ans=max(ans,j-i+1);
                st.insert(s[j]);
            }
        }
    }
    return ans;
}
int main(){
    string s="abcabcbb";
    cout<<longestSubstring(s);
    return 0;
}

//time complexity O(n^2)
//space complexity O(n)
//this code is contributed by Surbhi Tyagi
// Path: DSA/longestsybstringrepeatingcharacter.cpp
// Compare this snippet from DSA/gcd.cpp:
// //gcd of two numbers
// int gcd(int a, int b){
//     if(b==0)
//         return a;
//     return gcd(b, a%b);
// }
// Compare this snippet from DSA/smallestdivisorinlist.cpp:
// #include <bits/stdc++.h>
// using namespace std;
