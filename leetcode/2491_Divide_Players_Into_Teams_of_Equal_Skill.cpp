/*
Problem Name : 2491. Divide Players Into Teams of Equal Skill
Author: Abdalrahman Shaban
Date: 04/10/2024 11:20:35
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  long long dividePlayers(vector<int> &skill) {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    sort(skill.begin(), skill.end());
    int n = skill.size();
    long long bs = skill[0] + skill[n - 1];
    unordered_map<int, int> mp;
    for (int i = 1; i + 1 < n; i++) {
      mp[skill[i]]++;
    }
    long long ans = skill[0] * skill[n - 1];
    for (int i = 1; i + 1 < n; i++)
      if (mp[skill[i]]) {
        if (bs - skill[i] == skill[i]) {
          if (mp[bs - skill[i]] >= 2) {
            mp[bs - skill[i]]--;
            mp[skill[i]]--;
            ans += skill[i] * (bs - skill[i]);
          } else
            return -1;
        } else if (mp[bs - skill[i]]) {
          mp[bs - skill[i]]--;
          mp[skill[i]]--;
          ans += skill[i] * (bs - skill[i]);
        } else
          return -1;
      }
    return ans;
  }
};

int main() { return 0; }
