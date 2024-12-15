/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 14, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/14         #                       
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
   
    int n = 500; // 500 robots in the input
    
    // Initializing the grid to store the number of robots at a moment on the cell (i, j)
    int a[103][101]; 
    for (int i = 0; i<103; i++){
        for (int j = 0; j<101; j++){
            a[i][j] = 0;
        }
    }
  
    for (int i = 0; i<n; i++){
        // Input parsing for x and y
        string s1, s2;
        cin >> s1 >> s2;
        s1 = s1.substr(2, (int)s1.size() - 2);
        s2 = s2.substr(2, (int)s2.size() - 2);
        string s;
        stringstream ss(s1);
        vector<string> v;
        while (getline(ss, s, ',')) {
            v.push_back(s);
        }
        int x = stoi(v[0]), y = stoi(v[1]);

        // Similar for vx and vy
        stringstream ss2(s2);
        vector<string> v2;
        while (getline(ss2, s, ',')) {
            v2.push_back(s);
        }
        int vx = stoi(v2[0]), vy = stoi(v2[1]);

        // Brute Force: Finding the coordinates after 100s, taking mod to accomodate cases where robot goes outside the grid.
        for (int i = 0; i<100; i++){
            x = (x + vx);
            if (x < 0){
                x += 101;
            }
            else{
                x %= 101;
            }
            y = (y + vy);
            if (y < 0){
                y += 103;
            }
            else{
                y %= 103;
            }
        }
        a[y][x]++;
    }

    // Counting the robots in the top left quadrant
    int c1 = 0;
    for (int i = 0; i<=50; i++){
        for (int j = 0; j<=49; j++){
            c1 += a[i][j];
        }
    } 

    // Bottom Left
    int c2 = 0;
    for (int i = 52; i<=102; i++){
        for (int j = 0; j<=49; j++){
            c2 += a[i][j];
        }
    }

    // Bottom Right
    int c3 = 0;
    for (int i = 52; i<=102; i++){
        for (int j = 51; j<= 100; j++){
            c3 += a[i][j];
        }
    }

    // Top right
    int c4 = 0;
    for (int i = 0; i<=50; i++){
        for (int j = 51; j<=100; j++){
            c4 += a[i][j];
        }
    }
  
    ll ans = 1ll * c1 * c2 * c3 * c4;
    cout << ans << endl;
  
    return 0;
}
