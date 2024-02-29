/*
Problem Name : 1609. Even Odd Tree 
Author: Abdalrahman Shaban
Date: 29/02/2024 08:15:55
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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int dpth = 0;
        while(!q.empty()){
            int sz = q.size();
            vector<int> v;
            while(sz--){
                TreeNode* tmp = q.front(); q.pop();
                if(tmp->left != nullptr) q.push(tmp->left);
                if(tmp->right != nullptr) q.push(tmp->right);
                if(dpth&1 && ((tmp->val) & 1)) return 0;
                if(dpth % 2 == 0 && ((tmp->val) % 2 == 0)) return 0;
                v.emplace_back(tmp->val);
            }
            for(int i = 1; i < v.size(); i++){
                if(dpth&1){
                    if(v[i] >= v[i-1]) return 0;
                }
                else{
                    if(v[i] <= v[i-1]) return 0;
                }
            }
            dpth++;
        }
        return 1;
    }
};
