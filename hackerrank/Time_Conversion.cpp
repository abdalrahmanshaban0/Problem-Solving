#include <bits/stdc++.h>

using namespace std;

/*
 * Complete the 'timeConversion' function below.
 *
 * The function is expected to return a STRING.
 * The function accepts STRING s as parameter.
 */

string timeConversion(string s) {
    string w = s.substr(s.size()-2, 2);
    string f = s.substr(2, s.size()-4);
    string hs = s.substr(0,2);
    int h = stoi(hs);
    string ans;
    if(h == 12){
        if(w == "PM"){
            ans = hs + f;
        }
        else{
            ans = "00" + f;
        }
    }
    else{
        if(w == "PM"){
            ans = to_string(h+12) + f;
        }
        else{
            ans = hs + f;
        }
    }
    return ans;   
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    string result = timeConversion(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

