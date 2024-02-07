/*
Problem Name : 3026. Maximum Good Subarray Sum 
Author: Abdalrahman Shaban
Date: 05/02/2024 19:14:52
*/
class Solution {
public:
    long long maximumSubarraySum(vector<int>& v, int k) {
        int n = v.size();
        map<ll, ll> mp;
        ll prf[n];
        prf[0] = v[0];
        ll ans = -1e15;
        mp[v[0]] = ans;
        for(int i = 1; i < n; i++){
            prf[i] = prf[i-1] + v[i];
            mp[v[i]] = ans;
        }
        for(int i = n-1; i >= 0; i--){
            mp[v[i]] = max(mp[v[i]], prf[i]);
            if(mp[v[i]-k]){
                ll sm = 0;
                if(i == 0){
                    sm = mp[v[i]-k];
                }
                else{
                    sm = mp[v[i]-k] - prf[i-1];
                }
                ans = max(ans, sm);
            }
            if(mp[v[i]+k]){
                ll sm = 0;
                if(i == 0){
                    sm = mp[v[i]+k];
                }
                else{
                    sm = mp[v[i]+k] - prf[i-1];
                }
                ans = max(ans, sm);
            }
        }
        return (ans == -1e15 ? 0 : ans);
    }
};
