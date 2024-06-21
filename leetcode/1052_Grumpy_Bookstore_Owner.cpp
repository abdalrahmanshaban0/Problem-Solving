#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSatisfied(vector<int>& c, vector<int>& b, int m) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        int n = c.size();
        int sm = 0, mx = 0, mxsm = 0, mxi = 0, mxj = 0;
        int l = 0, r = 0;
        while(r < m){
            if(b[r]) sm += c[r];
            r++;
        }
        mxj = r-1, mxsm = sm;
        for(; r < n; r++){
            if(b[r])sm += c[r];
            if(b[l]) sm -= c[l];
            l++;
            if(sm > mxsm){
                mxsm = sm;
                mxi = l;
                mxj = r;
            }
        }
        int ans = 0;
        for(int i = 0; i < n; i++){
            if(i >= mxi && i <= mxj){
                ans += c[i];
            }
            else{
                if(!b[i]) ans += c[i];
            }
        }
        return ans;
    }
};

int main(){
    return 0;
}
