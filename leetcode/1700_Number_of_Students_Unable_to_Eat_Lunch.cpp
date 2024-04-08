/*
Problem Name : 1700. Number of Students Unable to Eat Lunch 
Author: Abdalrahman Shaban
Date: 08/04/2024 14:12:34
*/
class Solution {
public:
    int countStudents(vector<int>& s, vector<int>& sw) {
        queue<int> q;
        for(auto& i : s) q.push(i);
        int sz = s.size(), cnt = 0;
        int i = 0;
        while(!q.empty() && cnt < sz){
            if(sw[i] == q.front()){
                q.pop();
                i++;
                cnt = 0; 
                sz--;
            }
            else{
                cnt++;
                q.push(q.front());
                q.pop();
            }
        }
        return q.size();
    }
};
