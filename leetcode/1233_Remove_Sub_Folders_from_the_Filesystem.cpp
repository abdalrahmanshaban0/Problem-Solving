/*
Problem Name : 1233. Remove Sub-Folders from the Filesystem
Author: Abdalrahman Shaban
Date: 25/10/2024 10:20:04
*/
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
  vector<string> removeSubfolders(vector<string> &folder) {
    sort(folder.begin(), folder.end());
    for (int i = 1; i < folder.size(); i++) {
      string s = folder[i - 1];
      int j = i;
      while (j < folder.size() && (folder[j].size() >= s.size() + 1) &&
             (s + "/" == folder[j].substr(0, s.size() + 1))) {
        folder[j] = '#';
        j++;
      }
      i = j;
    }
    vector<string> ans;
    for (auto &i : folder) {
      if (i != "#")
        ans.push_back(i);
    }
    return ans;
  }
};

int main() { return 0; }
