/*
Problem Name : 948. Bag of Tokens 
Author: Abdalrahman Shaban
Date: 04/03/2024 21:42:59
*/
class Solution {
public:
    int bagOfTokensScore(vector<int>& v, int p) {
        sort(v.begin(), v.end());
        int n = v.size(), mx = 0;
        int l = 0, r = n-1, sm = p, sc = 0;
        while(l <= r){
            if(sm >= v[l]){
                sm -= v[l];
                sc++;
                l++;
            }
            else{
                if(sc > 0){
                    sm += v[r];
                    r--, sc--;
                }
                else{
                    break;
                }
            }
            mx = max(mx, sc);
        }
        return mx;
    }
};
