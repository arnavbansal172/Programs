#include <bits/stdc++.h>
using namespace std;

// program to take input of two arrays nums and numsdivide
//return the minimum number of deletions such that the smallest element in nums divides all element of numsdivide
// if not possible, return -1
//note that an integr x divides y if y%x == 0

int smallestDivisor(vector<int>& nums, vector<int>& numsdivide) {
    int n = nums.size();
    int m = numsdivide.size();
    int ans = INT_MAX;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(numsdivide[j] % nums[i] == 0) {
                ans = min(ans, numsdivide[j] / nums[i]);
            }
        }
    }
    if(ans == INT_MAX) {
        return -1;
    }
    return ans;
}