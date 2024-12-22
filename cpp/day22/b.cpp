/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 22, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/22         #                       
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
    
    ll mod = 16777216;
    
    ll n = 2008; // There were 2008 numbers in my input
    
    ll ax = 0; // Final ans
    
    vector<vector<ll>> vvg; // Vector of vectors to store the first digit of the the first 2000 special numbers for each input
    set<vector<ll>> vg; // Set of vectors to find all possible sequence of changes of length 4

    while (n--){
        ll x;
        cin >> x;
        
        vector<ll> v; // Vector to store the first digit of the the first 2000 special numbers for the current input
        
        v.push_back(fir(x));
        for (ll i = 0; i<2000; i++){
            ll temp = x * 64;
            x = x ^ temp;
            x %= mod;
            temp = x/32;
            x ^= temp;
            x %= mod;
            temp = x * 2048;
            x ^= temp;
            x %= mod;
            v.push_back(fir(x));
        }
        vvg.push_back(v);
    }

    // dp map to store the value where dp[{i, v}] is the value obtained by the ith input if the monkey is looking for
    // 'v' sequence of changes
    map<pair<ll, vector<ll>>, ll> dp;

    // Filling the dp map and the vg set of vectors.
    for (int j = 0; j<2008; j++){
        vector<ll> v = vvg[j];
        for (ll i = 4; i<(ll)v.size(); i++){
            vector<ll> temp = {v[i-3]-v[i-4], v[i-2]-v[i-3], v[i-1]-v[i-2], v[i]-v[i-1]};
            vg.insert(temp);
            if (dp.find({j, temp}) == dp.end()){
                dp[{j, temp}] = v[i];
            }
        }
    }

    for (auto vec: vg){
        ll a = 0; // The answer for the current sequence of changes vec
        for (int j = 0; j<2008; j++){
            if (dp.find({j, vec}) == dp.end()) continue;
            a += dp[{j, vec}];
        }
        ax = max(ax, a);
    }

    cout << ax << endl;

    return 0;
}
