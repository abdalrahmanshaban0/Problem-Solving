/*
Problem Name : K - Trees on the level 
Author: Abdalrahman Shaban
Date: 03/06/2024 15:05:32
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<long long> vi;
typedef pair<ll, ll> pi;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_multiset;
/*
   order_of_key (k) : Number of items strictly smaller than k .
   find_by_order(k) : K-th element in a set (counting from zero).
*/
#define endl '\n'
#define YES cout << "YES\n"
#define NO cout << "NO\n"
#define all(x) x.begin(), x.end()
#define allr(x) x.rbegin(), x.rend()
void vin(vector<ll>& v) {for(auto& i : v) cin >> i;}

const ll MOD = 1000000007;
const ll inf = LONG_LONG_MAX;

ll gcd(ll a, ll b) { return a ? gcd(b % a, a) : b; }
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll nCr(ll n, ll r) { if (r == 0 || n == r) return 1; return nCr(n - 1, r - 1) * n / r;}

void file() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
}

void Fast() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

//int dx[] = {0,0,1,-1};
//int dy[] = {1,-1,0,0};
//int dx[] = {0,0,1,-1,-1,-1,1,1};
//int dy[] = {1,-1,0,0,1,-1,-1,-1};


struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) { }
    TreeNode(int v, TreeNode* l, TreeNode* r) : val(v), left(l), right(r) { }
};

bool addnode(int val, string& pos, int i, TreeNode* root){
    if(i == pos.size()-1){
        TreeNode* temp = new TreeNode(val, NULL, NULL);

        if(pos[i] == 'L'){
            if(root->left != NULL) return 0;
            root->left = temp;
        }
        else{
            if(root->right != NULL) return 0;
            root->right = temp;
        }
        return 1;
    }
    bool ok = 0;
    if(pos[i] == 'L'){
        if(root->left == NULL) return 0;
        ok = addnode(val, pos, i+1, root->left);
    }
    else{
        if(root->right == NULL) return 0;
        ok = addnode(val, pos, i+1, root->right);
    }
    return ok;
}

bool cmp(pair<int, string>& a, pair<int, string>& b){
    return(a.second.size() < b.second.size());
}

void print_tree(TreeNode* root){
    if(root == NULL) return;
    queue<TreeNode*> q;
    q.push(root);
    int cnt = 0;
    while(!q.empty()){
        TreeNode* cur = q.front();
        q.pop();
        if(cnt++) cout << ' ';
        cout << cur->val;
        if(cur->left)
            q.push(cur->left);
        if(cur->right)
            q.push(cur->right);
        delete cur;
    }
    cout << endl;
}

    void deltree(TreeNode* root){
        if(root == NULL) return;
        deltree(root->left);
        deltree(root->right);
        delete root;
    }

void solve(vector<pair<int, string>>& v){    
    sort(all(v), cmp);
    TreeNode* root = NULL;
    if(v[0].second.size() == 0){
        root = new TreeNode(v[0].first, NULL, NULL);
    }
    else{
        cout << "not complete\n";
        return;
    }
    bool ok = 1;
    for(int i = 1; i < v.size(); i++){
        if(!addnode(v[i].first, v[i].second, 0, root)){
            ok = 0;
        }
    }
    if(!ok){
        cout << "not complete\n";
        deltree(root);
    }
    else{
        print_tree(root);
    }
}

int main() {
    Fast();
    file();

    string s;        
    vector<pair<int, string>> v;
    while(cin >> s){
        if(s.size() > 2){
            stringstream ss(s);
            char dummy;
            int val; pair<int, string> p;
            ss >> dummy >> p.first >> dummy >> p.second;
            p.second.pop_back();
            v.push_back(p);
        }
        else{
            solve(v);
            v.clear();
        }
    } 

    return 0;
}
