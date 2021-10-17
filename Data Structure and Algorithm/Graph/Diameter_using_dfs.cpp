#include <bits/stdc++.h>
using namespace std;

#define rep(i, init, n) for (ll i = init; i < n; i++)
#define endl '\n'
#define pb push_back
#define vi vector<int>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)



vi ar[100001];
int n, dis[100001], max_dis = 0, farthest_node = 1;
bool vis[100001];



void refresh()
{
    rep(i, 0, n + 1)
    {
        vis[i] = 0;
        dis[i] = -1;
    }
    max_dis = 0;
}




void dfs(ll node)
{
    vis[node] = 1;
    if (dis[node] > max_dis)
    {
        max_dis = dis[node];
        farthest_node = node;
    }

    for (auto it : ar[node])
    {
        if (!vis[it])
        {
            dis[it] = dis[node] + 1;
            dfs(it);
        }
    }
}





int main()
{
    int u, v;

    cout << "Enter the number of nodes: " << endl;
    cin >> n;
    cout << "Enter the edges" << endl;

    rep(i, 0, n - 1)
    {
        cin >> u >> v;
        ar[u].pb(v);
        ar[v].pb(u);
    }

    dis[1] = 0;
    dfs(1);

    refresh();
    dis[farthest_node] = 0;
    dfs(farthest_node);

    cout << "Diameter of the tree is: " << max_dis + 1 << endl;
    return 0;
}

