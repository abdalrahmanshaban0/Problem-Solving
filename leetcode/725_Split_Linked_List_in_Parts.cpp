/*
Problem Name : 725. Split Linked List in Parts
Author: Abdalrahman Shaban
Date: 08/09/2024 20:44:10
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
  int ListSize(ListNode *head) {
    int sz = 0;
    while (head) {
      head = head->next;
      sz++;
    }
    return sz;
  }

public:
  vector<ListNode *> splitListToParts(ListNode *head, int k) {
    int n = ListSize(head);
    vector<ListNode *> ret(k, nullptr);

    ListNode *ptr = head;
    int dv = (n > k ? n / k : 1);
    int cnt = (n > k ? n % k : 0);
    for (int i = 0; i < k && ptr; i++, cnt--) {
      ListNode *p = ptr, *temp = p;
      for (int j = 0; p && (j + 1 < dv + (cnt > 0 ? 1 : 0)); j++) {
        p = p->next;
      }
      ptr = p->next;
      p->next = nullptr;
      ret[i] = temp;
    }
    return ret;
  }
};

int main() { return 0; }
