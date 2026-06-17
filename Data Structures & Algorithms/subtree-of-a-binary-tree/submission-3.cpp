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
  bool isidentical(TreeNode* root, TreeNode* subRoot){
    if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        if(root->val!=subRoot->val) return false;
          bool lh=isidentical(root->left,subRoot->left);
            bool rh=isidentical(root->right,subRoot->right);
            return lh && rh;

  }
    bool solve(TreeNode* root, TreeNode* subRoot){
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        if(isidentical(root,subRoot)) return true;
        return solve(root->left,subRoot)||solve(root->right,subRoot);
        
        


    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL && subRoot==NULL) return true;
        if(root==NULL || subRoot==NULL) return false;
        
      return solve(root,subRoot);
        
    }
};
