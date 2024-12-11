/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 11, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/11         #                       
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

// dp map for memoization, where dp[{i, j}] stores the number of elements i breaks down into after j blinks.
// by default map values are 0
map<pair<ll, ll>, ll> dp;

ll rec(ll num, ll blinks){
    if (dp[{num, blinks}] != 0) return dp[{num, blinks}]; // If already calculated
    
    // base case
    if (blinks == 0){
        return 1;
    }
    else if (num == 0){
        return dp[{num, blinks}] = rec(1, blinks - 1);
    }
    string st = to_string(num);
    if ((int)st.size() % 2 == 0){
        string st1 = st.substr(0, (int)st.size()/2);
        string st2 = st.substr((int)st.size()/2, (int)st.size()/2);
        return dp[{num, blinks}] = rec(stoll(st1), blinks -1) + rec(stoll(st2), blinks - 1);
    }
    else{
        return dp[{num, blinks}] = rec(num * 2024, blinks - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    int n = 8; // The number of elements in the vector
    
    vector<ll> v(n);
    
    for (int i = 0; i<n; i++){
        cin >> v[i];
    }

    int blinks = 75;
    
    ll ans = 0;
    for (int i = 0; i<n; i++){
        ans += rec(v[i], blinks); // Adding the number of elements each element will break down into after 75 blinks
    }
    
    cout << ans << endl;
    
    return 0;
}
