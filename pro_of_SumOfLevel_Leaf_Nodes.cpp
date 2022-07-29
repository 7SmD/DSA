#include <bits/stdc++.h>
using namespace std;
 
struct Node {
    int data;
    Node* left;
    Node* right;
};
 

Node* newNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->left = temp->right = NULL;
    return temp;
}
 
void f(Node* r,map<int,int>& m,int lvl){
    if(!r){
        return;
    }
    if(!r->left && !r->right){
        m[lvl]+=r->data;
    }

    f(r->left,m,lvl+1);
    f(r->right,m,lvl+1);
}

int pro(Node* root){
    
    map<int,int> m;

    f(root,m,0);
    
    int p=1;

    for(auto i:m){
        p=p*(i.second);
    }

    return p;
}

int main()
{
    // Creating Binary Tree
    Node* root = newNode(2);
    root->left = newNode(7);
    root->right = newNode(5);
    root->left->right = newNode(6);
    root->left->left = newNode(8);
    root->left->right->left = newNode(1);
    root->left->right->right = newNode(11);
    root->right->right = newNode(9);
    root->right->right->left = newNode(4);
    root->right->right->right = newNode(10);
 
    cout << pro(root) << endl;
 
    return 0;
}