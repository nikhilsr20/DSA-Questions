/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 void make(TreeNode* root,int &ans,int count,int n){
    if(root==nullptr){
        return;
    }
    ans=max(count,ans);
    
    if(n==-1){
        make(root->left,ans,count+1,0);
         make(root->right,ans,count+1,1);
    }
    else if(n==0){
         make(root->right,ans,count+1,1);
          make(root->left,ans,1,0);
    }
    else if(n==1){
         make(root->left,ans,count+1,0);
          make(root->right,ans,1,1);
    }
    

 }
class Solution {
public:
    int longestZigZag(TreeNode* root) {
       int ans=0;
       int count=0;
        make(root,ans,count,-1);
        return ans;
    }
};