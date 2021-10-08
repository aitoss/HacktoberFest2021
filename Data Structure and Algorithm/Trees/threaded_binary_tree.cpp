#include<iostream>
#include<vector>
using namespace std;
class node
{
    public:
        bool left_thread,right_thread;
        node *left,*right;
        int data;
        node(int data=-1,int val=1)
        {
            this->data=data;
            left=right=nullptr;
            left_thread=right_thread=val;
        }
};

vector<node *>arr;
class tbt 
{
    node *dummy;
    public:
        tbt()
        {
            dummy=new node();
            dummy->left=dummy->right=dummy;
        }
        void insert(int data)
        {
            if(dummy->left_thread==1)
            {
                dummy->left=new node(data);
                dummy->left->left=dummy->left->right=dummy;
                dummy->left_thread=0;
            }
            else
            {
                node *root=dummy->left;
                while(true)
                {
                    if(root->data==data)
                    {
                        return;
                    }
                    else if(root->data>data)
                    {
                        if(root->left_thread)
                        {
                            node *child=new node(data);
                            child->left=root->left;
                            child->right=root;
                            root->left=child;
                            root->left_thread=0;
                            return;
                        }
                        root=root->left;
                    }
                    else
                    {
                        if(root->right_thread)
                        {
                            node *child=new node(data);
                            child->right=root->right;
                            child->left=root;
                            root->right=child;
                            root->right_thread=0;
                            return;
                        }
                        root=root->right;
                    }
                }
            }
        }
        void inorder()
        {
            cout<<"\ninorder : ";
            if(dummy->left_thread)
            {
                cout<<"Tree is empty!!"<<endl;
            }
            else
            {
                node *root=dummy->left;
                while(root!=dummy)
                {
                    while(root->left_thread!=1)
                    {
                        root=root->left;
                    }
                    cout<<root->data<<" ";
                    while(root->right_thread)
                    {
                        root=root->right;
                        if(root==dummy)
                            return;
                        cout<<root->data<<" ";
                    }
                    root=root->right;
                }
            }
        }
        void binary_tree_insert(int data)
        {
            if(dummy->left_thread)
            {
                dummy->left_thread=0;
                dummy->left=new node (data,0);
            }
            else
            {
                node *root=dummy->left;
                while(1==1)
                {
                    if(root->data==data)
                    {
                        return;
                    }
                    else if(root->data>data)
                    {
                        if(root->left)
                        {
                            root=root->left;
                        }
                        else
                        {
                            root->left=new node(data,0);
                            return;
                        }
                    }
                    else
                    {
                        if(root->right)
                        {
                            root=root->right;
                        }
                        else
                        {
                            root->right=new node(data,0);
                            return;
                        }
                    }
                }
            }
        }
        void inorder_fill_vector(node *root)
        {
            if(!root)
                return;
            inorder_fill_vector(root->left);
            arr.push_back(root);
            inorder_fill_vector(root->right);
        }
        void connect_threads(node *root)
        {
            if(!root)
                return;
            connect_threads(root->left);
            if(!root->left)
            {
                int i;
                for(i=0;i<(int)arr.size();i++)
                    if(arr[i]==root)break;
                if(i==0)
                {
                    root->left=dummy;
                    root->left_thread=true;
                }    
                else
                {
                    root->left=arr[i-1];
                    root->left_thread=true;
                }
            }
            connect_threads(root->right);
            if(!root->right)
            {
                int i;
                for(i=0;i<(int)arr.size();i++)
                    if(arr[i]==root)break;
                if(i==(int)arr.size()-1)
                {
                    root->right=dummy;
                    root->right_thread=true;
                }    
                else
                {
                    root->right=arr[i+1];
                    root->right_thread=true;
                }
            }
        }
        void binary_tree_to_tbt()
        {
            cout<<"converting binary tree to tbt!!"<<endl;
            arr.clear();
            if(dummy->left_thread)
            {
                cout<<"Tree is empty!!";
                return;
            }
            inorder_fill_vector(dummy->left);
            connect_threads(dummy->left);
        }
        void pre_order()
        {
            cout<<"\npreorder : ";
            if(dummy->left_thread)
            {
                cout<<"Tree is empty!!"<<endl;
            }
            else
            {
                node *root=dummy->left;
                while(root!=dummy)
                {
                    cout<<root->data<<" ";
                    while(root->left_thread!=1)
                    {
                        root=root->left;
                        cout<<root->data<<" ";
                    }
                    while(root->right_thread)
                    {
                        root=root->right;
                        if(root==dummy)
                            return;
                    }
                    root=root->right;
                }
            }
        }
};

int main()
{
    tbt t1;
    while(true)
    {
        int data;
        cin>>data;
        if(data==-9999)
        {
            break;
        }
        t1.binary_tree_insert(data);
    }
    t1.binary_tree_to_tbt();
    t1.inorder();
    cout<<endl;
    t1.pre_order();
    return 0;
}