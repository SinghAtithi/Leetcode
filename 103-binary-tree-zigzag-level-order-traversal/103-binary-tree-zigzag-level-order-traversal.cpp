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
    
    void dfs(TreeNode* root, int depth, vector<vector<int>> &ans){
        if(root == NULL)
            return;
        if(ans.size() == depth){
            ans.push_back({root->val});
        }
        else{
            ans[depth].push_back(root->val);
        }
        dfs(root->left, depth+1, ans);
        dfs(root->right, depth+1, ans);
    }
    
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans;
        dfs(root, 0, ans);
        for(int i=1;i<ans.size();i+=2){
            reverse(ans[i].begin(),ans[i].end());
        }        
        return ans;
    }
};