/*
Problem Name : 632. Smallest Range Covering Elements from K Lists 
Author: Abdalrahman Shaban
Date: 13/10/2024 04:51:20
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
      ios::sync_with_stdio(false);
      cin.tie(nullptr);
      int k = nums.size();
      vector<pair<int,int>> v;
      for(int i = 0; i < k; i++){      
        for(auto& j : nums[i]){
          v.push_back({j,i});
        }
      }
      sort(v.begin(), v.end());

      unordered_map<int, int> mp; 
      vector<int> rng;
      int mn = INT_MAX;

      int l = 0, r = 0;
      while(l < v.size() && l <= r){
        while(r < v.size() && mp.size() < k){
          mp[v[r].second]++;
          r++;
        }
        if(mp.size() == k && v[r-1].first-v[l].first <  mn){
          mn = v[r-1].first-v[l].first;
          rng = {v[l].first, v[r-1].first};
        }
        
        if(mp[v[l].second] == 1) mp.erase(v[l].second);
        else mp[v[l].second]--;
        l++;
      }
      return rng;
    }
};int main() {
  return 0;
}
