/*
Problem Name : 2807. Insert Greatest Common Divisors in Linked List
Author: Abdalrahman Shaban
Date: 10/09/2024 10:57:35
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
  int gcd(int a, int b) { return a ? gcd(b % a, a) : b; }

public:
  ListNode *insertGreatestCommonDivisors(ListNode *head) {
    ListNode *ptr = head, *ret = ptr;
    while (ptr && ptr->next) {
      ListNode *nnode = new ListNode(gcd(ptr->val, ptr->next->val), ptr->next);
      ListNode *temp = ptr->next;
      ptr->next = nnode;
      ptr = temp;
    }
    return ret;
  }
};

int main() { return 0; }
