/*
Problem Name : 442. Find All Duplicates in an Array 
Author: Abdalrahman Shaban
Date: 25/03/2024 22:38:13
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        const int N = 1e6;
        int frq[N] = {};
        for(int i : nums){
            frq[i]++;
        }
        int n = nums.size();
        vector<int> ret;
        for(int i = 1; i <= n; i++){
            if(frq[i] == 2) ret.push_back(i);
        }
        return ret;
    }
};

int main(){
    return 0;
}
