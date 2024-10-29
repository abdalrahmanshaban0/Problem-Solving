/*
Problem Name : 2684. Maximum Number of Moves in a Grid
Author: Abdalrahman Shaban
Date: 29/10/2024 20:05:57
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
  int n, m;
  int dx[3] = {-1, 0, 1};
  int dp[1000][1000];
  bool valid(int i, int j) { return (i < n && j < m && i >= 0 && j >= 0); }
  int rec(int i, int j, vector<vector<int>> &g) {
    int &ans = dp[i][j];
    if (~ans)
      return ans;
    ans = 0;
    for (int k = 0; k < 3; k++) {
      int nx = i + dx[k];
      if (valid(nx, j + 1) && g[nx][j + 1] > g[i][j]) {
        ans = max(ans, 1 + rec(nx, j + 1, g));
      }
    }
    return ans;
  }

public:
  int maxMoves(vector<vector<int>> &grid) {
    n = grid.size(), m = grid[0].size();
    memset(dp, -1, sizeof(dp));
    int ret = 0;
    for (int i = 0; i < n; i++) {
      ret = max(ret, rec(i, 0, grid));
    }
    return ret;
  }
};

int main() { return 0; }
