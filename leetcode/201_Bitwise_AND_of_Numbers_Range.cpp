/*
Problem Name : 201. Bitwise AND of Numbers Range 
Author: Abdalrahman Shaban
Date: 21/02/2024 18:19:23
*/
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int ans = 0;
        for(int i = 30; i >= 0; i--){
            if((left & (1<<i)) != (right & (1<<i))){
                break;
            }
            else{
                ans |= (right&(1<<i));
            }
        }
        return ans;
    }
};
