// Problem Statement:
// Given an array arr[] of size N, 
// check if it can be partitioned into two parts such that the sum of elements in both parts is the same.
// OUTPUT:if the array can be partitioned into two equal sum parts print
// YES else NO

#include <bits/stdc++.h>
#define int long long
//AND THE SHOW BEGINS :)//
using namespace std;
int dp[60005][500];
bool check(int current,int sum,int arr[],int n)
{
    if(n==0) return false;
    if(dp[current][n-1]!=-1) return dp[current][n-1];
    else if(current+arr[n-1]==sum) return dp[current][n-1]=1;
    else if(current+arr[n-1]<sum)
    {
        return dp[current][n-1]=((check(current+arr[n-1],sum,arr,n-1)) || (check(current,sum,arr,n-1)));
    }
    else 
    {
        return dp[current][n-1]=check(current,sum,arr,n-1);
    }
}
signed main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        int n;cin>>n;
        int arr[n];
        for(int i=0;i<n;i++) cin>>arr[i];
        int sum=0;
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++) sum+=arr[i];
        if(sum%2!=0) return 0;
        else
        {
            sum/=2;
            int current=0;
            if(check(current,sum,arr,n)) cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}


