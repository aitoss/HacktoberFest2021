#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

#define pb emplace_back
#define mp make_pair
#define F first
#define int long long
#define S second
#define all(c)(c).begin(), (c).end()
vector<bool> visited(2 * 10e5 + 1, false);
vi sub(2 * 10e5 + 1, 0);
map<int, vi> G;
inline void dfs(int x)
{
	visited[x] = true;
	for (auto i: G[x])
		if (visited[i] == false)
		{
			dfs(i);
			sub[x] += sub[i];
		}
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vi v(n - 1);
	for (int i = 0; i < n - 1; i++)
	{
		int g;
		cin >> g;
		v[i] = g;
		G[g].pb(i + 2);
	}
	visited.resize(n + 1);
	sub.resize(n + 1);
	for (auto it: v)
	{
		sub[it]++;
	}
	dfs(1);
	for (int i = 1; i <= n; i++)
	{
		cout << sub[i] << ' ';
	}
}
