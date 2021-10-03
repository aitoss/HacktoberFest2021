#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double lld;
typedef unsigned long long ull;
typedef vector<ll> vi;
typedef pair<ll, ll> pii;

#define pb emplace_back
#define mp make_pair
#define F first
#define Endl "\n"
#define S second
#define all(c) (c).begin(),(c).end()

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" : "; _print(x); cerr << endl;
#else
#define debug(x)
#pragma GCC optimize("Ofast")
#endif

#define int long long


vector<bool> visited(10e5, false);
vector<vi> ans;
void dfs(int x, map<int, vi> &G)
{
   visited[x] = true;
   for (auto& i : G[x])
   {
      if (visited[i] == false)
      {
         dfs(i, G);
      }
   }
}

signed main()
{

#ifndef ONLINE_JUDGE
   freopen("Error.txt", "w", stderr);
#endif

   srand(time(NULL));  //for stress-testing
   ios::sync_with_stdio(0);
   cin.tie(0);
   cout.tie(0);
   int nodes, edges;
   map<int, vi> graph;
   cin >> nodes >> edges;
   for (int i = 0; i < edges; i++)
   {
      int l, r;
      cin >> l >> r;
      graph[l].pb(r);
   }
   visited.resize(nodes);
   dfs(0, graph);
   for (int i = 0; i < nodes; i++)
      if (visited[i] == false)
      {
         cout << "The graph is not conected.";
         exit(0);
      }
   cout << "Graph is connected.";
}
