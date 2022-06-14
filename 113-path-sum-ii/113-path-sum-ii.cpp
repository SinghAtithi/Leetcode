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
    
    unordered_map<int,int> val;
    int par;
    
    void dfs(TreeNode* root, int sum , int &target, vector<int>& temp, vector<vector<int>>& ans){
        
        if(root == NULL)
            return;
        if(root -> left)
            val[root->left->val] = root->val;
        if(root->right)
            val[root->right->val] = root->val;
        
        // cout<<root->val<<" "<<sum<<"\n";
        
        sum += root->val;
        temp.push_back(root->val);
        if(sum == target && root->left == NULL && root->right == NULL){
            ans.push_back(temp);
        }
        dfs(root->left,sum,target,temp,ans);
        dfs(root->right,sum,target,temp,ans);
        temp.pop_back();
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        
        vector<vector<int>>ans;
        
        if(root == NULL)
            return ans;
        vector<int>temp;
        par = root->val;
        val.clear();
        
        dfs(root, 0, targetSum,temp, ans);
        return ans;
    }
};