/*
Problem Name : 539. Minimum Time Difference
Author: Abdalrahman Shaban
Date: 16/09/2024 13:27:15
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int findMinDifference(vector<string> &tp) {
    int n = tp.size();
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      v[i] = stoi(tp[i].substr(0, 2)) * 60 + stoi(tp[i].substr(3, 2));
    }
    sort(v.begin(), v.end());
    int ans = 24 * 60 - v[n - 1] + v[0];
    for (int i = 0; i + 1 < n; i++) {
      ans = min(ans, v[i + 1] - v[i]);
    }
    return ans;
  }
};

int main() { return 0; }
