/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 18, Part 2                       #                       
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
    
    ll n = 3450;
    int m = 70;
    int g_gird[m + 1][m + 1];
    int vis[m + 1][m + 1];
    for (int i = 0; i<m + 1; i++){
        for (int j = 0; j<m + 1; j++){
            g_gird[i][j] = 0;
            vis[i][j] = 0;
        }
    }
    vector<pair<int, int>> coord;
    while (n--){
        int x, y;
        cin >> x >> y;
        coord.push_back({y, x});
    }
    // for (int i = 0; i<m + 1; i++){
    //     for (int j = 0; j<m + 1; j++){
    //         cout << g_gird[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // vis[]
    int l = 1024;
    int r = 3449;
    pair<int, int> p;
    while (l <= r){
        int grid[m+1][m+1];
        for (int i = 0; i<=m; i++){
            for (int j = 0; j<=m; j++){
                grid[i][j] = 0;
                vis[i][j] = 0;
            }
        }
        int mid = l + (r-l)/2;
        for (int i = 0; i<=mid; i++){
            grid[coord[i].f][coord[i].s] = 1;
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {0, 0}});
        vis[0][0] = 1;
        ll ans = 5000000;
        while (!q.empty()){
            ll dist = q.front().f;
            int x = q.front().s.f;
            int y = q.front().s.s;
            q.pop();
            vector<pair<int, int>> v = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            if (x == m && y == m){
                ans = min(ans, dist);
                // cout << dist << endl;
                // continue;
            }
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
        if (ans == 5000000){
            p = coord[mid];
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << p.s << "," << p.f << endl;
    return 0;
}
