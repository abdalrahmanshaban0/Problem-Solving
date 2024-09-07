/*
Problem Name : 1367. Linked List in Binary Tree
Author: Abdalrahman Shaban
Date: 07/09/2024 11:04:49
*/

#include <bits/stdc++.h>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  bool dfs(ListNode *lptr, TreeNode *tptr) {
    if (lptr == nullptr)
      return true;
    if (tptr == nullptr)
      return false;
    bool ans = false;
    if (tptr->val == lptr->val) {
      ans = dfs(lptr->next, tptr->left) || dfs(lptr->next, tptr->right);
    }
    return ans;
  }
  bool checkpath(TreeNode *node, ListNode *Head) {
    if (node == nullptr)
      return false;
    if (dfs(Head, node))
      return true;
    return checkpath(node->right, Head) || checkpath(node->left, Head);
  }

  bool isSubPath(ListNode *head, TreeNode *root) {
    return checkpath(root, head);
  }
};

int main() { return 0; }
