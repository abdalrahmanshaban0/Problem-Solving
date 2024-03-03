/*
Problem Name : Super Reduced String 
Author: Abdalrahman Shaban
Date: 02/03/2024 21:43:27
*/

#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'superReducedString' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string superReducedString(string s) {
    int n = s.size();
    string ans;
    int it = 0;
    while(!s.empty() && it+1 < s.size()){        
        if(s[it] == s[it+1]){
            s.erase(s.begin()+it);
            s.erase(s.begin()+it);
            it = 0;
        }
        else{
            it++;
        }
    }
    return (s.empty() ? "Empty String" : s);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = superReducedString(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

