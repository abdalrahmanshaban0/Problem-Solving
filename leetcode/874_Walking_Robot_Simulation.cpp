/*
Problem Name : 874. Walking Robot Simulation
Author: Abdalrahman Shaban
Date: 04/09/2024 17:28:35
*/

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

void file();
void Fast();

class Solution {
  enum direction { N, E, S, W };

public:
  int robotSim(vector<int> &cms, vector<vector<int>> &obs) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    map<pair<int, int>, int> mp;
    for (auto &it : obs) {
      mp[{it[0], it[1]}]++;
    }
    pair<int, int> pos(0, 0);
    int dir = N;
    int mx = 0;
    for (auto &it : cms) {
      if (it < 0) {
        if (it == -1)
          it = 1;
        else
          it = -1;
        dir += it;
        if (dir < 0)
          dir += 4;
        else
          dir %= 4;
        continue;
      }
      pair<int, int> temp(pos);
      switch (dir) {
      case N:
        for (int i = temp.second + 1; i <= temp.second + it; i++) {
          if (mp.count({pos.first, i}))
            break;
          pos.second = i;
        }
        break;
      case S:
        for (int i = temp.second - 1; i >= temp.second - it; i--) {
          if (mp.count({pos.first, i}))
            break;
          pos.second = i;
        }
        break;
      case E:
        for (int i = temp.first + 1; i <= temp.first + it; i++) {
          if (mp.count({i, pos.second}))
            break;
          pos.first = i;
        }
        break;
      case W:
        for (int i = temp.first - 1; i >= temp.first - it; i--) {
          if (mp.count({i, pos.second}))
            break;
          pos.first = i;
        }
        break;
      }
      mx = max(mx, (pos.first * pos.first + pos.second * pos.second));
    }
    return mx;
  }
};
void solve() {}

int main() {
  Fast();
  // file();
  solve();

  return 0;
}

void file() {
#ifndef ONLINE_JUDGE
  freopen("input.txt", "r", stdin);
#endif
}
void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
