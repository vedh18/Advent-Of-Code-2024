/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 19, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/19         #                       
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

map<string, ll> dp; // Map for memoization.

// Recursion with memoization to count all the ways currDesign can be extended to desiredDesign.
ll count_ways(string desiredDesign, string currDesign, vector<string> paterns) {
    if (currDesign == desiredDesign) return 1; 
    if (currDesign.size() > desiredDesign.size()) return 0; 

    // If already calculated
    if (dp.count(currDesign)) return dp[currDesign]; 

    ll ways = 0;
    for (auto fragment : paterns) {
        int t = fragment.size();
        
        // Checking if the fragment can extend currDesign to desiredDesign
        if (currDesign.size() + t <= desiredDesign.size() && desiredDesign.substr(currDesign.size(), t) == fragment) {
            ways += count_ways(desiredDesign, currDesign + fragment, paterns);
        }
    }
    return dp[currDesign] = ways;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 447, m = 400; // The input was observed to have 447 towel patterns and 400 desired designs.

    // To avoid input parsing, I used {Ctrl-D --> Ctrl-F --> Find all} and replaced the commas with spaces.

    vector<string> paterns(n);
    for (int i = 0; i < n; i++) {
        cin >> paterns[i];
    }

    ll count = 0;
    while (m--) {
        string desiredDesign;
        cin >> desiredDesign;

        dp.clear();

        count += count_ways(desiredDesign, "", paterns);

    }

    cout << count << endl;
    return 0;
}
