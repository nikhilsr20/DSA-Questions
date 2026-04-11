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
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& d) {

        

        unordered_map<int,TreeNode*> a;
        unordered_set<int> set;
        for(auto x : d){
            TreeNode* p;
            if(a.count(x[0])){
               p=a[x[0]];
            }
            else{
                p=new TreeNode(x[0]);
                a[x[0]]=p;
            }


            TreeNode* q;
            if(a.count(x[1])){
               q=a[x[1]];
                
            }
            else{
                q=new TreeNode(x[1]);
                a[x[1]]=q;
            }
            
            if(x[2]==1){
            p->left=q;
            }
            else{
                p->right=q;
            }
            set.insert(x[1]);
        } 

        for(auto x : a){
            if (!set.count(x.first)){
                  return x.second;
            }
        }
        return 0;
    }
};