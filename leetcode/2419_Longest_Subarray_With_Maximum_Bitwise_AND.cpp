/*
Problem Name : 2419. Longest Subarray With Maximum Bitwise AND
Author: Abdalrahman Shaban
Date: 14/09/2024 13:56:47
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestSubarray(vector<int> &v) {
    int n = v.size();
    int mx = *max_element(v.begin(), v.end());
    int cnt = 0, mxln = 0;
    for (int i = 0; i < n; i++) {
      if (v[i] == mx) {
        cnt++;
      } else {
        cnt = 0;
      }
      mxln = max(mxln, cnt);
    }
    return mxln;
  }
};

int main() { return 0; }
