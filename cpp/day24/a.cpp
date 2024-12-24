/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 24, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/24         #                       
#                                                                #                       
##################################################################
*/


#include<bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define pb push_back
#define ll long long int
#define all(v) (v).begin(), (v).end()
#define printvec(vec) {for(int i = 0; i < vec.size(); i++) cout << vec[i] << " "; cout << endl;} 

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    map<string, int> mp;
    int n = 90;
    set<string> al;

    while (n--){
        string x;
        int a;
        cin >> x >> a;
        mp[x] = a;
        al.insert(x);
    }
    int m = 313 - 92 + 1;
    set<vector<string>> v;
    while (m--){
        string a, b, op, c;
        cin >> a >> op >> b >> c;
        if (mp.find(a) != mp.end() && mp.find(b) != mp.end()){
            if (op == "AND"){
                mp[c] = mp[a] & mp[b];
            }
            if (op == "OR"){
                mp[c] = mp[a] | mp[b];
            }
            if (op == "XOR"){
                mp[c] = mp[a] ^ mp[b];
            }
        }
        else{
            v.insert({a, op, b, c});
        }
    }
    while (!v.empty()){
        for (auto x: v){
            string a = x[0], op = x[1], b = x[2], c = x[3];
            if (mp.find(a) != mp.end() && mp.find(b) != mp.end()){
                v.erase(x);
                if (op == "AND"){
                    mp[c] = mp[a] & mp[b];
                }
                if (op == "OR"){
                    mp[c] = mp[a] | mp[b];
                }
                if (op == "XOR"){
                    mp[c] = mp[a] ^ mp[b];
                }
            }

        }
    }
    set<pair<string, int>> s;
    for (auto a: mp){
        if (a.f[0] == 'z'){
            s.insert({a.f, a.s});
        }
    }
    ll ans = 0;
    ll i = 0;
    cout << (int)mp.size() << " "; 
    for (auto x: s){
        if (x.s == 1){
            ans += (1ll<<i);
        }
        i++;
    }
    cout << ans << endl;
    return 0;
}
