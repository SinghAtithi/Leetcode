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
    
    string f;
    
    TreeNode* LCA(TreeNode* root, int &p, int &q){
        if(root == NULL || root->val == p || root->val == q){
            return root;
        }
        
        TreeNode* left = LCA(root->left, p, q);
        TreeNode* right = LCA(root->right, p ,q);
        
        if(left == NULL)
            return right;
        if(right == NULL)
            return left;
        
        return root;
    }
    
    int depth(TreeNode* root, int &target){
        if(root == NULL)
            return 1e6;
        
        if(root->val == target)
            return 0;
        
        int left = depth(root->left, target) + 1;
        int right = depth(root->right, target) + 1;
        
        return min(left, right);
    }
    
    void path(TreeNode* root, int &target, string &s, bool &found){
        if(root == NULL || found)
            return;
        if(root->val == target){
            f = s;
            found = true;
            return;
        }
        s+='L';
        path(root->left, target, s, found);
        s.pop_back();
        s+='R';
        path(root->right, target, s, found);
        s.pop_back();
    }
    
    string getDirections(TreeNode* root, int p, int q) {
        
        TreeNode* lca = LCA(root, p , q);
        string ans = "";
        int x = depth(lca, p);
        f="";
        string temp = "";
        bool found = false;
        
        path(lca, q, temp, found);
        
        for(int i = 0; i < x; i++)
            ans+='U';
        ans+=f;
        return ans;
        
    }
};