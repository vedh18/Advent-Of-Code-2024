/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 6, Part 2                        #                       
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

    // Storing the value of the starting cell in a different variable
    int sxx = sx, syy = sy;

    vector<pair<int,int>> v = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}}; // Stores the different possible values
                                                                  // of dx and dy, this gives the direction the guard is currently moving
    
    int i = 0; // v[i % 4] gives dx and dy, we increment the value of i everytime we change direction.
    
    int dx = v[i%4].f;
    int dy = v[i%4].s;

    vis[sx][sy] = 1; // The starting position is visited
    
    // The next cell the guard moves into
    sx += dx;
    sy += dy;
    
    int ans = 0;

    // Brute force: Placing a obstacle in every possible cell and checking if a loop is formed by the guard's path
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            // Placing the obstacle at (i, j)
            if (a[i][j] == '.'){
                a[i][j] = '#';
                
                // Counter variable to track a cycle.
                int t = 0;
                
                // Resetting the variables
                int i1 = 0;
                dx = -1, dy = 0;
                sx = sxx;
                sy = syy;

                while (1){
                    while (sx >= 0 && sx <= n-1 && sy>=0 && sy<=n-1 && a[sx][sy] == '.'){
                        t++;
                        sx += dx;
                        sy += dy;
                    }
                    // If counter exceeds the longest posible path by a guard without a cycle, then break. (cycle found)
                    if (t >= n*n){
                        break;
                    }
                    if (a[sx][sy] == '#'){
                        // Going one step behind the obstacle
                        sx -= dx;
                        sy -= dy;
                        
                        i1++; // Chnaging the direction in which we move.
                        
                        // updating dx and dy
                        dx = v[i1%4].f;
                        dy = v[i1%4].s;
                        
                        // The next cell the guard moves into
                        sx += dx;
                        sy += dy;
                    }
                    else{
                        break;
                    }
                }
                // If cycle increment ans
                if (t >= n * n){
                    ans++;
                }
                // Resetting the cell for future.
                a[i][j] = '.';
            }
        }
    }
    
    cout << ans << endl;

    return 0;
}
