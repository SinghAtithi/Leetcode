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
    map<int,vector<pair<int,int>>>ans;

    void dfs(TreeNode* root, int k, int lev){
        if(root==NULL)return;
        ans[k].push_back({lev,root->val});
        dfs(root->left,k-1,lev+1);
        dfs(root->right,k+1,lev+1);
    }

    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        ans.clear();
        vector<vector<int>>v;
        dfs(root,0,0);
        
        for(auto [a,b]:ans){
            sort(b.begin(),b.end());
            vector<int>temp;
            for(auto [x,y]:b){
                temp.push_back(y);
            }
            v.push_back(temp);
        }
        return v;
    }
};