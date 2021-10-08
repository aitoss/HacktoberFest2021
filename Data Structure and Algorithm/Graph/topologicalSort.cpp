#include<bits/stdc++.h>
using namespace std;
int ispart(vector<vector<int>>&a,int i,int n)
{
	for(int k=0;k<n;k++)
	{
		if(a[i][k]==1)
			return true;
	}
	return false;
}
vector<int> topological_sort(vector<vector<int>>&a,int n)
{
	vector<int>res;
	vector<int>pred(n);
	queue<int>zeros;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j][i]==1)
			{
				pred[i]++;
			}
		}
		if(pred[i]==0 && ispart(a,i,n))
			zeros.push(i);
	}
	while(!zeros.empty())
	{
		int node=zeros.front();
		zeros.pop();
		res.push_back(node);
		for(int i=0;i<n;i++)
		{
			if(a[node][i]==1)
			{
				pred[i]--;
				if(pred[i]==0)
				{
					zeros.push(i);
				}
			}
		}
	}
	return res;
}
int main()
{
	int n,e;cin>>n>>e;
	vector<vector<int>>a(n,vector<int>(n));
	for(int i=0;i<e;i++)
	{
		int val,val2;
		cin>>val2>>val;
		a[val2][val]=1;
	}
	vector<int>ans=topological_sort(a,n);
	for(int i:ans)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}