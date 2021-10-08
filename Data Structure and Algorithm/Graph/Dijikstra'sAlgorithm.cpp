#include <bits/stdc++.h>
using namespace std;
#define inf 1e5;
vector<int>dijkstra(int source,int v,vector<vector<bool>>&ad,vector<vector<int>>&wt,vector<int>&parent)
{
	vector<int>dist(v);
	vector<int>vis(v);
	for(int i=0;i<v;i++)
	{
		if(ad[source][i])
		{
			dist[i]=wt[source][i];
		}
		else
		{
			dist[i]=inf;
		}
	}
	dist[source]=0;
	vis[source]=1;
	for(int i=0;i<v-1;i++)
	{
		int cur=-1;
		int val=inf;
		for(int j=0;j<v;j++)
		{
			if(vis[j])continue;
			if(val>dist[j])
				cur=j,val=dist[j];
		}
		vis[cur]=1;
		for(int j=0;j<v;j++)
		{
			if(vis[j]==false && ad[cur][j] &&dist[j]>dist[cur]+wt[cur][j])
			{
				parent[j]=cur;
				dist[j]=dist[cur]+wt[cur][j];
			}
		}
	}
	return dist;
}

int main()
{
	int n,e;cin>>n>>e;
	vector<vector<bool>>ad(n,vector<bool>(n));
	vector<vector<int>>wt(n,vector<int>(n));
	vector<int>parent(n);
	for(int i=0;i<e;i++)
	{
		int node,dest,wts;
		cin>>node>>dest>>wts;
		ad[node][dest]=1;
		wt[node][dest]=wts;
	}
	int ver;cin>>ver;
	vector<int>dist=dijkstra(ver,n,ad,wt,parent);
	for(int i=0;i<(int)(dist).size();i++)
	{
		cout<<i<<" "<<dist[i]<<endl;
		int val=i;
		while(val!=ver)
		{
			cout<<val<<" ";
			val=parent[val];
		}
		cout<<val<<endl;
	}
	return 0;
}