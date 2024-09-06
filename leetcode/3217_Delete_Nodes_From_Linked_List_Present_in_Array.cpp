/*
Problem Name : 3217. Delete Nodes From Linked List Present in Array
Author: Abdalrahman Shaban
Date: 06/09/2024 11:33:12
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

class Solution {
  ListNode *modifylist(bool *mp, ListNode *head) {
    ListNode *dummy = new ListNode(0, head);
    ListNode *ret = dummy;
    while (dummy != nullptr && dummy->next != nullptr) {
      if (mp[dummy->next->val]) {
        dummy->next = dummy->next->next;
      } else
        dummy = dummy->next;
    }
    return ret->next;
  }

public:
  ListNode *modifiedList(vector<int> &nums, ListNode *head) {
    const int N = 1e5 + 1;
    bool mp[N];
    memset(mp, 0, sizeof(mp));
    for (auto &i : nums) {
      mp[i] = 1;
    }
    return modifylist(mp, head);
  }
};


int main() {
  return 0;
}
