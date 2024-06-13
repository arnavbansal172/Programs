//Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.
//
//Example:
//
//Input: "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//Note:
//
//Although the above answer is in lexicographical order, your answer could be in any order you want.
#include<iostream>
#include<vector>
#include<string>
using namespace std;
vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.size()==0)
        {
            return ans;
        }
        vector<string> v={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        ans.push_back("");
        for(int i=0;i<digits.size();i++)
        {
            vector<string> temp;
            for(int j=0;j<ans.size();j++)
            {
                for(int k=0;k<v[digits[i]-'0'].size();k++)
                {
                    temp.push_back(ans[j]+v[digits[i]-'0'][k]);
                }
            }
            ans=temp;
        }
        return ans;
    }
    int main()
    {
        string s;
        cin>>s;
        vector<string> v=letterCombinations(s);
        for(int i=0;i<v.size();i++)
        {
            cout<<v[i]<<" ";
        }
    }