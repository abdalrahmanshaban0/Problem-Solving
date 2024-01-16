/*
Problem Name : Extra Long Factorials 
Author: Abdalrahman Shaban
Date: 16/01/2024 11:51:12
*/
#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'extraLongFactorials' function below.
 *
 * The function accepts INTEGER n as parameter.
 */

void sm(string& x, string& temp){
    int carry = 0;
    int it = temp.size()-1;
    for(int i = x.size()-1; i >= 0; i--, it--){
        int chk = (x[i]-'0') + carry;
        carry = 0;
        if(it >= 0){
            chk += (temp[it]-'0');
        }
        if(chk >= 10){
            carry++;
        }
        chk %= 10;
        x[i] = (char)(chk+'0');
    }
    if(carry) x = "1" + x;
}

void extraLongFactorials(int n) {
    string x = to_string(n);
    for(int num = n-1; num >= 1; num--){
        string temp = x;
        for(int j = 1; j < num; j++){
            sm(x, temp);
        }
    }
    cout << x;
}


int main()
{
    string n_temp;
    getline(cin, n_temp);

    int n = stoi(ltrim(rtrim(n_temp)));

    extraLongFactorials(n);

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
            s.begin(),
            find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
           );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
            find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
            s.end()
           );

    return s;
}


