#include<bits/stdc++.h>

using namespace std;

struct Node{
    Node *left;
    Node *right;
    int data;
    
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void BFtraversal(Node *root){
    queue <Node*> q;
    if(root!=NULL){
        q.push(root);
    }
    q.push(NULL);
    
    while(!q.empty()){
        Node *cur=q.front();
        q.pop();
        if(cur==NULL){
            cout << '\n';
            if(q.size()>0)q.push(NULL);
            continue;
        }
        cout << cur->data << ' ';
        
        if(cur->left!=NULL){
            q.push(cur->left);
        }
        if(cur->right!=NULL){
            q.push(cur->right);
        }
    }
}

int main(){
    
    Node *root = new Node(5);
    root->left = new Node(10);
    root->right = new Node(15);
    root->left->left = new Node(25);
    root->left->right = new Node(35);
    root->left->right->left = new Node(45);
    root->right->left = new Node(55);
    
    BFtraversal(root);
    return 0;
}