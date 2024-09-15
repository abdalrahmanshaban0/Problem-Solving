/*
Problem Name : 1371. Find the Longest Substring Containing Vowels in Even Counts
Author: Abdalrahman Shaban
Date: 16/09/2024 00:27:15
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
  int vfrq[26];

public:
  Solution() {
    memset(vfrq, 0, sizeof(vfrq));
    vfrq[0] = 1;
    vfrq['e' - 'a'] = 2;
    vfrq['i' - 'a'] = 4;
    vfrq['o' - 'a'] = 8;
    vfrq['u' - 'a'] = 16;
  }
  int findTheLongestSubstring(string s) {
    int n = s.size();
    int mask = 0;
    const int N = 5e5 + 1;
    int mp[N];
    memset(mp, -1, sizeof(mp));
    mp[0] = -1;
    int ans = 0;
    for (int i = 0; i < n; i++) {
      mask ^= vfrq[s[i] - 'a'];
      if (mp[mask] == -1 && mask) {
        mp[mask] = i;
      } else {
        ans = max(ans, i - mp[mask]);
      }
    }
    return ans;
  }
};

int main() { return 0; }
