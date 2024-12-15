/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 14, Part 2                       #                       
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
  
    vector<vector<int>> vf; // Vector to store the coordinates and velocities of the robot.
  
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
        
        vf.push_back({x, y, vx, vy});
    }
    
    // Brute Force: Checking for each time t if all the robots are at distinct positions.
  
    for (int t = 0; t<=1000000; t++){
        for (auto& v: vf){
            int& x = v[0];
            int& y = v[1];
            int& vx = v[2];
            int& vy = v[3];
            a[y][x]--;
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
            a[y][x]++;
        }
        
        bool flag = 1;
        for (int i = 0; i<=102; i++){
            for (int j = 0; j<=100; j++){
                if (a[i][j] > 1){ // If more than one robot is found at (i, j), this is not a valid time and flag is set to 0
                    flag = 0;
                    break;
                }
            }
            if (!flag) break;
        }
      
        if (flag){
            cout << t + 1 << endl;
            break;
        }
    }
    return 0;
}
