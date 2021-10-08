#include <bits/stdc++.h>
using namespace std;
struct edge
{
	string v1, v2;
	int w;
};
class cmp
{
	public:
		bool operator()(edge e1, edge e2)
		{
			return e1.w > e2.w;
		}
};
class graph
{
		vector<edge>l;
		vector<edge>ans;
		map<string, string>mp;
		priority_queue<edge, vector<edge>, cmp>pq;
		int ver;
		int edg;
	public:
		graph()
		{
			cin >> ver >> edg;
			for (int i = 0; i < edg; i++)
			{
				edge e;
				cin >> e.v1 >> e.v2 >> e.w;
				pq.push(e);
				l.push_back(e);
				mp[e.v1] = e.v1;
				mp[e.v2] = e.v2;
			}
		}
		string find_parent(string node)
		{
			if (mp[node] == node)
				return node;
			return find_parent(mp[node]);
		}
		void unions(string node1, string node2)
		{
			mp[find_parent(node1)] = node2;
		}
		void generate()
		{
			int i = 0;
			while (!pq.empty() && i - 1 != ver)
			{
				edge e = pq.top();
				pq.pop();
				if (find_parent(e.v1) == find_parent(e.v2))
					continue;
				ans.push_back(e);
				unions(e.v1, e.v2);
				i++;
			}
			if (i + 1 != ver)
			{
				cout << "error cannot generate MST!!" << endl;
				return;
			}
		}
		~graph()
		{
			int cost = 0;
			for (edge e : ans)
			{
				cost += e.w;
				cout << e.v1 << " " << e.v2 << " " << e.w << endl;
			}
			cout << "Cost :" << cost << endl;
		}
};
class prims
{
		map<string, vector<edge>>mp;
		set<string>marked;
		vector<edge>ans;
		int ver, edg;
	public:
		prims()
		{
			cin >> ver >> edg;
			for (int i = 0; i < edg; i++)
			{
				edge e;
				cin >> e.v1 >> e.v2 >> e.w;
				mp[e.v1].push_back(e);
				mp[e.v2].push_back(e);
			}
		}
		edge get_min_edge()
		{
			edge t;
			t.v1 = t.v2 = "?";
			t.w = 1e8;
			for (auto i : mp)
			{
				if (marked.find(i.first) != marked.end())
				{
					for (edge j : i.second)
					{
						if ((i.first == j.v1 && marked.find(j.v2) == marked.end()) || (i.first == j.v2 && marked.find(j.v1) == marked.end()))
						{
							if (t.w >= j.w)
							{
								t = j;
							}
						}
					}
				}
			}
			return t;
		}
		void generate()
		{
			marked.insert(mp.begin()->first);

			for (int i = 1; i < ver ; i++)
			{
				edge edg = get_min_edge();
				if (edg.w == 1e8)
				{
					cout << "Error generating the tree!!" << endl;
					break;
				}
				marked.insert(edg.v1);
				marked.insert(edg.v2);
				ans.push_back(edg);
			}
		}
		~prims()
		{
			int cost = 0;
			for (edge e : ans)
			{
				cost += e.w;
				cout << e.v1 << " " << e.v2 << " " << e.w << endl;
			}
			cout << "Cost :" << cost << endl;
		}
};

int main()
{
	graph g1;
	g1.generate();
	// prims p1;
	// p1.generate();
	return 0;
}
