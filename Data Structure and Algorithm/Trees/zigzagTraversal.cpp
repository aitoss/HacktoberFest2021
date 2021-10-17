/*Given the binary tree, we have to find the zigzag level order traversal of its nodes' values. 
(i.e., from left to right, then right to left for the next level and alternate between).
Hence, the name zigzag :)*/

/* I have used recursive approach as lsited under:-
It is quite similar to the level order traversal. 
Here we simply include an extra parameter/flag to keep a track of printing each level in left-right or right-left way.*/

#include<bits/stdc++.h>
using namespace std;

struct node                 //for creating tree , node is required
{
	struct node* lchild;
	int data;
	struct node* rchild;

	node(int val)           //constructor
	{
		lchild=rchild=NULL;
		data=val;
	}
};

void zigzaglevelorder(node* root)      //function for evaluating the traversal
{
	vector<vector<int>> ans;
	queue<node*>q;
	q.push(root);
	bool flag= true;   //left to right
	while(!q.empty())
	{
		int size=q.size();
		vector<int> level(size);
		for(int i=0;i<size;i++)
		{
		    node* nd= q.front();
		    q.pop();
		    int index= (flag) ? i : size-1-i;
		    if(nd->lchild)
		    	q.push(nd->lchild);
		    if(nd->rchild)
		    	q.push(nd->rchild);
		    level[index]=nd->data;
		}
		flag = !flag;
		ans.push_back(level);
	}
	for(int i=0;i<ans.size();i++)
	{
		for(int j=0;j<ans[i].size();j++)
			cout<<ans[i][j]<<"\t";
		cout<<endl;
	}
}

int main()
{
	struct node* root=new node(1);       //creating tree
	root->lchild=new node(2);
	root->rchild=new node(3);
	root->lchild->lchild=new node(4);
	root->lchild->rchild=new node(5);
	root->rchild->rchild=new node(7);
	root->lchild->rchild->lchild=new node(6);
	zigzaglevelorder(root);
	return 0;
}

//Thank You !
