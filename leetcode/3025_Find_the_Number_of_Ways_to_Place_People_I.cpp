/*
Problem Name : 3025. Find the Number of Ways to Place People I 
Author: Abdalrahman Shaban
Date: 03/02/2024 18:27:23
*/
class Solution {
public:
    int numberOfPairs(vector<vector<int>>& v) {
        sort(v.begin(), v.end());
        int n = v.size();
        int ans = 0;
        for(int i = 0; i < n-1; i++){
            for(int j = i+1; j < n; j++){
                if((v[i][0] == v[j][0] || v[i][1] == v[j][1]) || (v[i][0] < v[j][0] && v[i][1] > v[j][1])){
                    bool f = 1;
                    for(int k = 0; k < n; k++) if(k != i && k != j){
                        if(v[k][0] >= v[i][0] && v[k][0] <= v[j][0] && v[k][1] <= v[i][1] && v[k][1] >= v[j][1]){
                            f = 0;
                            break;
                        }
                        if(v[k][0] <= v[i][0] && v[k][0] >= v[j][0] && v[k][1] >= v[i][1] && v[k][1] <= v[j][1]){
                            f = 0;
                            break;
                        }
                    }
                    if(f) ans++;
                }
            }
        }
        return ans;
    }
};
