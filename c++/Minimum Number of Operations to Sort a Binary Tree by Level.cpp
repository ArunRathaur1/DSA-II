#include<bits/stdc++.h>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
}; 
class Solution {
public:
    int minimumOperations(TreeNode* root) {
        queue<TreeNode*>q;
        vector<vector<int>>ar;
        vector<int>tem;
        q.push(root);
        while(!q.empty()){
            TreeNode* p=q.front();
            if(p==NULL){
                ar.push_back(tem);
                tem.clear();
            }
            else{
                tem.push_back(p->val);
                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
        }
        for(auto i: ar){
            for(auto j:i){
                cout<<j<<' ';
            }
            cout<<endl;
        }
    }
};
int main(){
    
}