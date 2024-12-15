#include <iostream>
#include <queue>
#include<bits/stdc++.h>
using namespace std;

// TreeNode structure
struct TreeNode {
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val) {
        data = val;
        left = right = nullptr;
    }
};

// Function to print level order traversal
string levelOrderTraversal(TreeNode* root) {
   string ans;
   if(root==NULL){
    return " ";
   }
   queue<TreeNode*>q;
   q.push(root);
   while (!q.empty())
   {
        TreeNode* p=q.front();
        q.pop();
        if(p==NULL){
            ans=ans+"# ";
            continue;
        }
        else{
            string s=to_string(p->data)+" ";
            ans=ans+s;
                q.push(p->left);
                q.push(p->right);
        }
   }
   return ans;
   
}
TreeNode* Deserialize(string s){
    if(s=="#")return NULL;
    queue<TreeNode*>q;
    stringstream ss(s);
    string g;
    getline(ss,g,' ');
    TreeNode* root=new TreeNode(stoi(g));
    q.push(root);
    while(!q.empty()){
        TreeNode* p=q.front();
        q.pop();
        getline(ss,g,' ');
        if(g=="#"){
            p->left=NULL;
        }
        else{
            TreeNode* tem=new TreeNode(stoi(g));
            p->left=tem;
            q.push(tem);
        }
        getline(ss,g,' ');
         if(g=="#"){
            p->right=NULL;
        }
        else{
            TreeNode* tem=new TreeNode(stoi(g));
            p->right=tem;
            q.push(tem);
        }
    }
    return root;
}
void printtree(TreeNode* root){
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* tem=q.front();
        q.pop();
            cout<<tem->data<<" ";
        if(tem->left)
        q.push(tem->left);
        if(tem->right)
        q.push(tem->right);
    }
}
int main() {
    // Create the root TreeNode
    TreeNode* root = new TreeNode(1);

    // Manually create the tree
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    /*
        The tree looks like this:
                 1
               /   \
              2     3
             / \   / \
            4   5 6   7
    */

    // Perform level order traversal
    cout << "Level Order Traversal: ";
    string ans=levelOrderTraversal(root);
    cout<<ans<<endl;
    TreeNode* root1=Deserialize(ans);
    printtree(root1);
    cout << endl;

    return 0;
}
