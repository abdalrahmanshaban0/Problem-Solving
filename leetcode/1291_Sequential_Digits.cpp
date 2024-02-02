/*
Problem Name : 1291. Sequential Digits 
Author: Abdalrahman Shaban
Date: 02/02/2024 15:12:02
*/
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string s = "123456789";
        vector<int> ans;
        int n = s.size();
        for(int i = 0 ;i < n; i++){
            string temp;
            for(int j = i; j < n; j++){
                temp += s[j];
                int val = stoi(temp);
                if(val >= low && val <= high){
                    ans.push_back(val);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};
