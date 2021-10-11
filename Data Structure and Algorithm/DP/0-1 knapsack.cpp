#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define rep(i,a,b) for(int i = a; i < b; i++)
#define mod 1000000007
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)

using namespace std;

void init_code(){
    fast_io;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("error.txt", "w", stderr);
    #endif 
} 

void knapsack(vector<pair<int,int>>p,int cap,int n)
{
   int dp[n+1][cap+1];
   for(int i=0;i<=n;i++)
   {
      for(int j=0;j<=cap;j++)
      {
         if(i==0 || j==0)
         {
            dp[i][j]=0;
         }
         else if(p[i-1].first<=j) // weight of ith element is less than or equal to current capacity of knapsack
         {
            dp[i][j]=max(dp[i-1][j],p[i-1].second+dp[i-1][j-p[i-1].first]);
         }
         else
         {
            dp[i][j]=dp[i-1][j];
         }
      }
   }
   cout<<dp[n][cap]<<"\n";
}
void solve()
{
   int n;
   //input number of elements
   cin>>n;
   
   int wt,val,max_cap;
   //input max capacity of knapsack
   cin>>max_cap;

   //input properties of item(weight,value)
   vector<pair<int,int> >p;
   for(int i=0;i<n;i++)
   {
      cin>>wt>>val;
      p.pb(mp(wt,val));
   }
   knapsack(p,max_cap,n);


}
int main() {
   init_code();
   int t = 1; 
   //cin >> t;
   while(t--){
         solve();
   }
   return 0;
}
