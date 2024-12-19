/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 16, Part 1                       #                       
#     Problem Link: https://adventofcode.com/2024/day/16         #                       
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

    int n = 141;
    int a[n][n];
    int sx, sy, ex, ey;
    vector<vector<ll>> dist(n, vector<ll>(n, LLONG_MAX));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            char x;
            cin >> x;
            // cout << x;
            if (x == '#') a[i][j] = 1;
            if (x == '.') a[i][j] = 0;
            if (x == 'S') {
                a[i][j] = 0;
                sx = i;
                sy = j;
            }
            if (x == 'E') {
                a[i][j] = 0;
                ex = i;
                ey = j;
            }
            // cout << a[i][j];
        }
        // cout << endl;
    }

    queue<vector<ll>> pq;
    pq.push({0, 0, 1, sx, sy});
    dist[sx][sy] = 0;

    while (!pq.empty()) {
        ll currDist = pq.front()[0];
        ll currDx = pq.front()[1];
        ll currDy = pq.front()[2];
        ll x = pq.front()[3];
        ll y = pq.front()[4];
        pq.pop();

        if (x == ex && y == ey) {
            continue;
            // return 0;
        }

        vector<pair<ll, ll>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (auto dir : directions) {
            ll tx = x + dir.first, ty = y + dir.second;
            if (tx >= 0 && tx < n && ty >= 0 && ty < n && a[tx][ty] == 0) {
                ll newDist = currDist + (make_pair(currDx, currDy) == dir ? 1 : make_pair(currDx, currDy) == make_pair(-dir.first, -dir.second) ? INT_MAX: 1001);
                if (dist[tx][ty] > newDist) {
                    dist[tx][ty] = newDist;
                    pq.push({newDist, dir.first, dir.second, tx, ty});
                }
            }
        }
    }

    cout << dist[ex][ey] << endl;
    return 0;
}
