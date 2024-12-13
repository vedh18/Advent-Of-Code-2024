/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 12, Part 2                       #                       
#     Problem Link: https://adventofcode.com/2024/day/12         #                       
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
    
    int n = 140; // Input was of dimentions 140 x 140
    
    char az[n][n]; // To store the square input
    int vis[n][n]; // To mark each cell visited or not

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> az[i][j];
            vis[i][j] = -1; // Initializing as -1
        }
    }
    
    ll ans = 0;

    int id = 1; // This time instead of marking 1/-1, we mark with an unique id corresponding 
                // to that connected component/region

    // Simple bfs called on every non visited cell
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (vis[i][j] == -1){
                char curr = az[i][j];
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = id;
                while (!q.empty()){
                    int x = q.front().f;
                    int y = q.front().s;
                    q.pop();
                    vector<pair<int, int>> diff = {{-1, 0}, {1, 0}, {0,1}, {0, -1}};
                    for (auto a: diff){
                        int nx = x + a.f;
                        int ny = y + a.s;
                        if (nx <= n-1 && nx >=0 && ny <= n-1 && ny >= 0){
                            // If unvisited and same as its parent
                            if (vis[nx][ny] == -1 && az[nx][ny] == curr){
                                vis[nx][ny] = id;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                id++;
            }
        }
    }
    for (int i = 1; i < id; i++) {
        int p = 0; // To count the perimeter contribution for the shape
        int a = 0;  // To count the total area (number of cells) of the shape

        // Arrays to track horizontal and vertical boundary transitions
        int hc[n][n + 1];
        int vc[n + 1][n];

        // Initialize
        for (int r = 0; r < n; r++) {
            for (int c = 0; c <= n; c++) {
                hc[r][c] = 0;
            }
        }
        for (int r = 0; r <= n; r++) {
            for (int c = 0; c < n; c++) {
                vc[r][c] = 0;
            }
        }

        // Process each row to compute area and horizontal boundary contributions
        for (int r = 0; r < n; r++) {
            int inShape = 0; // Flag to track whether we are inside the shape
            for (int c = 0; c < n; c++) {
                if (vis[r][c] == i) { // Current cell belongs to the shape
                    a++; // Increment area for each cell in the shape

                    if (!inShape) { // Transition from outside to inside the shape
                        inShape = 1;
                        hc[r][c] = 1; // Mark transition as entering the shape

                        // If no matching transition in the row above, this is a new side
                        if (r == 0 || hc[r - 1][c] != 1) {
                            p++;
                        }
                    }
                } else if (inShape) { // Transition from inside to outside the shape
                    inShape = 0;
                    hc[r][c] = 2; // Mark transition as exiting the shape

                    // If no matching transition in the row above, this is a new side
                    if (r == 0 || hc[r - 1][c] != 2) {
                        p++;
                    }
                }
            }

            // Handle edge case: Shape extends to the last column in the row
            if (inShape) {
                hc[r][n] = 2; // Mark transition as exiting at the last column
                if (r == 0 || hc[r - 1][n] != 2) {
                    p++;
                }
            }
        }

        // Similarily for vertical edges
        for (int c = 0; c < n; c++) {
            int inShape = 0; 
            for (int r = 0; r < n; r++) {
                if (vis[r][c] == i) { 
                    if (!inShape) { 
                        inShape = 1;
                        vc[r][c] = 1; 

                        if (c == 0 || vc[r][c - 1] != 1) {
                            p++;
                        }
                    }
                } else if (inShape) { 
                    inShape = 0;
                    vc[r][c] = 2; 

                    if (c == 0 || vc[r][c - 1] != 2) {
                        p++;
                    }
                }
            }

            if (inShape) {
                vc[n][c] = 2; 
                if (c == 0 || vc[n][c - 1] != 2) {
                    p++;
                }
            }
        }

        ans += p * a;
    }

    cout << ans << endl;

    return 0;
}
