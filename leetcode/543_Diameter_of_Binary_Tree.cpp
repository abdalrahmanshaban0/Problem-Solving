/*
Problem Name : 543. Diameter of Binary Tree 
Author: Abdalrahman Shaban
Date: 27/02/2024 12:50:23
*/
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
    public:
        int mxdia(TreeNode* nd, int& ret){
            if(nd == nullptr) return 0;
            int lft = mxdia(nd->left, ret);
            int rt = mxdia(nd->right, ret);

            ret = max(ret, lft+rt);
            return max(lft, rt)+1;
        }
        int diameterOfBinaryTree(TreeNode* root) {
            int ret = 0;
            mxdia(root, ret);
            return ret;
        }
};
