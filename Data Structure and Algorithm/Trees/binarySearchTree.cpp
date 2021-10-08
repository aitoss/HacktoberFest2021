#include <iostream>
#include <stack>
#include <queue>
using namespace std;
template <class T>
void swap_it(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}
class node
{
public:
    int data;
    node *left;
    node *right;
    node()
    {
        left = right = nullptr;
        data = -1;
    }
    node(int val)
    {
        left = right = nullptr;
        data = val;
    }
};
class bst
{
    node *root;

public:
    bst()
    {
        root = nullptr;
    }
    void insert(int val)
    {
        if (!root)
        {
            root = new node(val);
        }
        else
        {
            node *temp = root;
            while (1)
            {
                if (val < temp->data)
                {
                    if (!temp->left)
                    {
                        temp->left = new node(val);
                        break;
                    }
                    else
                        temp = temp->left;
                }
                else if (val > temp->data)
                {
                    if (!temp->right)
                    {
                        temp->right = new node(val);
                        break;
                    }
                    else
                        temp = temp->right;
                }
                else
                    break;
            }
        }
    }
    void display_inorder()
    {
        display_inorder(root);
        if (!root)
        {
            cout << "Empty bst" << endl;
            ;
        }
        cout << endl;
    }
    void display_inorder(node *root)
    {
        if (!root)
            return;
        display_inorder(root->left);
        cout << root->data << " ";
        display_inorder(root->right);
    }
    void insert_recursive(int val)
    {
        if (!root)
        {
            root = new node(val);
        }
        else
        {
            insert_recursive(root, val);
        }
    }
    void insert_recursive(node *root, int val)
    {
        if (!root)
            return;
        if (root->data == val)
            return;
        if (root->data < val)
        {
            if (!root->right)
            {
                root->right = new node(val);
                return;
            }
            else
            {
                insert_recursive(root->right, val);
                return;
            }
        }
        if (root->data > val)
        {
            if (!root->left)
            {
                root->left = new node(val);
                return;
            }
            else
            {
                insert_recursive(root->left, val);
                return;
            }
        }
    }
    int height()
    {
        return height(root);
    }
    int height(node *root)
    {
        if (!root)
            return 0;
        int lh = height(root->left);
        int rh = height(root->right);
        return max(lh, rh) + 1;
    }
    void iterative_inorder()
    {
        node *temp = root;
        stack<node *> st;
        while (1 == 1)
        {
            if (!temp)
            {
                if (st.empty())
                    break;
                temp = st.top();
                st.pop();
                cout << temp->data << " ";
                temp = temp->right;
            }
            else
            {
                st.push(temp);
                temp = temp->left;
            }
        }
        cout << endl;
    }
    void display_postorder()
    {
        display_postorder(root);
    }
    void display_postorder(node *root)
    {
        if (!root)
            return;
        display_postorder(root->left);
        display_postorder(root->right);
        cout << root->data << " ";
    }
    void display_preorder()
    {
        display_preorder(root);
    }
    void display_preorder(node *root)
    {
        if (!root)
            return;
        cout << root->data << " ";
        display_preorder(root->left);
        display_preorder(root->right);
    }
    void mirror()
    {
        mirror(root);
    }
    void mirror(node *root)
    {
        if (!root)
            return;
        swap_it(root->left, root->right);
        mirror(root->left);
        mirror(root->right);
    }
    void level_order()
    {
        queue<node *> a;
        a.push(root);
        node *tem;
        while (!a.empty())
        {
            tem = a.front();
            a.pop();
            if (tem)
            {
                cout << tem->data << " ";
                if (tem->left)
                {
                    a.push(tem->left);
                }
                if (tem->right)
                {
                    a.push(tem->right);
                }
            }
        }
    }
    void copy(bst &obj)
    {
        if (!root)
            return;
        else
        {
            obj.root = new node(root->data);
            copy(root, obj.root);
        }
    }
    void copy(node *root, node *root1)
    {
        if (root->left)
        {
            root1->left = new node(root->left->data);
            copy(root->left, root1->left);
        }
        if (root->right)
        {
            root1->right = new node(root->right->data);
            copy(root->right, root1->right);
        }
    }
    bool isEqual(bst obj)
    {
        if ((!root && obj.root) || (root && !obj.root))
        {
            cout << "Not equal bst" << endl;
            return false;
        }
        else
        {
            bool ans = isEqual(root, obj.root);
            if (ans)
            {
                cout << "Equal bst" << endl;
            }
            else
            {
                cout << "Not equal bst" << endl;
            }
            return ans;
        }
    }
    bool isEqual(node *root, node *root1)
    {
        if (!root || !root1)
            return root == root1;
        return isEqual(root->left, root1->left) && isEqual(root->right, root1->right);
    }
    void delete_(int val)
    {
        if (!root)
        {
            cout << "\n\nbst is empty";
        }
        else
        {
            bool ans = delete_(root, val);
            if (ans)
            {
                cout << "\n\nvalue deleted successfully" << endl;
            }
            else
            {
                cout << "\n\nvalue not found" << endl;
            }
        }
    }
    bool delete_(node *root, int val)
    {
        if (!root)
        {
            return false;
        }
        if (root->data == val)
        {
            delete_node(root);
            return true;
        }
        if (root->data < val)
        {
            return delete_(root->right, val);
        }
        else
        {
            return delete_(root->left, val);
        }
    }
    void delete_node(node *root)
    {
        if (root->data == this->root->data)
        {
            if (!root->left)
            {
                if (!root->right)
                {
                    node *t = root;
                    this->root = nullptr;
                    delete t;
                    return;
                }
                node *t = root;
                this->root = root->right;
                delete t;
                return;
            }
            if (!root->right)
            {
                node *t = root;
                this->root = t->left;
                delete t;
                return;
            }
            if (!root->right->left)
            {
                if (!root->right->right)
                {
                    node *t = root->right;
                    root->data = t->data;
                    root->right = nullptr;
                    delete t;
                    return;
                }
                node *t = root->right;
                root->data = t->data;
                root->right = t->right;
                delete t;
                return;
            }
            node *t, *t2;
            t = root->right;
            t2 = t->left;
            while (t2->left != nullptr)
            {
                t = t2;
                t2 = t2->left;
            }
            root->data = t2->data;
            t->left = t2->right;
            delete t2;
            return;
        }
        else
        {
            node *parent = find_parent(root->data);
            if (!root->left)
            {
                if (!root->right)
                {
                    if (parent->left == root)
                    {
                        parent->left = nullptr;
                        delete root;
                        return;
                    }
                    parent->right = nullptr;
                    delete root;
                    return;
                }
                if (parent->left == root)
                {
                    parent->left = root->right;
                    delete root;
                }
                else
                {
                    parent->right = root->right;
                    delete root;
                }
                return;
            }
            if (!root->right)
            {
                if (parent->left == root)
                {
                    parent->left = root->left;
                    delete root;
                }
                else
                {
                    parent->right = root->left;
                    delete root;
                }
                return;
            }
            if (!root->right->left || !root->right->right)
            {
                if (!root->right->left && !root->right->right)
                {
                    node *t = root->right;
                    root->data = t->data;
                    root->right = nullptr;
                    delete t;
                    return;
                }
                node *t = root->right;
                root->data = root->right->data;
                if (root->right->right)
                    root->right = root->right->right;
                else
                    root->right = root->right->left;
                delete t;
                return;
            }

            node *t1, *t2;
            t1 = root->right;
            t2 = t1->left;
            while (t2->left)
            {
                t1 = t2;
                t2 = t2->left;
            }
            t1->left = t2->right;
            root->data = t2->data;
            delete t2;
            return;
        }
    }
    node *find_parent(int val)
    {
        if (val == root->data)
            return root;
        return find_parent(root, val);
    }
    node *find_parent(node *root, int val)
    {
        if (!root)
        {
            return nullptr;
        }
        if (root->left)
        {
            if (root->left->data == val)
                return root;
        }
        if (root->right)
        {
            if (root->right->data == val)
                return root;
        }
        if (root->data < val)
        {
            return find_parent(root->right, val);
        }
        else
        {
            return find_parent(root->left, val);
        }
    }
   void generate_bst_using_inorder_preorder()
    {
        int sz;
        cout<<"Enter size of preorder : ";
        cin>>sz;
        int *pre=new int[sz];
        int *ino=new int[sz];
        cout<<"enter elements of inorder then preorder:\n";
        for(int i=0;i<sz;i++)
        {
            cin>>ino[i];
        }
        for(int i=0;i<sz;i++)
        {
            cin>>pre[i];
        }
        root=generate(pre,ino,0,sz-1);
        cout<<"root";
    }
    node* generate(int preorder[],int inorder[],int left,int right)
    {
        static int preind=0;
        if(left>right)
            return nullptr;
        node *t=new node(preorder[preind]);
        if(left==right)
            return t;
        int indx=left;
        preind++;
        for(int i=left;i<=right;i++)
        {
            if(inorder[i]==t->data)
            {
                indx=i;
                break;
            }
        }
        t->left=generate(preorder,inorder,left,indx-1);
        t->right=generate(preorder,inorder,indx+1,right);
        return t;
    }
    void iterative_postorder()
    {
        if(root==nullptr)
        {
            cout<<"bsr is empty!!"<<endl;
            return;
        }
        node *temp;
        stack<node *>fir;
        stack<node *>sec;
        fir.push(root);
        while(!fir.empty())
        {
            temp=fir.top();
            fir.pop();
            sec.push(temp);
            if(temp->left)
            {
                fir.push(temp->left);
            }
            if(temp->right)
            {
                fir.push(temp->right);
            }
        }
        while(!sec.empty())
        {
            temp=sec.top();
            cout<<temp->data<<" ";
            sec.pop();
        }
    }
    void iterative_preorder()
    {
        node *temp;
        stack<node *>st;
        st.push(root);
        while(!st.empty())
        {
            temp=st.top();
            st.pop();
            cout<<temp->data<<" ";
            if(temp->right)
            {
                st.push(temp->right);
            }
            if(temp->left)
            {
                st.push(temp->left);
            }
        }
    }
};
void print_choice()
{
    cout<<"\n\n\nMenu:-\n";
    cout<<"\n1.insert in bst:";
    cout<<"\n2.insert recursive in bst:";
    cout<<"\n3.height of bst:";
    cout<<"\n4.iterative inorder of bst:";
    cout<<"\n5.iterative postorder of bst:";
    cout<<"\n6.iterative preorder of bst:";
    cout<<"\n7.inorder of bst:";
    cout<<"\n8.preorder of bst:";
    cout<<"\n9.postorder of bst:";
    cout<<"\n10.copy of bst:";
    cout<<"\n11.compare 2 bst(is equal ?):";
    cout<<"\n12.delete value of bst:";
    cout<<"\n13.generate bst:";
    cout<<"\n14.mirror bst:";
    cout<<"\n0.exit!!!!";
    cout<<"\nEnter your choice :";
}
int main()
{
    bst obj;
    bst obj2;
    while(1)
    {
        //print_choice();
        int choice;
        cin>>choice;
        if(choice==0)
        {
            break;
        }
        else if(choice==1)
        {
            cout<<"\nEnter value to insert:";
            int val;cin>>val;
            obj.insert(val);
            cout<<endl;
        }
        else if(choice==2)
        {
            cout<<"\nEnter value to insert:";
            int val;cin>>val;
            obj.insert_recursive(val);
            cout<<endl;
        }
        else if(choice==3)
        {
            cout<<"\nheight of bst is : "<<obj.height();
        }
        else if(choice==4)
        {
            cout<<endl;
            obj.iterative_inorder();
        }
        else if(choice==5)
        {
            cout<<endl;
            obj.iterative_postorder();
        }
        else if(choice==6)
        {
            cout<<endl;
            obj.iterative_preorder();
            
        }
        else if(choice==7)
        {
            obj.display_inorder();
            cout<<endl;
        }
        else if(choice==8)
        {
            obj.display_preorder();
            cout<<endl;
        }
        else if(choice==9)
        {
            obj.display_postorder();
            cout<<endl;
        }
        else if(choice==10)
        {
            obj.copy(obj2);
            cout<<"\ncopied bst inorder : ";
            obj2.display_inorder();
            cout<<endl;
        }
        else if(choice==11)
        {
            obj.isEqual(obj2);
            cout<<endl;
        }
        else if(choice==12)
        {
            cout<<"\nEnter value to be deleted : ";
            int val;cin>>val;
            obj.delete_(val);
            cout<<endl;
        }
        else if(choice==13)
        {
            bst obj3;
            obj3.generate_bst_using_inorder_preorder();
            cout<<endl;
        }
        else if(choice==14)
        {
            obj.mirror();
            cout<<endl;
        }
    }
    return 0;
}
