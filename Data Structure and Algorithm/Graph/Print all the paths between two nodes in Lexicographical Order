#include <bits/stdc++.h>
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
#define all(c)(c).begin(), (c).end()
#define int long long

void dfs(int a, int b, map<int, vi> &graph, vi &ans, vector<bool> &visited)
{
	visited[a - 1] = true;
	if (a == b)
	{
		for (auto it: ans)
			cout << it << " ";
		cout << endl;
		return;
	}
	else
	{
		for (auto it: graph[a])
		{
			if (visited[it - 1] == false)
			{
				ans.pb(it);
				dfs(it, b, graph, ans, visited);
				ans.pop_back();
				visited[it - 1] = false;
			}
		}
	}
}
void addEdge(int a, int b, map<int, vi> &graph)
{
	graph[a].pb(b);
	graph[b].pb(a);
}
signed main()
{#
	ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);#
	endif
	srand(time(NULL));	//for stress-testing
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int nodes;
	cin >> nodes;
	map<int, vi> graph;
	int edges;
	cin >> edges;
	for (int i = 0; i < edges; i++)
	{
		int a, b;
		cin >> a >> b;
		addEdge(a, b, graph);
	}
	int source, destination;
	cin >> source >> destination;
	vi ans;
	ans.pb(source);
	vector<bool> visited(nodes, false);
	dfs(source, destination, graph, ans, visited);
}

NOTE: Index should be 1 based indexing.
