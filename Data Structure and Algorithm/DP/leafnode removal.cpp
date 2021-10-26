// Problem Description:
// Given a non-rooted tree using at max k operations (where in each operation you can
// remove all the laef nodes of tree).Find the number of nodes left after k operations.
// Notes:
// 1)applying an operation to an empty tree (of 0 vertices) does not change it;
// 2)applying an operation to a tree of one vertex removes this vertex (this vertex is treated as a leaf);
// 3)applying an operation to a tree of two vertices removes both vertices (both vertices are treated as leaves).

#include <bits/stdc++.h>
#define int long long
//AND THE SHOW BEGINS :)//
using namespace std;
signed main()
{
    int t = 1;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> adj[n + 1];
        vector<int> deg(n + 1);
        for (int i = 0; i < (n - 1); i++)
        {
            int a, b;
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
            deg[a]++;
            deg[b]++;
        }
        vector<int> leaf;
        for (int i = 1; i <= n; i++)
        {
            if (deg[i] == 1)
                leaf.push_back(i);
        }
        int ans = n;
        while (leaf.size() && k)
        {
            ans -= leaf.size();
            k--;
            vector<int> temp;
            for (int i = 0; i < leaf.size(); i++)
            {
                for (auto it : adj[leaf[i]])
                {
                    deg[it]--;
                    if (deg[it] == 1)
                        temp.push_back(it);
                }
            }
            leaf = temp;
        }
        cout << (n == 1 ? 0 : ans) << " ";
    }
    return 0;
}
