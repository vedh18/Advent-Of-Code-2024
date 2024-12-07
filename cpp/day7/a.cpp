/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 7, Part 1                        #                       
#     Problem Link: https://adventofcode.com/2024/day/7          #                       
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

// Global varaible to store the test value of a equation.
ll result;

// Brute force with recursion to try out every possible operation at a possible space.
// If the result after evaluating all the numbers in the vector is equal to the test value, returns true.
bool rec(vector<ll>& nums, int idx, ll pr){
    if (idx == (int)nums.size()){
        return (result == pr);
    }
    else if (idx == 0){
        return rec(nums, idx + 1, nums[idx]);
    }
    return rec(nums, idx + 1, pr + nums[idx]) | rec(nums, idx + 1, pr * nums[idx]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    int n = 850; // The number of lines in the input
    
    ll ans = 0;
    while (n--){
        string input;
        getline(cin, input);

        // The store the line input in a vector of strings splitted by ' '
        string s;
        stringstream ss(input);
        vector<string> v;
        while (getline(ss, s, ' ')) {
            v.push_back(s);
        }

        // Processing the test value 
        string a = v[0];
        a.pop_back();
        result = stoll(a);

        // Storing the other numbers of the string in a vector
        vector<ll> nums;
        for (ll i = 1; i<(int)v.size(); i++){
            nums.push_back(stoll(v[i]));
        }

        if (rec(nums, 0, 0)){
            ans += result;
        }
    }

    cout <<ans << endl;

    return 0;
}
