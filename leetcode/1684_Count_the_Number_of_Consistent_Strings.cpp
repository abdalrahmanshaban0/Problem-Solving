/*
Problem Name : 1684. Count the Number of Consistent Strings
Author: Abdalrahman Shaban
Date: 12/09/2024 08:25:05
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int countConsistentStrings(string a, vector<string> &w) {
    unordered_map<char, bool> mp;
    for(auto& i : a) mp[i] = 1;
    int ans = 0;
    for(auto& i : w){
      bool f = 1;
      for(auto& j : i){
        if(!mp[j]){
          f = 0; break;
        }
      }
      if(f) ans++;
    }
    return ans;
  }
};

int main() { return 0; }
