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
    
    class node{
        public:
        bool good;
        int val;
        int maxi;
        int mini;
    };
    
    
public:
    node dfs(TreeNode* root, int &ans){
        if(root == NULL){
            node res;
            res.good = true;
            res.val = 0;
            res.maxi = INT_MIN;
            res.mini = INT_MAX;
            return res;
        }
        
        node left = dfs(root->left, ans);
        node right = dfs(root->right, ans);
        
        node res;
        res.good = (left.good && right.good);
        res.val = 0;
        
        if(root->left != NULL && root->left->val >= root->val)
            res.good = false;
        
        if(root->right != NULL && root->right->val <= root->val)
            res.good = false;
             
        if(res.good == true)
            res.val = left.val + right.val + root->val;
        
        if(left.maxi >= root->val || right.mini <= root->val)
            res.good = false;
        
        res.maxi = max({root->val, left.maxi, right.maxi});
        res.mini = min({root->val, left.mini, right.mini});
        
        if(res.good)ans = max(ans, res.val);
        
        // cout<<root->val<<" "<<res.mini<<" "<<res.maxi<<"\n";
        
        return res;          
        
    }
    
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};