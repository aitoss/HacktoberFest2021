#include <iostream>
#include <queue>
using namespace std;
class node
{
    public:
        int val;
        node *left;
        node *right;
        node(int val=-1)
        {
            this->val=val;
            left=right=nullptr;
        }
};
class bt
{
    node *root;
    public:
        bt()
        {
            root=nullptr;
            insert();
        }
        void insert()
        {
            cout<<"Enter value of root : ";
            int val;
            cin>>val;
            root=new node(val);
            queue<node*>q;
            q.push(root);
            while(!q.empty())
            {
                node *temp=q.front();
                q.pop();
                cout<<"Does "<<temp<<" has left child ?(y/n)";
                char as;cin>>as;
                if(as=='y' || as=='Y')
                {
                    cout<<"Enter value of left child of "<<temp->data<<" : ";
                    cin>>val;
                    temp->left=new node(val);
                    q.push(temp->left);
                }
                cout<<"Does "<<temp<<" has right child ?(y/n)";
                cin>>as;
                if(as=='y' || as=='Y')
                {
                    cout<<"Enter value of right child of "<<temp->data<<" : ";
                    cin>>val;
                    temp->right=new node(val);
                    q.push(temp->right);
                }
            }
        }
        void inorder()
        {
            if(!root)
            {
                cout<<"Empty binary tree "<<endl;
                return;
            }
            inorder(root);
        }
        void inorder(node *root)
        {
            if(!root)
                return;
            inorder(root->left);
            cout<<root->val<<" ";
            inorder(root->right);
        }
        void preorder()
        {
            if(!root)
            {
                cout<<"Empty binary tree "<<endl;
                return;
            }
            preorder(root);
        }
        void preorder(node *root)
        {
            if(!root)
                return;
            cout<<root->val<<" ";
            preorder(root->left);
            preorder(root->right);
        }
        void postorder()
        {
            if(!root)
            {
                cout<<"Empty binary tree "<<endl;
                return;
            }
            postorder(root);
        }
        void postorder(node *root)
        {
            if(!root)
                return;
            postorder(root->left);
            postorder(root->right);
            cout<<root->val<<" ";
        }
        void level_order()
        {
            if(!root)
            {
                cout<<"Empty binary tree "<<endl;
                return;
            }
            queue<node*>a;
            a.push(root);
            node *tem;
            while(!a.empty())
            {
                tem=a.front();
                a.pop();
                if(tem)
                {
                    cout<<tem->data<<" ";
                    if(tem->left)
                    {
                        a.push(tem->left);
                    }
                    if(tem->right)
                    {
                        a.push(tem->right);
                    }
                }
            }
        }
        bool search(int val)
        {
            if(!root)
            {
                cout<<"Empty binary tree"<<endl;
                return false;
            }
            bool ans=search(root,val);
            if(ans)
            {
                cout<<val<<" found !!";
                return  ans;
            }
            cout<<val<<" not found !!";
            return ans;
        }
        bool search(node *root,int val)
        {
            if(!root)
                return false;
            if(root->data==val)
                return true;
            return search(root->left,val)|seach(root->right,val);
        }
        int height()
        {
            return height(root);
        }
        int height(node *root)
        {
            if(!root)
                return 0;
            int lh=height(root->left);
            int rh=height(root->right);
            return max(lh,rh)+1;
        }
};
int main()
{

    return 0;
}
