/*
Problem Name : 567. Permutation in String
Author: Abdalrahman Shaban
Date: 05/10/2024 23:56:47
*/
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define all(s) s.begin(), s.end()
void Fast();

class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    int frq1[26] = {}, frq2[26] = {};
    for (auto &i : s1) {
      frq1[i - 'a']++;
    }
    int l = 0;
    for (int i = 0; i < s2.size(); i++) {
      if (i < s1.size()) {
        frq2[s2[i] - 'a']++;
      } else {
        bool f = 1;
        for (int j = 0; j < 26; j++) {
          if (frq1[j] != frq2[j]) {
            f = 0;
            break;
          }
        }
        if (f)
          return true;
        frq2[s2[l++] - 'a']--;
        frq2[s2[i] - 'a']++;
      }
    }
    for (int j = 0; j < 26; j++) {
      if (frq1[j] != frq2[j]) {
        return false;
      }
    }
    return true;
  }
};
int main() { return 0; }
