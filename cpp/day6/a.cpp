/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 6, Part 1                        #                       
#     Problem Link: https://adventofcode.com/2024/day/6          #                       
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
    
    int n = 130; // The input was given to be a square grid of n x n

    char a[n][n];
    int vis[n][n]; // To store if a particular cell with coordinates (i, j) is visited by the guard or not
    
    int sx = -1, sy = -1; // sx and sy to store the current (starting) position of the guard.
    
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> a[i][j];
            vis[i][j] = 0;
            if (a[i][j] == '^'){
                sx = i;
                sy = j;
            }
        }
    }
    
    // For the rest of the path, the starting cell is considered as an empty cell with no obstacles.
    a[sx][sy] = '.';
    
    vector<pair<int,int>> v = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Stores the different possible values
                                                                  // of dx and dy, this gives the direction the guard is currently moving
    
    int i = 0; // v[i % 4] gives dx and dy, we increment the value of i everytime we change direction.
    
    int dx = v[i%4].f;
    int dy = v[i%4].s;

    vis[sx][sy] = 1; // The starting position is visited
    
    // The next cell the guard moves into
    sx += dx;
    sy += dy;

    while (1){
        while (sx >= 0 && sx <= n-1 && sy>=0 && sy<=n-1 && a[sx][sy] == '.'){
            vis[sx][sy] = 1;
            sx += dx;
            sy += dy;
        }
        // If the guard's path was hindered by an obstacle.
        if (a[sx][sy] == '#'){
            sx -= dx;
            sy -= dy;
            
            i++; // Chnaging the direction in which we move.
            
            // updating dx and dy
            dx = v[i%4].f;
            dy = v[i%4].s;
            
            // The next cell the guard moves into
            sx += dx;
            sy += dy;
        }

        // If the guard exited the map
        else{
            break;
        }
    }
  
    // Counting the number of cells visited.
    int ans = 0;
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (vis[i][j] == 1) ans++;
        }
    }
   
    cout << ans << endl;
    
    return 0;
}
