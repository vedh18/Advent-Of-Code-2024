/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 19, Part 1                       #                       
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

// Simple recursion to check if currDesign could be extended to desiredDesign using patterns (trying them each one by one).
bool is_possible(string desiredDesign, string currDesign, vector<string> paterns) {
    if (currDesign == desiredDesign) return true; 
    if (currDesign.size() > desiredDesign.size()) return false; 

    for (auto fragment : paterns) {
        int t = fragment.size();
        
        // Checking if the fragment can edesiredDesigntend the current string
        if (currDesign.size() + t <= desiredDesign.size() && desiredDesign.substr(currDesign.size(), t) == fragment) {
            if (is_possible(desiredDesign, currDesign + fragment, paterns)) {
                return true; 
            }
        }
    }
    return false;
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

    int count = 0;
    while (m--) {
        string desiredDesign;
        cin >> desiredDesign;

        if (is_possible(desiredDesign, "", paterns)) {
            count++;
        }
    }

    cout << count << endl;
    return 0;
}
