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
    
    int dfs(TreeNode* &root, int &ans){
        
        if(root == NULL)
            return 0;
        
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        
        int x = 0;
        
        if(root->left != NULL && root->left->val == root->val)
            x = max(x, left + 1);
        
        if(root->right != NULL && root->right->val == root->val)
            x = max(x, right + 1);
        
        ans = max(ans, x);
        
        if(root->right != NULL && root->right->val == root->val)
            if(root->left != NULL && root->left->val == root->val)
                ans = max(ans, left + right + 2);

        return x;
        
    }
    
    int longestUnivaluePath(TreeNode* root) {
        ios_base :: sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};