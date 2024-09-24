/*
Problem Name : 3043. Find the Length of the Longest Common Prefix
Author: Abdalrahman Shaban
Date: 24/09/2024 12:50:18
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
  int longestCommonPrefix(vector<int> &arr1, vector<int> &arr2) {
    unordered_map<int, bool> mp;
    for(auto& i : arr1){
      string s = to_string(i);
      string temp;
      for(auto& j : s){
        temp += j;
        mp[stoi(temp)] = 1;
      }
    }
    int ans = 0;
    for(auto& i : arr2){
      string s = to_string(i);
      string temp;
      for(auto& j : s){
        temp += j;
        if(mp[stoi(temp)]){
          ans = max(ans, (int)temp.size());
        }
      }
    }
    return ans;
  }
};

int main() { return 0; }
