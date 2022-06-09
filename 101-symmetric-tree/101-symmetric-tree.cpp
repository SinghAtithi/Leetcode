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
    
    bool ans;
    
    void dfs(TreeNode *first, TreeNode *second){
        
        if(first == NULL && second != NULL){
            ans = false;
            return;
        }

        if(first != NULL && second == NULL){
            ans = false;
            return;
        }
        
        if(first == NULL && second == NULL)
            return;
        
        
        if(first->val != second->val ){
            ans = false;
            return;
        }
        
                        // cout<<first->val<<" "<<second->val<<"\n";

        dfs(first->left, second->right);
        dfs(first->right, second->left);
    }
    
    bool isSymmetric(TreeNode* root) {
        ans = true;
        dfs(root->left, root->right);
        return ans;
    }
};