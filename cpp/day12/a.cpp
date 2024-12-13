/*
##################################################################
#                                                                #                       
#     Advent of Code 2024 - Day 12, Part 1                       #                       
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

#define n 140

// Function to calculate valid neighbours
int nnn(char mat[][n], int i, int j, char curr)
{
    int count = 0;
    if (i > 0 && mat[i - 1][j] == curr)
        count++;
    if (j > 0 && mat[i][j - 1] == curr)
        count++;
    if (i < n-1 && mat[i + 1][j] == curr)
        count++;
    if (j < n-1 && mat[i][j + 1] == curr)
        count++;
 
    return count;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); 
    
    char az[n][n]; // To store the square input
    int vis[n][n]; // To mark each cell visited or not

    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            cin >> az[i][j];
            vis[i][j] = -1; // Initializing as -1
        }
    }
    ll ans = 0;

    // Simple bfs called on every non visited cell
    for (int i = 0; i<n; i++){
        for (int j = 0; j<n; j++){
            if (vis[i][j] == -1){
                char curr = az[i][j];
                queue<pair<int, int>> q;
                q.push({i, j});
                vis[i][j] = 1;
                int c = 1; // To store the area
                int p = 4 - nnn(az, i, j, curr); // Perimeter
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
                                c++;
                                p += 4 - nnn(az, nx, ny, curr);
                                vis[nx][ny] = 1;
                                q.push({nx, ny});
                            }
                        }
                    }
                }
                ans += c * p;
            }
        }
    }

    cout << ans << endl;

    return 0;
}
