/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 20, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/20         #                       
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

#define n 141

bool isValid(int x, int y){
    return x>=0 && y>=0 && y<n && x<n;
}

// updates dist array so that dist[i][j] is the smallest distance from (sx, sy) to (i, j)
void bfs(ll a[][n], ll dist[][n], ll sx, ll sy){
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            dist[i][j] = n*n;
        }
    }

    queue<vector<ll>> q;

    dist[sx][sy] =0;
    q.push({0, sx, sy});

    while(!q.empty()){
        ll currDist = q.front()[0];
        ll x = q.front()[1];
        ll y = q.front()[2];
        q.pop();
        
        vector<pair<ll, ll>> directions = {{0,1}, {0,-1},{1,0}, {-1,0}};
        
        for (auto direction: directions){
            ll tx = direction.f + x;
            ll ty = direction.s + y;
            if (isValid(tx, ty) && a[tx][ty] == 0 && dist[tx][ty] > currDist+1){
                dist[tx][ty] = currDist+1;
                q.push({currDist+1, tx,ty});
            }
        }
    }
    return;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 

    ll a[n][n]; // a[i][j] represents the input grid, if a[i][j] --> 1 then obstacle ('#') else no obstacle
    ll sx, sy, ex, ey; 
    
    for (ll i = 0; i<n; i++){
        for (ll j = 0; j<n; j++){
            char x;
            cin >> x;
            if (x == '#'){
                a[i][j] = 1;
            }
            else{
                a[i][j] = 0;
            }
            if (x == 'S'){
                sx = i;
                sy = j;
            }
            else if (x == 'E'){
                ex = i;
                ey = j;
            }
        }
    }
    
    ll dist_start[n][n], dist_end[n][n];
    
    bfs(a, dist_start, sx, sy);
    bfs(a, dist_end, ex, ey);

    int count = 0;
    
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            for (int k = 0; k<n; k++){
                for (int l = 0; l<n; l++){
                    // For any two points visitable (i, j) and (k, l)
                    // such that (i, j) can be visited from (sx, sy) and (k, l) can be visited from (ex, ey)
                    if (dist_start[i][j] != n*n && dist_end[k][l] != n*n){
                        int d = abs(i-k) + abs(j-l);

                        // Since we can now cheat for at most 20 cells, we can cater points which are at most 20 units apart.
                        if (d <= 20){
                            // We first travel to (i, j) from (sx, sy) then travel the d dist to (k, l)
                            // Then we get the dist of (k, l) --> (ex, ey) through dist_end[k][l]
                            ll dist_through_cheating = (dist_start[i][j] + d + dist_end[k][l]);
                            count += (dist_start[ex][ey] - dist_through_cheating >= 100);
                        }
                    }
                }
            }
        }
    }

    cout << count << endl;

    return 0;
}
