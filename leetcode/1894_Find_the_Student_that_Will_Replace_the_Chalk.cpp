/*
Problem Name : 1894. Find the Student that Will Replace the Chalk
Author: Abdalrahman Shaban
Date: 04/09/2024 00:33:40
*/

#include <bits/stdc++.h>
#include <numeric>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()

void Fast();

class Solution {
  void Fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
  }

public:
  int chalkReplacer(vector<int> &chalk, int k) {
    Fast();
    ll sm = accumulate(chalk.begin(), chalk.end(), 0LL);
    k %= sm;
    for (int i = 0; i < chalk.size(); i++) {
      if (chalk[i] <= k) {
        k -= chalk[i];
      } else {
        return i;
      }
    }
    return -1;
  }
};

int main() {
  Fast();
  return 0;
}

void Fast() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
}
