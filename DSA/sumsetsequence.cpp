// Given a set of non-negative integers and a value sum, the is to check if there is a subset of the given set whose sum is equal to the given sum
// input:set []= {3,34,4,12,5,2}, sum = 9
//Output: True
//There is a subset (4,5) with sum 9.
#include <iostream>
using namespace std;
bool subsetSum(int set[], int n, int sum)
{
    bool t[n + 1][sum + 1];
    for (int i = 0; i <= n; i++)
    {
        t[i][0] = true;
    }
    for (int i = 1; i <= sum; i++)
    {
        t[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {
            if (set[i - 1] > j)
            {
                t[i][j] = t[i - 1][j];
            }
            else
            {
                t[i][j] = t[i - 1][j] || t[i - 1][j - set[i - 1]];
            }
        }
    }
    return t[n][sum];
}   
int main()
{
    int set[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(set) / sizeof(set[0]);
    if (subsetSum(set, n, sum) == true)
    {
        cout << "True";
    }
    else
    {
        cout << "False";
    }
}