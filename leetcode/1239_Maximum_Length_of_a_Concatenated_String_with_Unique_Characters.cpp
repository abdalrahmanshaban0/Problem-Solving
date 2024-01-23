/*
Problem Name : 1239. Maximum Length of a Concatenated String with Unique Characters 
Author: Abdalrahman Shaban
Date: 23/01/2024 12:47:33
*/

class Solution {
public:
    int frq[26];
    int mx;
    Solution(){
        mx = 0;
        memset(frq, 0, sizeof(frq));
    }
    void bt(int idx, vector<string>& arr){
        if(idx == arr.size()){
            int cnt = 0;
            for(int i = 0; i < 26; i++){
                if(frq[i] > 1) return;
                cnt += frq[i];
            }
            mx = max(mx, cnt);
            return;
        }
        for(auto& i : arr[idx]){
            frq[i-'a']++;
        }
        bt(idx+1, arr);
        for(auto& i : arr[idx]){
            frq[i-'a']--;
        }
        bt(idx+1, arr);
    }
    int maxLength(vector<string>& arr) {
        bt(0, arr);
        return mx;
    }
};


