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
int path(TreeNode* root,int &ans){
    if(root==nullptr) return 0;
    
    int x=path(root->left,ans);
    int y=path(root->right,ans);
    x=max(0,x);
    y=max(0,y);
    ans=max({ans,x+y+root->val});
    return root->val + max(x, y);
    
 }
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans=INT_MIN;
       int p=path(root,ans); 
       return ans;
    }
};