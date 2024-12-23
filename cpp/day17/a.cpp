/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 17, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/17         #                       
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

ll a,b,c; // Global Variables to store the value of the registers.

// Function which returns the combo operant of x
ll combo(ll x){
    if (x>=0 && x<=3){
        return x;
    }
    else if (x == 4){
        return a;
    }
    else if (x == 5){
        return b;
    }
    else if (x == 6){
        return c;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    // To avoid input parsing, I removed all non integer characters
    // (was easier as there weren't many)

    cin >> a >> b >> c;

    ll n = 16; // The number of instructions in the input
    
    vector<int> v(n);
    for (int i = 0; i<n; i++){
        cin >> v[i];
    }

    // Simply followed the instructions
    for (int i = 0; i<n-1; i+=2){
        ll n = v[i];
        ll m = v[i+1];
        if (n == 0){
            a = a/(1<<combo(m));
        }
        else if (n == 1){
            b = b ^ m;
        }
        else if (n == 2){
            b = combo(m) % 8;
        }
        else if (n == 3){
            if (a==0)continue;
            i = m;
            i -= 2;
        }
        else if (n == 4){
            b = b ^ c;
        }
        else if (n == 5){
            cout << combo(m) % 8 << ",";
        }
        else if (n == 6){
            b = a/(1<<combo(m));
        }
        else{
            c = a/(1<<combo(m));
        }
    }

    // Removed the last comma while entering the answer from the output.

    return 0;
}
