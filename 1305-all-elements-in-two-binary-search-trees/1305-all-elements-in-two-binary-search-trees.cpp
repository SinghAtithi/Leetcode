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
    
    void dfs(TreeNode* &root, vector<int>&v){
        if(root==NULL)return;
        dfs(root->left,v);
        v.push_back(root->val);
        dfs(root->right,v);
    }
    
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int>v;
        vector<int>vv;
        dfs(root1,v);
        dfs(root2,vv);
        vector<int>ans;
        int i=0,j=0;
        int n=v.size();
        int m=vv.size();
        while(i<n && j<m){
            if(v[i]<vv[j]){
                ans.push_back(v[i]);
                i++;
            }
            else{
                ans.push_back(vv[j]);
                j++;
            }
        }
        for(;i<n;i++){
            ans.push_back(v[i]);
        }
        for(;j<m;j++){
            ans.push_back(vv[j]);
        }
        return ans;
    }
};