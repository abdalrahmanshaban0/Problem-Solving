/*
Problem Name : 3024. Type of Triangle II 
Author: Abdalrahman Shaban
Date: 03/02/2024 20:29:56
*/
class Solution {
public:
    string triangleType(vector<int>& v) {
        if(v[0]+v[1] <= v[2] || v[1]+v[2] <= v[0] || v[0]+v[2]<=v[1]){
            return "none";
        }
        if(v[0]==v[1] && v[1] == v[2]){
            return "equilateral";
        }
        if(v[0]==v[1] || v[0] == v[2] || v[1] == v[2]){
            return "isosceles";
        }
        return "scalene";
    }
};
