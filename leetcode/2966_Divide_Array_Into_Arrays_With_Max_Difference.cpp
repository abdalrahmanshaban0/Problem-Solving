/*
Problem Name : 2966. Divide Array Into Arrays With Max Difference 
Author: Abdalrahman Shaban
Date: 01/02/2024 14:45:03
*/
class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& v, int k) {
        sort(v.begin(), v.end());
        vector<vector<int>> ans;
        vector<int> temp;
        temp.push_back(v[0]);
        int it = 0;
        for(int i = 1; i < v.size(); i++){
            if(temp.size() == 3 || v[i]-v[it] > k){
                if(temp.size() < 3){
                    return {};
                }
                ans.push_back(temp);
                temp.clear();
                it = i;
                temp.push_back(v[it]);
            }
            else{
                temp.push_back(v[i]);
            }
        }
        if(temp.size() < 3) return {};
        ans.push_back(temp);
        return ans;
    }
};
