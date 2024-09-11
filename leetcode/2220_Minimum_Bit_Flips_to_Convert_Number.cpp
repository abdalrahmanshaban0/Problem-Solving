/*
Problem Name : 2220. Minimum Bit Flips to Convert Number
Author: Abdalrahman Shaban
Date: 11/09/2024 17:47:46
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minBitFlips(int st, int g) {
    int mx = max(st, g);
    int ans = 0;
    for (long long i = 0; (1LL << i) <= mx; i++) {
      bool a = ((1LL << i) & st);
      bool b = ((1LL << i) & g);
      if (a != b) {
        ans++;
      }
    }
    return ans;
  }
};

int main() { return 0; }
