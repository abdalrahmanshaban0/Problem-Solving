/*
Problem Name : 2707. Extra Characters in a String
Author: Abdalrahman Shaban
Date: 23/09/2024 21:33:31
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int dp[51];
  int rec(string &s, vector<string> &dict, int idx) {
    if (idx == s.size()) {
      return 0;
    }
    int &ans = dp[idx];
    if (~ans) {
      return ans;
    }
    ans = s.size();
    for (auto &i : dict) {
      int it = 0, j = idx;
      while (it < i.size() && i[it] == s[j]) {
        it++;
        j++;
      }
      if (it == i.size()) {
        ans = min(ans, rec(s, dict, idx + i.size()));
      }
    }
    ans = min(ans, 1 + rec(s, dict, idx + 1));
    return ans;
  }
  int minExtraChar(string s, vector<string> &dict) {
    memset(dp, -1, sizeof(dp));
    return rec(s, dict, 0);
  }
};

int main() { return 0; }
