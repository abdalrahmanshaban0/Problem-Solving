/*
Problem Name : 1590. Make Sum Divisible by P
Author: Abdalrahman Shaban
Date: 03/10/2024 05:40:21
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int minSubarray(vector<int> &nums, int p) {
    long long sm = accumulate(nums.begin(), nums.end(), 0LL);
    int mo = sm % p;
    if (!mo)
      return 0;

    int n = nums.size();

    sm = 0;
    map<int, int> mp;
    mp[0] = -1;
    int ans = n;
    for (int i = 0; i < n; i++) {
      sm += nums[i];
      sm %= p;

      int val = (sm - mo + p) % p;

      if (mp.count(val)) {
        ans = min(ans, i - mp[val]);
      }

      mp[sm] = i;
    }
    return ans == n ? -1 : ans;
  }
};

int main() { return 0; }
