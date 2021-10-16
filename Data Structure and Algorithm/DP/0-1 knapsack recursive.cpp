#include <bits/stdc++.h>
#define int long long
//AND THE SHOW BEGINS :)//
using namespace std;
int dp[1005][1005];
int knapSack(int W, int wt[], int val[], int n) 
{ 
    if(n==0 || W==0) return 0;
    if(dp[n-1][W]!=-1) return dp[n-1][W];
    else if(wt[n-1]<=W)
    {
        return dp[n-1][W]=max((val[n-1]+knapSack(W-wt[n-1],wt,val,n-1)),(knapSack(W,wt,val,n-1)));
    }
    else 
    {
        return dp[n-1][W]=knapSack(W,wt,val,n-1);
    }
}

signed main()
{
    int t=1;
    cin>>t;
    while(t--)
    {
        int n,w;cin>>n>>w;
        int weight[n],value[n];
        for(int i=0;i<n;i++) cin>>weight[i];
        for(int i=0;i<n;i++) cin>>value[i];
        memset(dp,(-1),sizeof(dp));
        cout<<knapSack(w,weight,value,n);
    }
    return 0;
}


