/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 22, Part 1                       #                       
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
    
    int n = 2008; // There were 2008 numbers in my input
    
    ll a = 0; // Final ans

    while (n--){
        ll x;
        cin >> x;
        
        // Pretty straightforward 
        for (int i = 0; i<2000; i++){
            ll temp = x * 64;
            x = x ^ temp;
            x %= mod;
            temp = x/32;
            x ^= temp;
            x %= mod;
            temp = x * 2048;
            x ^= temp;
            x %= mod;
        }

        a += x;
    }
    
    cout << a << endl;

    return 0;
}
