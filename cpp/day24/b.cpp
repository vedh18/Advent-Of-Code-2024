/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 24, Part 2                       #                       
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
    int m1= 313 - 92 + 1;
    set<vector<string>> v;
    map<string, vector<string>> par;
    map<string, string> m;
    m["AND"] = "green";
    m["OR"] = "red";
    m["XOR"] = "yellow";
    // map<string, string> mp;
    while (m1--){
        string a, b, op, c;
        cin >> a >> op >> b >> c;
        v.insert({min(a, b), op, max(a, b), c});
        cout << c << "[color=\"" << m[op] << "\"]" << endl;
        par[c] = {a, op, b};

    }
    // map<string, string> mp;
    for (auto x: v){
        cout << x[0] << " -> " << x[3] << ";" << endl;
        cout << x[2] << " -> " << x[3] << ";" << endl;
    }
    for (int i = 10; i<=44; i++){
        cout << "x" << i << endl;
    }
    return 0;
}
