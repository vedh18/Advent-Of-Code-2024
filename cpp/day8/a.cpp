/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 8, Part 1                        #                       
#     Problem Link: https://adventofcode.com/2024/day/8          #                       
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
    
    int n = 50; // The input was a 50 x 50 grid of characters
    char a[n][n];

    int antinode[n][n]; // To store if a cell is an antinode
    
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> a[i][j];
            antinode[i][j] = 0; // 0 initially
        }
    }

    // Brute force: For every two cells with the same antena, creating antinodes with the relative distance of one point over the other.
    for (int i1 = 0; i1<n; i1++){
        for (int j1 = 0;j1<n; j1++){
            
            if (a[i1][j1] == '.') continue;

            // First cell - (i1, j1) with antena
            for (int i2 = 0; i2<n; i2++){
                for (int j2 = 0; j2<n; j2++){
                    
                    // Second cell - (i2, j2) with the same antena as (i1, j1)
                    if ((i1 != i2 || j1 != j2) && a[i1][j1] == a[i2][j2]){
                        // The coordinates for a potential antinode formed by adding the relative distance between the points.
                        int j3 = j2 + (j2 - j1);
                        int i3 = i2 + (i2 - i1);
                        
                        // If the coordinates are valid then an antinode is placed.
                        if (i3>=0 && i3<n && j3>=0 && j3<n){
                            antinode[i3][j3] = 1;
                        }   
                    }
                }
            }
        }
    }
    
    int ans = 0;
    
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (antinode[i][j] == 1){
                ans++;
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}
