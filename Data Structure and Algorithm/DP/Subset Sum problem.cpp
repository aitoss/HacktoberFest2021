// Problem Statement:
// Given an array of non-negative integers, and a value sum,
// determine if there is a subset of the given set with sum equal to given sum.
// Output:if such subset exists print 1 else 0;

#include <bits/stdc++.h>
#define int long long
//AND THE SHOW BEGINS :)//
using namespace std;
int dp[10005][10005];
bool check(int current, int sum, int arr[], int n)
{
    if (n == 0)
        return false;
    if (dp[current][n - 1] != -1)
        return dp[current][n - 1];
    else if (current + arr[n - 1] == sum)
        return dp[current][n - 1] = 1;
    else if (current + arr[n - 1] < sum)
    {
        return dp[current][n - 1] = ((check(current + arr[n - 1], sum, arr, n - 1)) || (check(current, sum, arr, n - 1)));
    }
    else
    {
        return dp[current][n - 1] = check(current, sum, arr, n - 1);
    }
}
signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, sum;
        cin >> n >> sum;
        int arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        int current = 0;
        memset(dp, -1, sizeof(dp));
        cout << check(current, sum, arr, n);
    }
    return 0;
}
