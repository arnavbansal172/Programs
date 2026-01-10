//given a substring find the length of longest substring without repeating
//characters
#include <bits/stdc++.h>
using namespace std;
int lengthOfLongestSubstring(string s) {
    int n = s.length();
    int i = 0, j = 0, ans = 0;
    unordered_map<char, int> m;
    while (j < n) {
        m[s[j]]++;
        if (m.size() == j - i + 1) {
            ans = max(ans, j - i + 1);
        } else if (m.size() < j - i + 1) {
            while (m.size() < j - i + 1) {
                m[s[i]]--;
                if (m[s[i]] == 0)
                    m.erase(s[i]);
                i++;
            }
        }
        j++;
    }
    return ans;
}

int main() {
    string s = "abcabcbb";
    cout << lengthOfLongestSubstring(s);
    return 0;
}

//time complexity O(n)
//space complexity O(n)