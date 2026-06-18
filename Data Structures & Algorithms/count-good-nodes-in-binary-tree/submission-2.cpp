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
    int cnt=0;
    void solve(TreeNode* root,int parent){
        if(root==NULL) return;
        if(root->val>=parent){
            cnt++;
            parent=root->val;
        }
        solve(root->left,parent);
        solve(root->right,parent);
    }

    int goodNodes(TreeNode* root) {
        if(root==NULL) return -1;
        int parent=root->val;
        solve(root,parent);
        return cnt;
    

        
    }
};
