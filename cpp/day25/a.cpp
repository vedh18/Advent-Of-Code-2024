/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 25, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/25         #                       
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
    
    int n = 500; // The number of inputs in the grid.
    
    vector<vector<int>> keys, locks; // To store 

    for (int i = 0; i<n; i++){
        // Input the gird
        char grid[5][7];
        for (int j = 0; j<7; j++){
            for (int k = 0; k<5; k++){
                cin >> grid[j][k];
            }
        }
        // Identify if the given grid is a lock or a key.
        bool lock = 1;
        for (int i = 0; i<5; i++){
            if (grid[0][i] != '#'){
                lock = 0;
                break;
            }
        }
        // Store the key/lock => as a vector with size 5 
        if (lock){
            vector<int> v;
            for (int i = 0; i<5; i++){
                int c = 0;
                for (int j= 1; j<7; j++){
                    c += (grid[j][i] == '#');
                }
                v.push_back(c);
            }
            locks.push_back(v);
        }
        else{
            vector<int> v;
            for (int i = 0; i<5; i++){
                int c = 0;
                for (int j= 5; j>=0; j--){
                    c += (grid[j][i] == '#');
                }
                v.push_back(c);
            }
            keys.push_back(v);
        }
    }

    ll ans = 0;

    // Brute force: For every lock check each key if it sets in the lock.
    for (auto lock: locks){
        for (auto key: keys){
            bool flag = 1; // flag to check if current lock/key combo is valid
            for (int i = 0; i<5; i++){
                // max value of sum should be 5.
                if (lock[i] + key[i] > 5){
                    flag = 0;
                    break;
                }
            }
            ans += flag;
        }
    }

    cout << ans << endl;
    
    return 0;
}
