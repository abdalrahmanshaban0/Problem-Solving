/*
Problem Name : 2326. Spiral Matrix IV
Author: Abdalrahman Shaban
Date: 09/09/2024 11:34:36
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
private:
  void nextIdx(int &i, int &j, int &a, int &b, char &dir, const int n,
               const int m) {
    if (i == n - a && j == b - 1 && dir == 'r') {
      dir = 'd';
      ++i;
      return;
    }
    if (i == a - 1 && j == b - 1 && dir == 'd') {
      dir = 'l';
      --j;
      return;
    }
    if (i == a - 1 && j == m - b && dir == 'l') {
      dir = 'u';
      --a;
      --i;
      return;
    }
    if (i == n - a && j == m - b && dir == 'u') {
      dir = 'r';
      --b;
      ++j;
      return;
    }
    switch (dir) {
    case 'r':
      ++j;
      break;
    case 'l':
      --j;
      break;
    case 'd':
      ++i;
      break;
    case 'u':
      --i;
      break;
    }
  }

public:
  vector<vector<int>> spiralMatrix(int mm, int nn, ListNode *head) {
    int n = mm, m = nn;
    int i = 0, j = 0;
    char dir = 'r';
    vector<vector<int>> ans(n, vector<int>(m, -1));
    ListNode *ptr = head;
    while (ptr) {
      ans[i][j] = ptr->val;
      nextIdx(i, j, n, m, dir, mm, nn);
      ptr = ptr->next;
    }
    return ans;
  }
};
void solve() {}

int main() {
  Fast();
  solve();

  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
