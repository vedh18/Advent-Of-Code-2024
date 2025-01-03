/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 18, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/18         #                       
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
    
    ll n = 1024; // First we only consider the first 1024 bits
    int m = 70;

    // Initializing required grids of size 71 x 71
    int grid[m + 1][m + 1];
    int vis[m + 1][m + 1];
    for (int i = 0; i<m + 1; i++){
        for (int j = 0; j<m + 1; j++){
            grid[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    
    // To avoid input parsing, I used {Ctrl-D --> Ctrl-F --> Find all} and replaced the commas with spaces.

    // Filling the grid with obstacles
    while (n--){
        int x, y;
        cin >> x >> y;
        grid[y][x] = 1;
    }

    // Simple bfs with queue containing {dist, {x, y}} to find shortest path to (m, m) from (0,0)
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {0, 0}});
    vis[0][0] = 1;
    ll ans = 5000000;
    while (!q.empty()){
        ll dist = q.front().f;
        int x = q.front().s.f;
        int y = q.front().s.s;
        q.pop();
        if (x == m && y == m){
            ans = min(ans, dist);
        }
        // Storing changes in coordinates possible to iterate through all neighbours easily.
        vector<pair<int, int>> v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        for (auto p : v){
            int dx = p.f;
            int dy = p.s;
            int temp_x = x + dx;
            int temp_y = y + dy;
            if (temp_x >= 0 && temp_x <=m && temp_y>=0 && temp_y<=m){
                if (grid[temp_x][temp_y] == 0 && vis[temp_x][temp_y] == 0){
                    vis[temp_x][temp_y] = 1;
                    q.push({dist+1, {temp_x, temp_y}});
                }
            }
        }
    }
    
    cout << ans << endl;
    
    return 0;
}
