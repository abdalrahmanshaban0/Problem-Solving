/*
Problem Name : 1481. Least Number of Unique Integers after K Removals 
Author: Abdalrahman Shaban
Date: 16/02/2024 15:24:27
*/
class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        int n  = arr.size();
        map<int, int> mp;
        for(auto& i : arr){
            mp[i]++;
        }
        vector<int> v;
        for(auto& i : mp){
            v.push_back(i.second);
        }
        sort(v.begin(), v.end());
        int ans = mp.size();
        for(int i = 0; i < v.size(); i++){
            if(k >= v[i]){
                k -= v[i];
                ans--;
            }
            else{
                break;
            }
        } 
        return ans;
    }
};
