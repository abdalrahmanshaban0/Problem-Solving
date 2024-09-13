/*
Problem Name : 1310. XOR Queries of a Subarray
Author: Abdalrahman Shaban
Date: 13/09/2024 17:11:57
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  vector<int> xorQueries(vector<int> &arr, vector<vector<int>> &queries) {
    int n = arr.size();
    vector<int> prf(n);
    prf[0] = arr[0];
    for (int i = 1; i < n; i++) {
      prf[i] = (prf[i - 1] ^ arr[i]);
    }
    int m = queries.size();
    vector<int> ans(m);
    for (int i = 0; i < m; i++) {
      int l = queries[i][0], r = queries[i][1];
      if (l) {
        ans[i] = (prf[r] ^ prf[l - 1]);
      } else {
        ans[i] = prf[r];
      }
    }
    return ans;
  }
};

int main() { return 0; }
