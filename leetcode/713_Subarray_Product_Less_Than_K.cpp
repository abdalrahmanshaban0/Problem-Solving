/*
Problem Name : 713. Subarray Product Less Than K 
Author: Abdalrahman Shaban
Date: 27/03/2024 07:41:40
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smof(int num){
        return (num*(num+1)/2);
    }
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int n = nums.size();
        int ret = 0, temp = 1;
        int cnt = 0;
        int l = 0;
        for(int r = 0; r < n && l < n; r++){
            temp *= nums[r];
            if(temp < k){
                cnt++;
            }
            else{
                ret += smof(cnt);
                while(temp >= k){
                    cnt--;
                    temp /= nums[l++];
                }
                if(temp < k) cnt++;
                ret -= smof(r-l);
            }
        }
        ret += smof(cnt);
        return ret;
    }
};

int main() {

    return 0;
}
