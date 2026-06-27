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
     int i=0;
     TreeNode* solve(unordered_map<int,int>&mpp,vector<int>& preorder,int l,int r){
      
        if(l>r) return NULL;
        TreeNode* node=new TreeNode(preorder[i++]);
        
            int mid=mpp[node->val];
            node->left=solve(mpp,preorder,l,mid-1);
            node->right=solve(mpp,preorder,mid+1,r);
            return node;
            
        
     }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        int l=0;
        int r=preorder.size()-1;
        int n=preorder.size();
        for(int i=0;i<n;i++){
            mpp[inorder[i]]=i;
        }
        
        return  solve(mpp,preorder,l,r);
        
       


        
        
    }
};
